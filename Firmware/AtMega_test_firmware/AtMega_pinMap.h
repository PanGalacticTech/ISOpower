/*  AtMega_pinMap.h

     Translates schematic pin numbers into Arduino digital pin numbers
     and register numbers for pins not available on arduino nano board




*/

#ifndef AtMega_pinMap_h
#define AtMega_pinMap_h



  
#define BUS_12V_DISABLE        2       // HIGH to Disable - I Think
#define BUS_5V_DISABLE         3       // HIGH to Disable
#define CH_C                   4

#define BUS_5V_MONITOR         5       //BUS_5V_MONITOR
#define BUS_12V_MONITOR        6       // BUS_12V_MONITOR

#define LED_PIN               7  


 //Depreciated but not harming anybody
#define CH_A                  2        //BUS_12V_DISABLE              // HIGH to Disable
#define CH_B                  3        //BUS_5V_DISABLE               // HIGH to Disable
#define CH_C                  4

#define IN_D                  5        //BUS_5V_MONITOR
#define IN_E                  6        //BUS_12V_MONITOR

        

// Experiment Output Channels         // HIGH to Disable- (I Think)
#define CH_F                  10
#define CH_G                  A0
#define CH_H                  A1
#define CH_I                  A2
#define CH_J                  A3

int outputChannels[5] = {CH_F, CH_G, CH_H, CH_I, CH_J} ;

#define ADC4                  A4             //Spare
#define ADC5                  A5             //Spare

#define CURRENT_SENSE_12V     A6
#define CURRENT_SENSE_5V      A7






#endif
