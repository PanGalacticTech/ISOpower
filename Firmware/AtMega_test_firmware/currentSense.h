/*  currentSense.h

     Read analog input and convert to current as detected by ACS712 IC



*/


int16_t bus12v_sample;

int16_t bus5v_sample;

int16_t adcVoltage;

int16_t currentValue;

//Constant Values for ACS712-30A (Can change for different models of board)
int sensitivity = 66;
int offsetVoltage = 2500;



autoDelay sampleDelay;

#define ADC_SAMPLE_DELAY 500


void sampleADCs() {
  if (sampleDelay.millisDelay(ADC_SAMPLE_DELAY)) {
    bus12v_sample = analogRead(CURRENT_SENSE_12V);
    bus5v_sample = analogRead(CURRENT_SENSE_5v);
  }
}


void ADCtoVoltage(int16_t adcValue){
  adcVoltage = (adcValue / 1023) * 5000;
}

void voltageToCurrent(int16_t adcVoltage){
  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);
}
