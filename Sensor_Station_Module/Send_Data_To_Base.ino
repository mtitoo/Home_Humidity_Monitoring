
  void Send_Data_To_Base(){
    
        radio.stopListening();
        radio.write( &Data_String, sizeof(Data_String) );
        radio.startListening(); 

 };
