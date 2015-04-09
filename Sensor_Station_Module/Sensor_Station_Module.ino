#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"
#include <Ethernet.h>
#include "Variables.h"
#include <dht.h>

#define DEBUG
#define   Station_ID                   East_ID


  void setup(){
      Current_Time_Humidity_Sensor_Scan = millis();
      Previous_Time_Humidity_Sensor_Scan = 0;
      Humidity_Scan_Interval = 5000;
      
            
      Init_Serial();
      printf_begin();
      Init_RF_COM ();

  }//end of setup
  
  
  void loop(){
      Current_Time_Humidity_Sensor_Scan = millis();
      if(Current_Time_Humidity_Sensor_Scan-Previous_Time_Humidity_Sensor_Scan > Humidity_Scan_Interval){
         
         Read_Humidity_Temp();
         Send_Data_To_Base();
         
         Previous_Time_Humidity_Sensor_Scan = Current_Time_Humidity_Sensor_Scan;
    
  }//end of Scanning RF Data
    
    
  }//end of loop
