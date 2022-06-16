int inByte = 0;
char test_string[10]= "UART_TEST";
int target = 7;

void ISOwifiBegin(int32_t baudrate = 115200) {
  Serial.begin(baudrate);
  Serial.print("ISO Wifi Test Firmware");
} 
  
void setup() {
  // start serial port at 9600 bps:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  pinMode(2, INPUT);   // digital sensor is on digital pin 2
  establishContact();  // send a byte to establish contact until receiver responds
}




void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
  }
}
void establishContact() {
  if (inByte == target) {
    Serial.print('Test Passed');   // send a capital A
    delay(300);
  } 
}
