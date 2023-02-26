/*
 Project uses Arduino UNO R3 to show 3 different Vibration Sensor fuctions 

 1 x Arduino UNO R3 (Cpu USB power supply)
 1 x Shift Register 74HC595
 6 x LED
 6 x 220 Ohm Resistors
 1 x Tap Switch Module
 1 x Tilt Switch Module
 1 x Shock Switch Module
 */


/* Include Libraries */
#include <Arduino.h> //for VSCode

/* Global Variables */
const uint8_t latchPin = 6; //Pin connected to ST_CP of 74HC595
const uint8_t clockPin = 5; //Pin connected to SH_CP of 74HC595
const uint8_t dataPin = 7; //Pin connected to DS of 74HC595
const uint8_t tapSense = 9; //Data pin from Tap Switch
const uint8_t shockSense = 10; //Data pin from Shock Switch
const uint8_t tiltSense = 11; //Data pin from Tilt Switch

/* Setup Loop */
void  setup() {
  /* Initialize Serial Monitor: */
  Serial.begin(9600); //Start Serial Communication at 9600 baud rate
  if (!Serial) {
    while (1); //Wait for Serial Monitor to open
  } //end if (!Serial)

  /* Initialize Pins */
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(tapSense, INPUT_PULLUP);
  pinMode(shockSense, INPUT_PULLUP);
  pinMode(tiltSense, INPUT_PULLUP);
} //end setup()

/* Main Loop*/
void  loop() {
  /* Read Sensors */
  bool tapRead = digitalRead(tapSense); //Read the state of the Tap Sensor
  bool shockRead = digitalRead(shockSense); //Read the state of the Shock Sensor
  bool tiltRead = digitalRead(tiltSense); //Read the state of the Tilt Sensor

  /* Clear Shift Register */
  digitalWrite(latchPin, LOW); //Open the latch
  shiftOut(dataPin, clockPin, MSBFIRST, 0); //Shift the bits, 0 = 000000
  digitalWrite(latchPin, HIGH); //Close the latch

  /* Check Tap Sensor */
  if (tapRead == LOW) { //Low when Triggered
    digitalWrite(latchPin, LOW); //Open the latch
    shiftOut(dataPin, clockPin, MSBFIRST, 48); //Shift the bits, 48 = 110000
    digitalWrite(latchPin, HIGH); //Close the latch
    
    /* For Testing */
    Serial.print("tapSense = ");
    Serial.println (tapRead);

    /* Read Pin States */
    bool tapRead = digitalRead(tapSense); //Read the state of the Tap Sensor
    bool shockRead = digitalRead(shockSense); //Read the state of the Shock Sensor
    bool tiltRead = digitalRead(tiltSense); //Read the state of the Tilt Sensor
    delay(1000); //Delay 1 second
  } //end if (tapRead==LOW)

  /* Check Shock Sensor */
  if (shockRead == LOW) { //Low when Triggered
    digitalWrite(latchPin, LOW); //Open the latch
    shiftOut(dataPin, clockPin, MSBFIRST, 12); //Shift the bits, 12 = 001100
    digitalWrite(latchPin, HIGH); //Close the latch
    
    /* For Testing */
    Serial.print("shockSense = ");
    Serial.println (shockRead);

    /* Read Pin States */
    bool tapRead = digitalRead(tapSense); //Read the state of the Tap Sensor
    bool shockRead = digitalRead(shockSense); //Read the state of the Shock Sensor
    bool tiltRead = digitalRead(tiltSense); //Read the state of the Tilt Sensor
    delay(1000); //Delay 1 second
  } //end if (shockRead==LOW)

  /* Check Tilt Sensor */
  if (tiltRead == LOW) { //Low when Triggered
    digitalWrite(latchPin, LOW); //Open the latch
    shiftOut(dataPin, clockPin, MSBFIRST, 3); //Shift the bits, 3 = 000011
    digitalWrite(latchPin, HIGH); //Close the latch

    /* For Testing */
    Serial.print("tiltSense = ");
    Serial.println (tiltRead);

    /*Read Pin States*/
    bool tapRead = digitalRead(tapSense); //Read the state of the Tap Sensor
    bool shockRead = digitalRead(shockSense); //Read the state of the Shock Sensor
    bool tiltRead = digitalRead(tiltSense); //Read the state of the Tilt Sensor
    delay(1000); //Delay 1 second
  } //end if (tiltRead==LOW)
} //end loop()
