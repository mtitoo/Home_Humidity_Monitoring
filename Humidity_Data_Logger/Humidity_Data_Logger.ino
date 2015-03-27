#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"
#include <Ethernet.h>
#include "Variables.h"


#define DEBUG
#define No_RF




void setup(){
   Current_Time_RF_Sensor_Scan = millis();
   Previous_Time_RF_Sensor_Scan = 0;
   RF_Scan_Interval = 3000;
   Current_Time_Any_Incoming_Web_Request = millis();
   Previosu_Time_Any_Incoming_Web_Request = 0;;
   Web_Request_Interval = 100;
   Current_Time_Post_To_DataServer = millis();
   Previous_Time_Post_To_DataServer = 0;;
   Data_Server_Interval = 1000;
   Current_Time_Post_To_Local_UDP = millis();
   Previous_Time_Post_To_Local_UDP = 0;;
   Local_UDP_Interval = 1000;
  
  
   Init_Serial();
   Init_Ehternet_Module();
   printf_begin();
   Init_RF_COM ();
   
}//end of setup

void loop(){
  Current_Time_RF_Sensor_Scan = millis();
  Current_Time_Any_Incoming_Web_Request = millis();
  
  
  //Scanning RF Data
  if(Current_Time_RF_Sensor_Scan-Previous_Time_RF_Sensor_Scan > RF_Scan_Interval){
     Get_Data_from_Sensors();
     Send_Data_to_DataServer();
     Previous_Time_RF_Sensor_Scan = Current_Time_RF_Sensor_Scan;
    
  }//end of Scanning RF Data
  
  if(Current_Time_Any_Incoming_Web_Request-Previosu_Time_Any_Incoming_Web_Request > Web_Request_Interval){
    Web_Service();
  }//end of Web Service
  
  
  




}//end of loop
