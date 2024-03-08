/**
 * Gas Sensor Demo
 * 
 * This example demonstrates how to use the analog gas sensor.
 * 
 * Simply connect the sensor to the analog pin A0 as per the
 * schematic and run the example. Open the serial monitor to
 * see the sensor values on your laptop.
 * 
*/

#include <Arduino.h>
#include "BIDFestTools.h"  // Include our library to ease the process

// The setup function runs once when you press reset or power the board
void setup() {
  initializeGasSensor(A0);  // Initialize the gas sensor on analog pin A0
  Serial.begin(9600);  // Initialize the Serial Monitor
}

// The loop then function runs over and over again forever
void loop() {
  printGasSensorValue();  // Print the gas sensor value to the serial monitor
  delay(1000);  // Wait for a second
}