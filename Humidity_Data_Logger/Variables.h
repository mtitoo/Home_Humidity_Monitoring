#include <Ethernet.h>

unsigned long Current_Time_RF_Sensor_Scan = millis();
unsigned long Previous_Time_RF_Sensor_Scan = 0;
int           RF_Scan_Interval = 1000;
unsigned long Current_Time_Any_Incoming_Web_Request = millis();
unsigned long Previosu_Time_Any_Incoming_Web_Request = 0;;
int           Web_Request_Interval = 1000;
unsigned long Current_Time_Post_To_DataServer = millis();
unsigned long Previous_Time_Post_To_DataServer = 0;;
int           Data_Server_Interval = 1000;
unsigned long Current_Time_Post_To_Local_UDP = millis();
unsigned long Previous_Time_Post_To_Local_UDP = 0;;
int           Local_UDP_Interval = 1000;
int           Num_Pipe = 4;



//byte Humidity_Sensor_RF_ID[][6] = {"East","West","South","North"};
//byte Base_RF_ID = "Peralman";

String  Sensor_Location [5] = {"East","West","South","North"}; 
String  Humidity_Sensor_Data [6]={"","","","","",""};

#define   East_ID                      0xF0F0F0F011
#define   West_ID                      0xF0F0F0F022
#define   South_ID                     0xF0F0F0F033
#define   North_ID                     0xF0F0F0F044
#define   Base_ID                      0xF0F0F0F0AA

#define CE_Pin 8
#define CS_Pin 7 
RF24 radio (CE_Pin,CS_Pin);

const uint64_t Read_Pipes[5] = { East_ID,West_ID,South_ID,North_ID }; 

EthernetClient Web_client;
EthernetServer server(80);
char serverName[] = "www.thingspeak.com";
int ThingSpeak_Counter = 0;
