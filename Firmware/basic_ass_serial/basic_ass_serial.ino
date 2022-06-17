

#define LED_PIN               7  

void setup() {
  Serial.begin(115200);
  flashLED();
}



int iterations;

void loop() {
  Serial.println(iterations);
  iterations++;
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
