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


//Pin connected to ST_CP of 74HC595
int latchPin = 6;

//Pin connected to SH_CP of 74HC595
int clockPin = 5;

////Pin connected to DS of 74HC595
int dataPin = 7;

int tapSense = 9; //Data from Tap Switch
int shockSense = 10; //Data from Shock Switch
int tiltSense = 11; //Data from Tilt Switch


void  setup() {

  Serial.begin(9600);

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  pinMode(tapSense, INPUT);
  pinMode(shockSense, INPUT);
  pinMode(tiltSense, INPUT);

}


void  loop() {

  int tapRead = digitalRead(tapSense);
  int shockRead = digitalRead(shockSense);
  int tiltRead = digitalRead(tiltSense);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin, HIGH);


   if (tapRead==LOW) { //Low when Triggered
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 48);
    digitalWrite(latchPin, HIGH);

    Serial.print("tapSense = ");
    Serial.println (tapRead);

   int tapRead = digitalRead(tapSense);
   int shockRead = digitalRead(shockSense);
   int tiltRead = digitalRead(tiltSense);

           delay(1000);
   }


  if (shockRead==LOW) { //Low when Triggered
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 12);
    digitalWrite(latchPin, HIGH);

    Serial.print("shockSense = ");
    Serial.println (shockRead);

    
   int tapRead = digitalRead(tapSense);
   int shockRead = digitalRead(shockSense);
   int tiltRead = digitalRead(tiltSense);

          delay(1000);
   }


  if (tiltRead==LOW) { //Low when Triggered
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 3);
    digitalWrite(latchPin, HIGH);

    Serial.print("tiltSense = ");
    Serial.println (tiltRead);
    
   int tapRead = digitalRead(tapSense);
   int shockRead = digitalRead(shockSense);
   int tiltRead = digitalRead(tiltSense);

          delay(1000);
   }
}
