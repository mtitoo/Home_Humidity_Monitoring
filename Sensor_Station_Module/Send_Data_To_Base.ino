
  void Send_Data_To_Base(){
        char TemBuf [Data_String.length()+1];
        Data_String.toCharArray (TemBuf,Data_String.length()+1);
        //radio.stopListening();
        Serial.println(TemBuf);
        radio.write( &TemBuf, Data_String.length()+1);
        //radio.startListening(); 
        delay(1000);

 }
 
