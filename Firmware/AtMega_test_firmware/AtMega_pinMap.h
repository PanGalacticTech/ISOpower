/*  AtMega_pinMap.h

     Translates schematic pin numbers into Arduino digital pin numbers
     and register numbers for pins not available on arduino nano board




*/

#ifndef AtMega_pinMap_h
#define AtMega_pinMap_h



  
#define BUS_12V_DISABLE        D2       // HIGH to Disable
#define BUS_5V_DISABLE         D3       // HIGH to Disable
#define CH_C                   D4

#define BUS_5V_MONITOR         D5       //BUS_5V_MONITOR
#define BUS_12V_MONITOR        D6       // BUS_12V_MONITOR

#define LED_PIN               D7  


 //Depreciated but not harming anybody
#define CH_A                  D2        //BUS_12V_DISABLE              // HIGH to Disable
#define CH_B                  D3        //BUS_5V_DISABLE               // HIGH to Disable
#define CH_C                  D4

#define IN_D                  D5        //BUS_5V_MONITOR
#define IN_E                  D6        //BUS_12V_MONITOR

        

// Experimental Output Channels         // HIGH to Disable
#define CH_F                  D10
#define CH_G                  A0
#define CH_H                  A1
#define CH_I                  A2
#define CH_J                  A3

int outputChannels[5] = {CH_F, CH_G, CH_H, CH_I, CH_J);

#define ADC4                  A4             //Spare
#define ADC5                  A5             //Spare

#define CURRENT_SENSE_12V     A6
#define CURRENT_SENSE_5V      A7






#endif
