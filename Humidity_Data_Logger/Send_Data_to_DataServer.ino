

void Send_Data_to_DataServer(){
  
  if (Web_client.connect(serverName, 80)) {
    
    #ifdef DEBUG
      Serial.println("connected");
      String Get_Request_String = String ("http://api.thingspeak.com/update?key=HK6OZW4YT4V6BU0K&field1="+ThingSpeak_Counter++);
      ThingSpeak_Counter++;
    #endif
      // Make a HTTP request:
      Web_client.println(Get_Request_String);
      Web_client.println();
  }
  else {
    // kf you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  

}//end of Send Data to Server
