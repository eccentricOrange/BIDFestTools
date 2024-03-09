/**
 * IR sensor functions
 * 
 * IR sensor functions to initialize and get the value of the IR sensor.
 * 
 * Simply connect the sensor to the digital pin 2 as per the
 * schematic and run the example. Open the serial monitor to
 * see the sensor values on your laptop.
 */

#include <Arduino.h>
#include "BIDFestTools.h"  // Include our library to ease the process

// The setup function runs once when you press reset or power the board
void setup() {
  initializeIRSensor(9);  // Initialize the IR sensor on digital pin 9
  Serial.begin(9600);  // Initialize the Serial Monitor
}

// The loop then function runs over and over again forever
void loop() {
  printIRObjectDetected();  // Print the IR sensor value to the serial monitor
}