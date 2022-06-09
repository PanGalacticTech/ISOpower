/*  currentSense.h

     Read analog input and convert to current as detected by ACS712 IC



*/


int16_t bus12v_sample;

int16_t bus5v_sample;

int16_t bus_12v_current;
int16_t but_5v_current;

//Constant Values for ACS712-30A (Can change for different models of board)
#define SENSITIVITY  66
#define V_OFFSET  2500

bool newSample;


autoDelay sampleDelay;

#define ADC_SAMPLE_DELAY 500


void sampleADCs() {
  if (sampleDelay.millisDelay(ADC_SAMPLE_DELAY)) {
    bus12v_sample = analogRead(CURRENT_SENSE_12V);
    bus5v_sample = analogRead(CURRENT_SENSE_5v);
    newSample = true;
  }
}


int16_t ADCtoVoltage(int16_t adcValue) {
  int16_t adcVoltage = (adcValue / 1023) * 5000;
  return adcVoltage;
}

int16_t voltageToCurrent(int16_t adcVoltage) {
  int16_t currentValue = ((adcVoltage - V_OFFSET) / SENSITIVITY);
  return currentValue;
}




void currentSenseLoop() {
  sampleADCs();
  if (newSample) {
    char buffer[42];
    bus_12v_current = ADCtoVoltage(bus_12v_sample);
    bus_12v_current = voltageToCurrent(bus_12v_current);
    bus_5v_current = ADCtoVoltage(bus_5v_sample);
    bus_5v_current = voltageToCurrent(bus_5v_current);
    sprintf(buffer, "12v Bus Current: %i,  5v BUs Current: %i", bus_12v_current, bus_5v_current);
    Serial.println(buffer);
  }


}
