
unsigned long Current_Time_RF_Sensor_Scan;
unsigned long Previous_Time_RF_Sensor_Scan;
unsigned long Current_Time_Any_Incoming_Web_Request;
unsigned long Previosu_Time_Any_Incoming_Web_Request;
unsigned long Current_Time_Post_To_DataServer;
unsigned long Previous_Time_Post_To_DataServer;
unsigned long Current_Time_Post_To_Local_UDP;
unsigned long Previous_Time_Post_To_Local_UDP;



byte Humidity_Sensor_RF_ID[][6] = {"East","West","South","North"};
byte Base_RF_ID = "Peralman";

unsigned long  Humidity_Sensor_Data [6]={0,0,0,0,0,0};

