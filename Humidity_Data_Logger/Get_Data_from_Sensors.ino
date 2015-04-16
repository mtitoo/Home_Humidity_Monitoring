#include "nRF24L01.h"
#include "RF24.h"

void Get_Data_from_Sensors(){
       
            
       Valid_Sensor_Data = false;
       int sender_id;
       uint8_t pipe_num;
       char Temp_Sensor_Data[32];
       unsigned long time;
      String Temp_Data_Str;
              
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
             
              Valid_Sensor_Data = true;
             #ifdef DEBUG
               printf("Current Pipe:%d\n",pipe_num);
             #endif
             uint8_t len;
              while (radio.available(&pipe_num)) { // While there is data 
                 len = radio.getDynamicPayloadSize();
                 radio.read( &Temp_Sensor_Data,len); // Get the payload
                
                //radio.read( &time, sizeof(unsigned long)); // Get the payload
              
              }//end of while

               // Humidity_Sensor_Data[i]= Temp_Sensor_Data;
                
               String Temp_String = String (Temp_Sensor_Data);
               int First_Semi = Temp_String.indexOf(';');
               int Second_Semi = Temp_String.indexOf(';',First_Semi+1);
               
               String humidity_str =  Temp_String.substring(0,First_Semi);
               String temperature_str = Temp_String.substring(First_Semi+1,Second_Semi);
               String Source_Voltage = Temp_String.substring(Second_Semi+1,len);
               humidity[i] =  humidity_str.toFloat();
               temperature[i] = temperature_str.toFloat();
               Sensor_Station_Source_Voltage[i] = Source_Voltage.toFloat()*5/1024; 
               //Serial.println("Voltage");
               
               //Serial.println(Source_Voltage);
               //Serial.println(Sensor_Station_Source_Voltage);
          
                
                #ifdef DEBUG
                 //printf("Current Data:%s\n",Temp_Sensor_Data);
                Serial.println(String(Temp_Sensor_Data));
                //Serial.println(*((float*)Temp_Sensor_Data));
                //humidity = *((float*)Temp_Sensor_Data);
         
                #endif
            
                     
         }//end of if
            
            #endif
       }//end of for loop
      

}//End of Get_Data
