/**
 * Temperature sensor
 *
 * Temperature sensor example to initialize and get the value of the temperature sensor.
 *
 * Simply connect the sensor to the digital pin 4 as per the
 * schematic and run the example. Open the serial monitor to
 * see the sensor values on your laptop.
 */

#include <Arduino.h>

#include "BIDFestTools.h"  // Include our library to ease the process

// The setup function runs once when you press reset or power the board
void setup() {
    initializeTemperatureSensor(A0);  // Initialize the temperature sensor on digital pin A0
    Serial.begin(9600);              // Initialize the Serial Monitor
}

// The loop then function runs over and over again forever
void loop() {
    printTemperature();  // Print the temperature sensor value to the serial monitor
    delay(1000);         // Delay for 1 second
}