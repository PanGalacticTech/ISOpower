# PCB Specification Procedure


1. Schematic is verified

2. Assign footprints, use specified parts & JLCpcb parts library to cross check part against suitable item in parts libary. This will ensure that selected part is attainable and cost effective before moving onto layout.

3. Define net classes in Eschema using [File] > [Schematic Setup] > {Project} -> [Net Classes]

4. Open PCB in board editor.



## Net Classes
_List Net Classes & Specifications. Calculations below if required._

1oz Copper = ~35 um (0.035mm)
2oz Copper = ~70 um   

Trace Thickness Assumed to be 0.035mm


| Bus/Bus Class		| Type 	| Vmax 	| Vtyp 	| Imax 	| Ityp 	| Pmax	| Ptyp	|Temp Rise	| Trace Width(mm) 	| Notes |
|----				|----	|----	|----	|----	|----	|----	|----	|----		|----				|----	|
| Default			|Signal	| 		|		|		|		|		|		|	20		| 	0.8			|		|		
| GND				|Power	|	0	|	0	| 28.83	| 6.16	|		|		|	20		|	2.5				| 	Same power requirements as 24V_BUS		|
| 24V_BUS			|Power	|	26	|	24	| 28.83	| 6.16	|	346	| 147.9	|	20		|	2.5			|	24v must be able to provide sum total of all other power bus		|
| 12V_BUS			|Power	|	12	|	12	| 20.83	| 10.2	|	250	| 122.4	|	20		|	5			|	Imax is @ max power available from DC/DC - Unlikely condition	|
| 5V_BUS			|Power	|	5	|	5	| 16.2	| 4.8	|	81	| 24	|	20		|	2				|	Imax assumes 6x raspi drawing 2.7A, typical is 0.4-0.8A	|
| MCU_5V_BUS		|Power	|	5	|	5	| 3		| 0.5	|	15	| 1.5	|	20		|	1				|	Imax taken from max available from large wall plug USB chargers	|
| USB_PBUS			|Power	|	"	|	"	| "		|  "	|	"	| " 	|	20		|	1				|	Same as above Not included in 24v calcs	|
| Data				|Data	|	5	|	2.5	|	n/a	|	n/a	|	n/a	|	n/a	|	20		|	0.8				|					|
| CURRENT_SENSOR	|Power	|	12	|	12	|20.83	|	10.2|		|		|	4		|	6			|					|	
|
