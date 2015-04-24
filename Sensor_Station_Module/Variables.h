#define   Crawl_Space                  0xF0F0F0F011LL
#define   Garden                       0xF0F0F0F022LL
#define   South_ID                     0xF0F0F0F033LL
#define   North_ID                     0xF0F0F0F044LL
#define   Base_ID                      0xF0F0F0F0AALL
#include <dht.h>

dht DHT;
float humidity;
#define DHT11_PIN 3

#define CE_Pin 9
#define CS_Pin 10 
RF24 radio (CE_Pin,CS_Pin);

String  Sensor_Location [5] = {"Crawl_Space","Garden","South","North"}; 
const uint64_t Read_Pipes[5] = { Crawl_Space,Garden,South_ID,North_ID }; 

unsigned long Current_Time_Humidity_Sensor_Scan = millis();
unsigned long Previous_Time_Humidity_Sensor_Scan = 0;
int           Humidity_Scan_Interval = 5000;
int           Num_Pipe = 4;

String  Data_String,Status_String;
volatile int WatchDog_Counter;
