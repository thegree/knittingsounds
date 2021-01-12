/*
  Knittingsounds by Tamar Greenberg
  Adapted from Arduino Drawdio
  Adapted from Adafruit Arduino - Lesson 10. Pseudo Thermin 
  See https://learn.adafruit.com/adafruit-arduino-lesson-10-making-sounds?view=all for detailed explanation. 
  
  Connections:
  -Speaker Connection: negative to ground / positive to D12
  -1K Resistor Connection: ground / A1 (try different resistors)
  -Knitted Conductive Cord 1: 5V
  -Knitted Concductive Cord 2: A1  

  This sketch uses the tone commmand. 
  https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
  The Arduino 'tone' command takes two or three parameters. 
  The first is the pin to play the tone on, 
  the second is the frequency of the tone to play,
  and the third is the duration of the tone in milliseconds (optional).
  To play a note of a particular pitch, you specify the frequency. 
  
  The pitches.h library contains all the pitch values for typical notes. 
  See https://www.arduino.cc/en/Tutorial/toneMelody for use of pitches.h
  
*/

#include "pitches.h"

//A piezo speaker connected to digital pin 12
int speakerPin = 12;

//A stretch resistor connected to analog pin A1
int resistorPin = A1;

int sensorTrip = 10;

//The range of sensor values to be
//mapped to music tones. 
int lowerThreshold = 30;
int upperThreshold = 900;

//Define the lowest and highest tone. 
//Defined in pitches.h
int toneLow = NOTE_C3;
int toneHigh = NOTE_B6; // Change sensor sensitivity here

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(resistorPin);
  Serial.println(reading);

/*
  Music Procedure
  Map the sensor value to tones. 
  The map()function maps values smaller than the lower
  threshold to the lowest desired value.
*/
  
  int music;
  if (reading > 0) {
    music = map(reading, lowerThreshold, upperThreshold, toneLow, toneHigh);
  } else {
    music = 0;
  }
  if (reading > sensorTrip) {
    tone(speakerPin, music, 200);                  // drive a piezo element at pin A, frequency B, and for C microseconds
  }

  delay (100);   //try changing delay (in milliseconds) and see what happens

}
