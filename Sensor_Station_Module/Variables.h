#define   East_ID                      0xF0F0F0F011
#define   West_ID                      0xF0F0F0F022
#define   South_ID                     0xF0F0F0F033
#define   North_ID                     0xF0F0F0F044
#define   Base_ID                      0xF0F0F0F0AA
#include <dht.h>

dht DHT;
float humidity;
#define DHT11_PIN 3

#define CE_Pin 9
#define CS_Pin 10 
RF24 radio (CE_Pin,CS_Pin);

String  Sensor_Location [5] = {"East","West","South","North"}; 
const uint64_t Read_Pipes[5] = { East_ID,West_ID,South_ID,North_ID }; 

unsigned long Current_Time_Humidity_Sensor_Scan = millis();
unsigned long Previous_Time_Humidity_Sensor_Scan = 0;
int           Humidity_Scan_Interval = 5000;
int           Num_Pipe = 4;

String  Data_String,Status_String;
volatile int WatchDog_Counter;
