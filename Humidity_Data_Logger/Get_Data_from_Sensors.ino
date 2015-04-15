#include "nRF24L01.h"
#include "RF24.h"

void Get_Data_from_Sensors(){
       
            
       
       int sender_id;
       uint8_t pipe_num;
       char Temp_Sensor_Data[32];
       unsigned long time;
              
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
             uint8_t len;
              while (radio.available(&pipe_num)) { // While there is data 
                 len = radio.getDynamicPayloadSize();
                radio.read( &Temp_Sensor_Data,len); // Get the payload
                //radio.read( &time, sizeof(unsigned long)); // Get the payload
              
              }//end of while
              Serial.println(len);
               // Humidity_Sensor_Data[i]= Temp_Sensor_Data;
                #ifdef DEBUG
                 //printf("Current Data:%s\n",Temp_Sensor_Data);
                Serial.println(*((float*)Temp_Sensor_Data));
                humidity = *((float*)Temp_Sensor_Data);
                #endif
            
                     
         }//end of if
            
            #endif
       }//end of for loop
      

}//End of Get_Data
