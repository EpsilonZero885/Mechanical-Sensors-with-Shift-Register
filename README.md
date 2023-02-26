Project uses Arduino UNO R3 and a 74HC595 Shift Register to demonstrate operation of 3 different Mechanical Sensors, with output to 6 colored LEDs
	Each sensor, when triggered, will light up 2 adjacent LEDs for 1s
		Tilt: Displays Binary "3" (110000)
	 	Shock: Displays Binary "12" (001100)
		Tap: Displays Binary "48" (001100)
		

Materials:
 1 x Arduino UNO R3 (Cpu USB power supply)
 1 x Shift Register 74HC595
 6 x LED
 6 x 220 Ohm Resistors
 1 x Tap Switch Module
 1 x Tilt Switch Module
 1 x Shock Switch Module
 1 x Breadboard
 Misc Wires

Pinouts (Reads best if opened with notepad)
	UNO		74HC595		Tap		Shock		Tilt		LED1		LED2		LED3		LED4		LED5		LED6
	5VDC		VCC+MR		VCC		VCC		VCC		N/C		N/C		N/C		N/C		N/C		N/C
	GND		GND+OE		GND		GND		GND		CAT		CAT		CAT		CAT		CAT		CAT
	D9		N/C		OUTPUT		N/C		N/C		N/C		N/C		N/C		N/C		N/C		N/C
	D10		N/C		N/C		OUTPUT		N/C		N/C		N/C		N/C		N/C		N/C		N/C					
	D11		N/C		N/C		N/C		OUTPUT		N/C		N/C		N/C		N/C		N/C		N/C					
	D5		SH_CP/SRCLK	N/C		N/C		N/C		N/C		N/C		N/C		N/C		N/C		N/C
	D6		ST_CP/RCLK	N/C		N/C		N/C		N/C		N/C		N/C		N/C		N/C		N/C
	D7		DS/SER		N/C		N/C		N/C		N/C		N/C		N/C		N/C		N/C		N/C
	N/C		QA		N/C		N/C		N/C		ANO		N/C		N/C		N/C		N/C		N/C
	N/C		QB		N/C		N/C		N/C		N/C		ANO		N/C		N/C		N/C		N/C
	N/C		QC		N/C		N/C		N/C		N/C		N/C		ANO		N/C		N/C		N/C
	N/C		QD		N/C		N/C		N/C		N/C		N/C		N/C		ANO		N/C		N/C
	N/C		QE		N/C		N/C		N/C		N/C		N/C		N/C		N/C		ANO		N/C
	N/C		QF		N/C		N/C		N/C		N/C		N/C		N/C		N/C		N/C		ANO
NOTE: place a >=220ohm resistor in series with the anode of each LED to prevent damage


Experiment notes:
  -Test to verify correct pinouts

More reading:
https://lastminuteengineers.com/74hc595-shift-register-arduino-tutorial/
	Note: The pin names differ between this link and the TI/nxp datasheets for this register. The numbering is the same, cross-reference as needed
