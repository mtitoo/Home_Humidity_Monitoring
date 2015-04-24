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
#define       Num_Pipe  4

float         humidity[Num_Pipe]={0,0,0,0};
float         temperature[Num_Pipe]={0,0,0,0};
boolean       Valid_Sensor_Data;
float         Sensor_Station_Source_Voltage[Num_Pipe]={0,0,0,0};


//byte Humidity_Sensor_RF_ID[][6] = {"East","West","South","North"};
//byte Base_RF_ID = "Peralman";

String  Sensor_Location [5] = {"Crawl Space","Inside Home","South","North"}; 
String  Humidity_Sensor_Data [6]={"","","","","",""};

#define   Crawl_Space                  0xF0F0F0F011LL
#define   Garden                       0xF0F0F0F022LL
#define   South_ID                     0xF0F0F0F033LL
#define   North_ID                     0xF0F0F0F044LL
#define   Base_ID                      0xF0F0F0F0AALL

#define CE_Pin 8
#define CS_Pin 7 
RF24 radio (CE_Pin,CS_Pin);

const uint64_t Read_Pipes[5] = { Crawl_Space,Garden,South_ID,North_ID }; 

EthernetClient Web_client;
EthernetServer server(80);
char serverName[] = "www.thingspeak.com";
byte Server_IP[] = {184, 106, 153, 149 };
byte Local_IP[] = {192, 168, 1, 149 };
#define Server_IP_WIFI "184.106.153.149"

String GET = "GET /update?key=8VFHE5FEEK9VLPRJ&";
#define SSID "Science"
#define PASS "bangl"


int ThingSpeak_Counter = 0;
int WebServer_Counter = 0;


#define BUFFER_SIZE 512
#define bufferMax 512

#define SSID  "Science"      // change this to match your WiFi SSID
#define PASS  "bangl"  // change this to match your WiFi password
#define PORT  "80"           // using port 8080 by default

char buffer[BUFFER_SIZE];
#define esp Serial1   // use Serial1 to talk to esp8266
#define esp8266 Serial1 
char OKrn[] = "OK\r\n";
int bufferSize;

