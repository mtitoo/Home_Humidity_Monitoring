
unsigned long Current_Time_RF_Sensor_Scan;
unsigned long Previous_Time_RF_Sensor_Scan;
unsigned long Current_Time_Any_Incoming_Web_Request;
unsigned long Previosu_Time_Any_Incoming_Web_Request;
unsigned long Current_Time_Post_To_DataServer;
unsigned long Previous_Time_Post_To_DataServer;
unsigned long Current_Time_Post_To_Local_UDP;
unsigned long Previous_Time_Post_To_Local_UDP;



//byte Humidity_Sensor_RF_ID[][6] = {"East","West","South","North"};
//byte Base_RF_ID = "Peralman";

String  Humidity_Sensor_Data [6]={"","","","","",""};

#define   East_ID                      0xF0F0F0F011
#define   West_ID                      0xF0F0F0F022
#define   South_ID                     0xF0F0F0F033
#define   North_ID                     0xF0F0F0F044
#define   Base_ID                      0xF0F0F0F0AA

#define CE_Pin 7
#define CS_Pin 8
RF24 radio (CE_Pin,CS_Pin);

const uint64_t Read_Pipes[5] = { East_ID,West_ID,South_ID,North_ID }; 
