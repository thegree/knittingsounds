/*
Adafruit Arduino - Lesson 10. Pseudo Thermin
*/
#include "pitches.h"

//A piezo speaker connected to digital pin 12
int speakerPin = 12;

//A stretch resistor connected to analog pin 0
int resistorPin = 0;

int sensorTrip = 100; 

//The range of capacitive sensor values to be
//mapped to music tones. See example
//"help/CapacitiveSwitchTest" about how to get
//the values
int lowerThreshold=80;
int upperThreshold=900;

//Define the lowest and highest tone. Defined
//in pitches.h
int toneLow=NOTE_C3;
int toneHigh=NOTE_B6;// Change sensor sensitivity here

void setup()
{
  //nothing to do here
}

void loop()
{
int reading = analogRead(resistorPin);


  
  //map the sensor value to tones. The map()
  //function maps values smaller than lower
  //threshold to the lowest desired value.

  int music;
  if(reading>0){
    music=map(reading,lowerThreshold,upperThreshold,toneLow,toneHigh);
  }else{
    music=0;
  }   
    if (reading > sensorTrip){               
        tone(12, music, 10);                  // drive a piezo element at pin A, frequency B, and for C microseconds  
    }
    
  

}
