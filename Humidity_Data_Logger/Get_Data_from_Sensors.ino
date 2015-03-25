

void Get_Data_From_Sensor(){
      
       int sender_id;
       uint8_t pipe_num;
      
      for (int i=0;i < sizeof(pipes);i++){
      
            if( radio.available(&pipe_num)){
              while (radio.available(&pipe_num)) { // While there is data ready
                radio.read( Humidity_Sensor_Data[i], sizeof(unsigned long) ); // Get the payload
            }  
      
      }
      

}//End of Get_Data
