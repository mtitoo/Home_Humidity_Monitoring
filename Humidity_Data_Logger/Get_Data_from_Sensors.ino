

void Get_Data_From_Sensor(){
      
       int sender_id;
       uint8_t pipe_num;
       char Temp_Sensor_Data[32];
       for (int i=0;i < sizeof(Read_Pipes);i++){
      
            if( radio.available(&pipe_num)){
             
             #ifdef DEBUG
               printf("Current Pipe:%d",pipe_num);
             #endif
              while (radio.available(&pipe_num)) { // While there is data 
                radio.read( &Temp_Sensor_Data, sizeof(unsigned long) ); // Get the payload
                Humidity_Sensor_Data[i]= Temp_Sensor_Data;
                #ifdef DEBUG
                 printf("Current Data:%s",Temp_Sensor_Data);
                #endif
               }
                     
         }//end of if
       }//end of for loop
      

}//End of Get_Data
