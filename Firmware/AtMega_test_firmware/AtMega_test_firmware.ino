/*  ISO Power AtMega Test Firmware


     Basic program to test IO Functions and verify PCB is correct

     Imogen Wren
     08/06/2022

    Compile software for Arduino Nano 16MHz
*/


#include <autoDelay.h>


#include "AtMega_pinMap.h"

#include "currentSense.h"



void setup() {
ISOpowerBegin(115200);
}





void loop() {


}






void ISOpowerBegin(int32_t baudrate = 115200) {
  Serial.begin(baudrate);
  Serial.print("ISO Power Test Firmware");


  //Outputs
  pinMode(BUS_12V_DISABLE, OUTPUT);
  pinMode(BUS_5V_DISABLE, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  for (int i = 0, i < 5, i++) {
    pinMode(outputChannels[i], OUTPUT);
  }


  //Inputs
  pinMode(BUS_5V_MONITOR, INPUT);
  pinMode(BUS_12V_MONITOR, INPUT);

}
