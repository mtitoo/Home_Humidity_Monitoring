

void Send_Data_to_DataServer(){
  
  if (Web_client.connect(Server_IP, 80)) {
     String Get_Request_String = String ("field1="+String(humidity[0])+"&field2="+String(temperature[0])+"&field3="+String(Sensor_Station_Source_Voltage[0])
     +"&field4="+String(humidity[1])+"&field5="+String(temperature[1])+"&field6="+String(Sensor_Station_Source_Voltage[1])
     );
    #ifdef DEBUG
      Serial.println("connected");
      //String Get_Request_String = String ("field1="+String(ThingSpeak_Counter));
     
      
      Serial.println(Get_Request_String);
      ThingSpeak_Counter++;
    #endif
      // Make a HTTP request:
      
    //Web_client.print("GET /update?key=HK6OZW4YT4V6BU0K&field1=");
    Web_client.println("POST /update HTTP/1.1");
    Web_client.println("Host: api.thingspeak.com");
    Web_client.println("Connection: close");
    //Web_client.println("X-THINGSPEAKAPIKEY:HK6OZW4YT4V6BU0K");
    Web_client.println("X-THINGSPEAKAPIKEY:8VFHE5FEEK9VLPRJ");
    Web_client.println("Content-Type: application/x-www-form-urlencoded");
    Web_client.print("Content-Length:");
    Web_client.println(Get_Request_String.length());
    //Web_client.println(sizeof(float));
    
    Web_client.println();
    Web_client.println(Get_Request_String);
    
    delay(300);
 
      Web_client.stop();
      Valid_Sensor_Data = false;
  }
  else {
    // kf you didn't get a connection to the server:
    Web_client.stop();
    Serial.println("connection failed");
  }
  

}//end of Send Data to Server
