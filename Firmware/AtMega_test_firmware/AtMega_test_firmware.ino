/*  ISO Power AtMega Test Firmware


    Basic program to test IO Functions and verify PCB is correct

    Imogen Wren
    08/06/2022

   Compile software for Arduino Nano 16MHz


   To Program Remove Wifi Header and use   

   
*/


#include <autoDelay.h>


#include "AtMega_pinMap.h"

#include "currentSense.h"









void ISOpowerBegin(int32_t baudrate = 115200) {
  Serial.begin(baudrate);
  Serial.print("ISO Power Test Firmware");

  //Outputs
  pinMode(BUS_12V_DISABLE, OUTPUT);
  pinMode(BUS_5V_DISABLE, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  for (int i = 0; i < 5; i++) {
    pinMode(outputChannels[i], OUTPUT);
  }
  //Inputs
  //  pinMode(BUS_5V_MONITOR, INPUT);    //Analog I/P do not need setting up as input
  //  pinMode(BUS_12V_MONITOR, INPUT);
}



void changeChannelState(int16_t channelNumber, bool state) {
  digitalWrite(outputChannels[channelNumber], !state);
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
  int loops = 6;
  while (loops > 0) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(200);
    loops--;
  }
}



void sendByte(uint8_t someData) {
  Serial.println(someData);
}


void startListen() {
  char buffer[64];
  int intBuffer;
  if (Serial.available() > 0) {
    intBuffer = Serial.read();
    Serial.println(intBuffer);
  }
}



void setup() {
  ISOpowerBegin(115200);
  changeChannelState(0, HIGH);
  changeChannelState(1, HIGH);
  changeChannelState(2, HIGH);
  changeChannelState(3, HIGH);
  changeChannelState(4, HIGH);
  enable12vBus(false);
  enable5vBus(false);
  flashLED();

}




autoDelay txDelay;
#define TX_PERIOD 1

void loop() {
//  currentSenseLoop();
 //startListen();
  
 // if (rxVal != 0) {
 //   Serial.println(rxVal);
 // }

///  if (txDelay.secondsDelay(TX_PERIOD)) {
 // sendByte(7);
 // }

}
