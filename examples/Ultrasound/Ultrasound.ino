/**
 * Ultrasound sensor example
 * 
 * This example demonstrates how to use the ultrasound distance sensor.
 * 
 * Simply connect the sensor to the digital pins 12 and 13 as per the
 * schematic and run the example. Open the serial monitor to
 * see the sensor values on your laptop.
 */

#include <Arduino.h>
#include "BIDFestTools.h"  // Include our library to ease the process

// The setup function runs once when you press reset or power the board
void setup() {
  initializeUltrasound(12, 13);  // Initialize the ultrasound sensor on digital pins 12 and 13
                                 // 12 is the trigger pin and 13 is the echo pin
  Serial.begin(9600);  // Initialize the Serial Monitor
}

// The loop then function runs over and over again forever
void loop() {
  printUltrasoundDistance();  // Print the ultrasound sensor value to the serial monitor
}