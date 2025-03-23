/**
 * Servo Motor example
 * 
 * This example demonstrates how to use the Servo motor.
 * 
 * Simply connect the servo motor to the digital pin 9 as per
 * the schematic and run the example. 
*/

#include <Arduino.h>
#include "BIDFestTools.h"  // Include our library to ease the process

// The setup function runs once when you press reset or power the board
void setup() {
    void initializeServoMotor(9);  // Initialize the Servo motor on digital pin 9
}

// The loop then function runs over and over again forever
void loop() {
  void sweepServo(int range = 180); // Sweep the motor back and forth
  delay(1000);  // Wait for a second
  void rotateServo(int angle = 90); // Rotate the motor to the specified angle
  delay(1000);  // Wait for a second
}