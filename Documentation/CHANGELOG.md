# ChangeLog


04/02/2022
As per discussion 26/01/22
1. Changed per channel 5v MOSFET switches to MOSFET control of DC/DC module on/off pin - due to failure of MOSFET switching during testing.
2. Added 5v buck converter for independent MCU_5V power bus.
	- Ensured all 5v MCU hardware is powered from common MCU_5V bus.
3. Removed circuit from NC pins on DC/DC modules.
4. Changed ESP32 USB interface to CH340
5. Changed MCU serial logic level converters from MOSFET to IC - TXS0102DCT
	- TODO: OE pin now requires low signal untill DC/DC supply is stable - Does it? Can it just be tied to 5v bus with a large capacitor? Does it need MCU to hold pin low untill 5V_BUS is stable?
6. Removed redundent 3V3_IN to power distribution page.
	- Rechecked all sheets for redundent pins, it won't impact drawing traces, but it will impact readability.
7. Added Mechanical layer as hirarchical sheet.
8. Moved voltage monitoring circuits to hirarchical sheet
9. Added voltage monitoring with TL431DBZ to 12V_BUS
10. Automatic shutoff circuit removed, as this would prevent the DC/DC module from powering on. Instead moved to AtMega328p digital inputs
and microcontroller will control shutdown of DC/DC supply if out of spec voltage detected.
		- This is a severe limitation compared to the specification, and this also does not prevent damage to devices on 5V_BUS if voltage is pulled high, for example to 12v due to user error.
		- TODO: Add independent overvoltage protection to 5V_BUS? 		[Zener Diode Overvoltage Protection - Sparkfun](https://www.rs-online.com/designspark/how-does-zener-diode-do-overvoltage-protection-in-circuit#:~:text=In%20order%20to%20protect%20the,flow%20in%20the%20reverse%20direction).
11. Changed logic level conversion for 12v outputs to 12v drive circuit. [12v drive circuit](https://forum.arduino.cc/t/easiest-way-of-driving-amplifying-from-5v-to-12v/123290)
12. Added proto pin connections for ESP MCU.
13. Changed 20v Zener in reverse voltage protection to 18v

16/02/2022
14. Added Nominal Voltage indication for 5v & 12v Bus
15. Added capacitor to OE pin on logic level converter and tied pin to 3v3


## TODO

PCB Layout

## TODO Notes

Check advantages of TH or SMD electrolytic capacitors - speccing SMD parts for now.



## Components

What is Ext. Price on JLC PCB?

#### JLC Sourced Components

| Type					|Value	| Footprint | Price(pU)	|Min Quantity	| Price(min Q)	|JLC Part No|Vmax	| SMD/TH 	|Basic Part?|
|---					|---	|---		|---		|---			|---			|---		|--		|---		|			|
|Film/MLCC				| 100n	| 0805		|0.0046		|	4000		|				|C49678		|100	|	SMD		|	Yes		|
|Film/MLCC				| 22n	| 0805		|0.0112		|	4000 or 20	| 0.0112		|C1804		|50		|	SMD		|	Yes		|
|Electrolytic Capacitor | 100u 	| 6.3x7.7	|0.0895		| 	900			| 80.55			|C65221		|35		|	SMD		|			|
|Electrolytic Capacitor | 22u	| 6.3x5.4	|0.0383		|  	1000 or 10?	| 38.3			|C72505		|50		|	SMD 	|			|	
|Film/MLCC				| 1n	| 0805		|0.0076		| 	4000 or 20? | 30.4			|C46653		|50		|	SMD		|	Yes		|
|Electrolytic Capacitor	| 680u	| 12.5x20	|0.2914		|	100 or 1?	| 29.14			|C270015	|50		| 	TH		|			|
|Electrolytic Capacitor	| 220u	| 6.3x7.7	|0.0467		|	1000 or 10	| 46.7			|C2887273	|16		| 	SMD		|	Yes		|
|Film/MLCC				| 4n7	| 0805		|0.0054		| 	4000 or 20? | 21.6			|C1744		|50		|	SMD		|	Yes		|
|Zener Diode			| 18v 	| MINIMELF	|0.0289		|	2500 or 20	|	72?			|C410854	|19.1	|	SMD		|			|	
|LED					| Blue	| 0805		|0.038		|	3000		|	114?		|C138557	| n/a	|	SMD		|			|
|Schottky Diode 1N5821	|SS36-E3| DO-214AB	|0.3063 	|	850 or 2	|  255!?!		|C35722		| 60	| 	SMD		|	Yes	 	| Used D_SMA Footprint
|PRTR5V0U2X				|		| SOT-143	|0.0649		|	3000 or 10	| 				|C2827688	|		|	SMD		|			|
|LED					|Green	| 0805		|0.0178		|				|				|C84257		|		|	SMD		|			|	
|LED					|Red	| 0805		|0.0123		|				|				|C84256		|		|	SMD		|	Yes		|
|Fuse/Holder			|20A	| -			|			|				|				|			|		|	TH		|			| Can be sourced from JLC? Check
|USB Connector			| A   	|
	
#### Externally Sourced Components

| Type 	| Value | Footprint | Price(pu)	| Min Q	| Price (Min Q)	|	Supplyer 	| Supplier ID 	| 
|---	|---	|---		|---		|---	|---			|---			|---			|	
| XT60	| male	| custom	|			|		|				|				|				|


## Change Notes
OE pin now requires low signal untill DC/DC supply is stable - Does it? Can it just be tied to 5v bus with a large capacitor? < YES || Does it need MCU to hold pin low untill 5V_BUS is stable? < Overkill

Add independent overvoltage protection to 5V_BUS? 		[Zener Diode Overvoltage Protection - Sparkfun](https://www.rs-online.com/designspark/how-does-zener-diode-do-overvoltage-protection-in-circuit#:~:text=In%20order%20to%20protect%20the,flow%20in%20the%20reverse%20direction).
PROBLEM: Suggested 100r resistor between 5v and raspberry pi, this limits current to 50mA, raspi requires min 400mA (Tested with raspi 512mb, raspi4 will likely require more current) 
if R=12.5 is selected, Imax would be 400mA, however power disspation in the resistor is now 0.4\*5 = 2W.






