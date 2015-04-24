#include "nRF24L01.h"
#include "RF24.h"

void Get_Data_from_Sensors(){
       
            
       Valid_Sensor_Data = false;
       int sender_id;
       uint8_t pipe_num;
       uint8_t Current_Pipe;
       
       char Temp_Sensor_Data[32];
       unsigned long time;
       String Temp_Data_Str;
              
    
             
         
           while( radio.available(&pipe_num)){
             
             uint8_t len;
             Current_Pipe = pipe_num;
             Valid_Sensor_Data = true;
                     
                     #ifdef DEBUG
                       printf("Current Pipe:%d\n",pipe_num);
                     #endif
            
             
                 Serial.println(radio.available(&pipe_num));
                 len = radio.getDynamicPayloadSize();
                 radio.read( &Temp_Sensor_Data,len); // Get the payload
                 Serial.println(radio.available(&pipe_num));
                 Serial.println(String(Temp_Sensor_Data));
                 String Temp_String = String (Temp_Sensor_Data);
                 int First_Semi = Temp_String.indexOf(';');
                 int Second_Semi = Temp_String.indexOf(';',First_Semi+1);
                 
                 String humidity_str =  Temp_String.substring(0,First_Semi);
                 String temperature_str = Temp_String.substring(First_Semi+1,Second_Semi);
                 String Source_Voltage = Temp_String.substring(Second_Semi+1,len);
                 humidity[pipe_num-1] =  humidity_str.toFloat();
                 temperature[pipe_num-1] = temperature_str.toFloat();
                 Sensor_Station_Source_Voltage[pipe_num-1] = Source_Voltage.toFloat()*5/1024; 
          }//end of while
            
           
       
      

}//End of Get_Data



