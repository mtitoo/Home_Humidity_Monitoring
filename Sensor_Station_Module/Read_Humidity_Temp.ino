
   void Read_Humidity_Temp(){
            
              // READ DATA
          Serial.print("DHT11, \t");
          int chk = DHT.read11(DHT11_PIN);
          switch (chk)
          {
            case DHTLIB_OK:  
                        Serial.print("OK,\t"); 
                        break;
            case DHTLIB_ERROR_CHECKSUM: 
                        Serial.print("Checksum error,\t"); 
                        break;
            case DHTLIB_ERROR_TIMEOUT: 
                        Serial.print("Time out error,\t"); 
                        break;
            case DHTLIB_ERROR_CONNECT:
                Serial.print("Connect error,\t");
                break;
            case DHTLIB_ERROR_ACK_L:
                Serial.print("Ack Low error,\t");
                break;
            case DHTLIB_ERROR_ACK_H:
                Serial.print("Ack High error,\t");
                break;
            default: 
                        Serial.print("Unknown error,\t"); 
                        break;
          }
          // DISPLAY DATA
          //Serial.print(DHT.humidity, 1);
          //Serial.print(",\t");
          //Serial.println(DHT.temperature, 1);
          //Data_String = "Humidity: "+ String(DHT.humidity)+"\t"+"Temperature:"+String(((1.8*DHT.temperature)+32))+"\t"+"Status:"+String(chk);
          DHT.humidity;
          DHT.temperature;
          delay(4000);
          Data_String = String(DHT.humidity)+";"+String(((1.8*DHT.temperature)+32))+";"+String(analogRead(0));
          humidity = DHT.humidity;
          Serial.println(Data_String);
          Serial.print("\n");
          
          //delay(2000);
  
  
  
  };//end of Read Module
