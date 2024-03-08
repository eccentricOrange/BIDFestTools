/**
 * Sensor Array Demo
 *
 * This is a demo of using multiple sensors at once.
 *
 * Simply connect the sensors to the digital pins as per the
 * schematic and run the example. Open the serial monitor to
 * see the sensor values on your laptop.
 */

#include <Arduino.h>
#include <BIDFestTools.h>  // Include our library to ease the process

// The setup function runs once when you press reset or power the board
void setup() {
    initializePIRSensor(2);            // Initialize the PIR sensor on digital pin 2
    initializeUltrasound(3, 4);  // Initialize the ultrasound sensor on digital pins 3 and 4
    initializeSoilMoistureSensor(A0);  // Initialize the soil moisture sensor on analog pin A0

    Serial.begin(9600);  // Initialize the Serial Monitor
}

// The loop then function runs over and over again forever
void loop() {
    printPIRMotionDetected();  // Print the PIR sensor value to the serial monitor
    printUltrasoundDistance();  // Print the ultrasound sensor value to the serial monitor
    printSoilMoistureSensorValue();  // Print the soil moisture sensor value to the serial monitor
    delay(1000);  // Wait for a second
}