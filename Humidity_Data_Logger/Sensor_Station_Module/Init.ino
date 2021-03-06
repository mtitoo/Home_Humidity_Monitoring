
void Init_Serial (){

  Serial.begin(57600);
  #ifdef DEBUG
    Serial.println(F("Sensor Station Started."));
  #endif
}//end Serial_Init

void Init_RF_COM (){
  
  
  radio.begin();
 
  radio.openWritingPipe(Station_ID); //Set Base ID
  
  //set read pipe to base 
    radio.openReadingPipe(1,Base_ID);
  
  radio.setPALevel(RF24_PA_LOW); //Right now Low Power Mode. Will need to change later
  radio.setAutoAck(1); // Ensure autoACK is enabled
  radio.enableAckPayload(); // Allow optional ack payloads
  radio.setRetries(0,15); // Smallest time between retries, max no. of retries
  //radio.setPayloadSize(32); // We do not need that. By default sends 32 bytes. 
 
  radio.startListening(); // Start listening
  
  #ifdef DEBUG  
    radio.printDetails(); // Dump the configuration of the rf unit for debugging
  #endif
  

}//end of RF_COM_Init
