/*
 * Test to check the UART Communication from ATMega328PB to ESP32
 * 
 * NOTES:
 * Serial2.write(val) will write the numeric value of 'val' as a numeric value.
 * 
 * If 'val' needs to be a String, then use Serial2.println(val). This writes the String
 * in 'val' as an ASCII value, character by character.
 * 
 * Serial2.read() will read the value as it is. Either as a numerical value or the ASCII value.
 */

#define RXD2 16
#define TXD2 17

void setup() {
  // put your setup code here, to run once:
  // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
//  Serial.println("Serial Txd is on pin: " + String(TXD2));
//  Serial.println("Serial Rxd is on pin: " + String(RXD2));
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial2.available()) {
    if (Serial2.read() == 22)
    {
      Serial.println("Message Confirmed");
      Serial2.write(12);
    }
  }
}
