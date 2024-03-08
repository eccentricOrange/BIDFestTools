/**
 * LDR example
 * 
 * LDR example to initialize and get the value of the LDR sensor.
 * 
 * Simply connect the sensor to the analog pin A0 as per the
 * schematic and run the example. Open the serial monitor to
 * see the sensor values on your laptop.
 */

#include <Arduino.h>
#include "BIDFestTools.h"  // Include our library to ease the process

// The setup function runs once when you press reset or power the board
void setup() {
  initializeLDR(A0);  // Initialize the LDR sensor on analog pin A0
  Serial.begin(9600);  // Initialize the Serial Monitor
}

// The loop then function runs over and over again forever
void loop() {
  printLDRValue();  // Print the LDR sensor value to the serial monitor
}