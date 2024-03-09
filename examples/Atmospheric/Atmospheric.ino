/**
 * Atmospheric sensor example
 * 
 * Atmospheric sensor example to initialize and get the value of the atmospheric sensor.
 * 
 * Simply connect the sensor to the digital pin 2 as per the
 * schematic and run the example. Open the serial monitor to
 * see the sensor values on your laptop.
 */

#include <Arduino.h>
#include "BIDFestTools.h"  // Include our library to ease the process

// The setup function runs once when you press reset or power the board
void setup() {
  initializeDHTSensor(4);  // Initialize the atmospheric sensor on digital pin 4
  Serial.begin(9600);  // Initialize the Serial Monitor
}

// The loop then function runs over and over again forever
void loop() {
  printDHTData();  // Print the atmospheric sensor value to the serial monitor
}