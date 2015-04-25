

byte wait_for_esp_response(int timeout, char* term=OKrn) {
  unsigned long t=millis();
  bool found=false;
  int i=0;
  int len=strlen(term);
  // wait for at most timeout milliseconds
  // or if OK\r\n is found
  while(millis()<t+timeout) {
    if(esp.available()) {
      buffer[i++]=esp.read();
      if(i>=len) {
        if(strncmp(buffer+i-len, term, len)==0) {
          found=true;
          break;
        }
      }
    }
  }
  buffer[i]=0;
  Serial.print(buffer);
  return found;
}

void setupWiFi() {
  // try empty AT command
  esp.println("AT");
  wait_for_esp_response(1000);

  // set mode 1 (client)
  esp.println("AT+CWMODE=1");
  wait_for_esp_response(1000);  
    // reset WiFi module
  esp.print("AT+RST\r\n");
  wait_for_esp_response(1500);
  delay(3000);
 
  // join AP
  esp.print("AT+CWJAP=\"");
  esp.print(SSID);
  esp.print("\",\"");
  esp.print(PASS);
  esp.println("\"");
  // this may take a while, so wait for 5 seconds
  wait_for_esp_response(5000);
  
  esp.println("AT+CIFSR");
  wait_for_esp_response(1000); 
  
  esp.println("AT+CIPMUX=0");
  wait_for_esp_response(1000); 
  
  //esp.println("AT+CIPSERVER=1,PORT"); // turn on TCP service
  //wait_for_esp_response(1000);
 
 
 
 // esp.println("AT+CIPSTO=30");  
 // wait_for_esp_response(1000);

  // start server
  //esp.println("AT+CIPMUX=1");
 // wait_for_esp_response(1000);
  
 // esp.print("AT+CIPSERVER=1,"); // turn on TCP service
 // esp.println(PORT);
  //wait_for_esp_response(1000);
  
    
}

void PrintString(char* label, char* str)
{
  Serial.print(label);
  Serial.print("=");
  Serial.println(str);
}

void PrintNumber(char* label, int number)
{
  Serial.print(label);
  Serial.print("=");
  Serial.println(number, DEC);
}

void WaitForRequest() // Sets buffer[] and bufferSize
{
  bufferSize = 0;
 
  while (esp.available()) {
    
       char c = esp.read();
        if (c == '\n')
           break;
        else
        if (bufferSize < bufferMax)
          buffer[bufferSize++] = c;
        else
          break;
    
  }
  
  PrintNumber("bufferSize", bufferSize);
}

String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
    
    esp8266.print(command); // send the read character to the esp8266
    
    long int time = millis();
    
    while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {
        
        // The esp has data so display its output to the serial window 
        char c = esp8266.read(); // read the next character.
        response+=c;
      }  
    }
    
    if(debug)
    {
      Serial.print(response);
    }
    
    return response;
}

void rx_empty(void) 
{
    while(esp.available()) {
        esp.read();
    }
}


