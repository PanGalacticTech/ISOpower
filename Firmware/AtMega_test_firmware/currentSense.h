/*  currentSense.h

     Read analog input and convert to current as detected by ACS712 IC



*/


int16_t bus12v_sample;

int16_t bus5v_sample;



autoDelay sampleDelay;

#define ADC_SAMPLE_DELAY 500


void sampleADCs() {
  if (sampleDelay.millisDelay(ADC_SAMPLE_DELAY)) {
    bus12v_sample = analogRead(CURRENT_SENSE_12V);
    bus5v_sample = analogRead(CURRENT_SENSE_5v);
  }
}


void ADCtoVoltage(int16_t adcValue){
  
}
