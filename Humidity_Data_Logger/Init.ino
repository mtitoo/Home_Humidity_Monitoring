#define DEBUG
#define   East_ID                     = 0xF0F0F0F0011,
#define   West_ID                     = 0xF0F0F0F022,
#define   South_ID                    = 0xF0F0F0F033,
#define   North_ID                    = 0xF0F0F0F044
#define   Base_ID                     = 0xF0F0F0F0AA

#include <SPI.h>
#include "RF24.h"
const uint64_t Read_Pipes[5] = { East_ID,West_ID,South_ID,North_ID }; 

Humidity_Sensor_RF_ID Sensor_ID
Base_Station_RF_ID    Base_ID
void Init (){

  Serial.begin(57600);
  #ifdef DEBUG
    Serial.println(F("Program Started."));
  #endif

  radio.begin();
  
  radio.openWritingPipe(Base);
 //set read pipes upto 6
  for (int i=0;i < sizeof(pipes);i++){
    radio.openReadingPipe(i+1,Read_Pipes[i]);
  }//end of for
  
  radio.setPALevel(RF24_PA_LOW); //Right now Low Power Mode. Will need to change later
  radio.setAutoAck(1); // Ensure autoACK is enabled
  radio.enableAckPayload(); // Allow optional ack payloads
  radio.setRetries(0,15); // Smallest time between retries, max no. of retries
  radio.setPayloadSize(1); // Here we are sending 1-byte payloads to test the call-response speed
  radio.startListening(); // Start listening
``
```#ifdef DEBUG  
  `radio.printDetails(); // Dump the configuration of the rf unit for debugging
``#endif


}//end of Init
