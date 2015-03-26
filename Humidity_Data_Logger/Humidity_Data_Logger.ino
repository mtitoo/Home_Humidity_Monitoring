#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"
#include "Variables.h"


#define DEBUG

void setup(){
  printf_begin();
  Init_Serial();
  Init_RF_COM ();

}//end of setup

void loop(){


}//end of loop
