/**
 * Soil Moisture Sensor
 * 
 * This example demonstrates how to use to a soil moisture sensor and print it to the Serial Monitor.
 * 
 * Simply connect the soil moisture sensor to the analog pin A1 as
 * shown in the diagram and run the example. Open the Serial Monitor
 * and see the soil moisture percentage printed.
 */

#include <Arduino.h>
#include "BIDFestTools.h"  // Include our library to ease the process

// The setup function runs once when you press reset or power the board
void setup() {
    initializeSoilMoistureSensor(A1);  // Initialize the soil moisture sensor
    Serial.begin(9600);  // Initialize the Serial Monitor
}

// The loop then function runs over and over again forever
void loop() {
    printSoilMoistureSensorValue();  // Print the soil moisture percentage to the Serial Monitor
    delay(1000);  // Wait for a second
}