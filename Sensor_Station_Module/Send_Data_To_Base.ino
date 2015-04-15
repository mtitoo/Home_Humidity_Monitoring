
  void Send_Data_To_Base(){
    
        radio.stopListening();
        unsigned long time = micros(); 
        //radio.write( &Data_String, sizeof(Data_String) );
        radio.write( &humidity, sizeof(float) );
        
        Serial.println(time);
        radio.startListening(); 

 };
