#include <CapacitiveSensor.h>
#include "pitches.h"
/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Taylor Hokanson 2015
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */

CapacitiveSensor   sensor1 = CapacitiveSensor(2,3);        // 1M resistor between pins 3 and 2 (2 is sensor pin), add a wire and or foil if desired
int sensorTrip = 100; 

//A piezo speaker connected to digital pin 8

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

void setup(){
   Serial.begin(9600);
}

void loop(){
  //Get value of the sensor.
  long lastReading;

  if (lastReading < millis() + 10){        // limits frequency of sensor value checking
    long start = millis();
    long total1 =  sensor1.capacitiveSensor(lowerThreshold);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(total1);                  // print sensor output
    Serial.println("\t");

//map the sensor value to tones. The map()
  //function maps values smaller than lower
  //threshold to the lowest desired value.
  
 int pitch;
  if(total1>0){
    pitch=map(total1,lowerThreshold,upperThreshold,toneLow,toneHigh);
  }else{
    pitch=0;
  }   
    if (total1 > sensorTrip){               
        tone(8, pitch, 10);                  // drive a piezo element at pin A, frequency B, and for C microseconds  
    }
    lastReading = millis();
  }
}
