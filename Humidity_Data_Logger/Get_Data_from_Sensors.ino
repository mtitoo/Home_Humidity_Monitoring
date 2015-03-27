

void Get_Data_from_Sensors(){
       
            
       
       int sender_id;
       uint8_t pipe_num;
       char Temp_Sensor_Data[32];
              
       for (int i=0;i < Num_Pipe;i++){
             
          #ifdef No_RF
                int sensorValue = analogRead(A0);
                String str = String(sensorValue);
                str.toCharArray(Temp_Sensor_Data,32);  
                Humidity_Sensor_Data[i]= String(Temp_Sensor_Data);
                #ifdef DEBUG         
                //printf("Current Data:%s\n",Temp_Sensor_Data);
                #endif

          
          #else 
          
            if( radio.available(&pipe_num)){
             
             #ifdef DEBUG
               printf("Current Pipe:%d\n",pipe_num);
             #endif
              while (radio.available(&pipe_num)) { // While there is data 
                radio.read( &Temp_Sensor_Data, sizeof(unsigned long) ); // Get the payload
              
                
                Humidity_Sensor_Data[i]= Temp_Sensor_Data;
                #ifdef DEBUG
                printf("Current Data:%s\n",Temp_Sensor_Data);
                #endif
            }//end of while
                     
         }//end of if
            
            #endif
       }//end of for loop
      

}//End of Get_Data
