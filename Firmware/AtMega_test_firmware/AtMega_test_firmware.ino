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
  changeChannelState(0, HIGH);
  enable12vBus(true);
  enable5vBus(true;
  flashLED();

}





void loop() {
  currentSenseLoop();
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
  //  pinMode(BUS_5V_MONITOR, INPUT);    //Analog I/P do not need setting up as input
  //  pinMode(BUS_12V_MONITOR, INPUT);
}



void changeChannelState(int16_t channelNumber, bool state) {
  digitalWrite(outputChannels[channelNumber], state);
}

void enable12vBus(bool enable) {
  if (enable) {
    digitalWrite(BUS_12V_DISABLE, LOW);
  } else {
    digitalWrite(BUS_12V_DISABLE, HIGH);
  }
}


void enable5vBus(bool enable) {
  if (enable) {
    digitalWrite(BUS_5V_DISABLE, LOW);
  } else {
    digitalWrite(BUS_5V_DISABLE, HIGH);
  }
}


void flashLED() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(2000);
}
