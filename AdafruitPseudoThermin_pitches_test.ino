/*
  Adafruit Arduino - Lesson 10. Pseudo Thermin
*/
#include "pitches.h"

//A piezo speaker connected to digital pin 5
int speakerPin = 12;

//A stretch resistor connected to analog pin A0
int resistorPin = 0;

int sensorTrip = 100;

//The range of sensor values to be
//mapped to music tones. 
int lowerThreshold = 80;
int upperThreshold = 900;

//Define the lowest and highest tone. Defined
//in pitches.h
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


  //map the sensor value to tones. The map()
  //function maps values smaller than lower
  //threshold to the lowest desired value.

  int music;
  if (reading > 0) {
    music = map(reading, lowerThreshold, upperThreshold, toneLow, toneHigh);
  } else {
    music = 0;
  }
  if (reading > sensorTrip) {
    tone(speakerPin, music, 100);                  // drive a piezo element at pin A, frequency B, and for C microseconds
  }

  delay (1000);

}
