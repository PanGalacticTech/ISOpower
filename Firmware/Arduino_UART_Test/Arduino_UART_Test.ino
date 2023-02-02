/*
 * Test to check the UART Communication from ATMega328PB to ESP32
 * 
 * NOTES:
 * SoftwareSerial.write(val) will write the numeric value of 'val' as a numeric value.
 * 
 * If 'val' needs to be a String, then use SoftwareSerial.println(val). This writes the String
 * in 'val' as an ASCII value, character by character.
 * 
 * SoftwareSerial.read() will read the value as it is. Either as a numerical value or the ASCII value.
 * 
 * There is a lot of noise while receiving on the ATMega328PB.
 */

#include <SoftwareSerial.h>
#define TX1 8
#define RX1 9

SoftwareSerial mySerial(RX1, TX1);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  mySerial.write(22);

  if (mySerial.available())
  {
    Serial.println(mySerial.read());
    if (mySerial.read() == 12)
      Serial.println("Message Confirmed");
  }
}
