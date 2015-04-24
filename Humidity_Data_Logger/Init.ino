
void Init_Serial (){

  Serial.begin(115200);
  #ifdef DEBUG
    Serial.println(F("Program Started."));
  #endif
}//end Serial_Init

void Init_RF_COM (){
  
  
  radio.begin();
 
  radio.openWritingPipe(Base_ID); //Set Base ID
  
  //set read pipes upto 6
  for (int i=0;i < Num_Pipe;i++){
    radio.openReadingPipe(i+1,Read_Pipes[i]);
  }//end of for
  
  radio.setPALevel(RF24_PA_HIGH); //Right now Low Power Mode. Will need to change later
  radio.setAutoAck(1); // Ensure autoACK is enabled
  radio.enableAckPayload(); // Allow optional ack payloads
  radio.setRetries(15,15); // Smallest time between retries, max no. of retries
  radio.setPayloadSize(32); // We do not need that. By default sends 32 bytes. 
 
  radio.startListening(); // Start listening
  
  #ifdef DEBUG  
    radio.printDetails(); // Dump the configuration of the rf unit for debugging
  #endif
  

}//end of RF_COM_Init

void Init_Web_Service (){
 
}//end of Web_Service_Init

void Init_Ehternet_Module(){
    byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
    if (Ethernet.begin(mac) == 0) {
        //Ethernet.begin(mac, Local_IP);
            Serial.println("Failed both to configure Ethernet using DHCP & Static");
        
   }
    Serial.print("IP = ");
   Serial.println(Ethernet.localIP());

}//end ethernet module init


void Init_ESP8266(){
  esp.begin(9600);
  setupWiFi();
   Serial.print("device ip addr:");
   esp.println("AT+CIFSR");
   wait_for_esp_response(1000);
   
}//End of Init ESP
