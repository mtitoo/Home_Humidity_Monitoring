
void Send_Data_to_DataServer_Wifi(){
  
  Valid_Sensor_Data = false;
  
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += Server_IP_WIFI;
  cmd += "\",80";
  
  esp.println(cmd);
  delay(2000);
  if(esp.find("Error")){\
    esp.println("AT+CIPCLOSE");
    wait_for_esp_response(1000);
    return;
  }

   cmd = GET;
   cmd += String("field1="+String(humidity[0])+"&field2="+String(temperature[0])+"&field3="+String(Sensor_Station_Source_Voltage[0])+"\r\n");
   esp.print("AT+CIPSEND=");
   esp.println(cmd.length());
    delay(1000);
    if(esp.find(">")){
    Serial.println("Found >");
    esp.println(cmd);
    delay(2000);
  }else{
    rx_empty();
    esp.println("AT+CIPCLOSE");
    wait_for_esp_response(1000);
    Serial.println("Not Found >");
    Init_ESP8266();
  }
  rx_empty();
  
   
  
  }//end of Send Data to Server
