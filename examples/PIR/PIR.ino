/**
 * PIR sensor example
 * 
 * This example demonstrates how to use the PIR motion detection sensor.
 * 
 * Simply connect the sensor to the digital pin 2 as per the
 * schematic and run the example. Open the serial monitor to
 * see the sensor values on your laptop.
*/

#include <Arduino.h>
#include "BIDFestTools.h"  // Include our library to ease the process

// The setup function runs once when you press reset or power the board
void setup() {
  initializePIRSensor(2);  // Initialize the PIR sensor on digital pin 2
  Serial.begin(9600);  // Initialize the Serial Monitor
}

// The loop then function runs over and over again forever
void loop() {
  printPIRMotionDetected();  // Print the PIR sensor value to the serial monitor
  delay(1000);  // Wait for a second
}