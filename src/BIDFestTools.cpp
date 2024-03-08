#include "BIDFestTools.h"

#include <Arduino.h>

// LED functions

/// @brief Initializes the LED pin
void initializeLED() {
    pinMode(LED_BUILTIN, OUTPUT);
}

/// @brief Turns the LED on and then off after provided duration
/// @param duration Duration for which the LED should be on
void blinkLED(int duration) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(duration);
    digitalWrite(LED_BUILTIN, LOW);
    delay(duration);
}

/// @brief Blinks the LED on and off for the provided number of times, each time for the provided duration
/// @param duration Duration for which the LED should be on
/// @param times Number of times the LED should blink (one cycle is on and off)
void blinkLED(int duration, int times) {
    for (int i = 0; i < times; i++) {
        blinkLED(duration);
    }
}

// Ultrasound functions
uint8_t ULTRASOUND_TRIGGER_PIN = 12;
uint8_t ULTRASOUND_ECHO_PIN = 13;

/// @brief Initializes the ultrasound sensor
/// @param triggerPin Digital pin to which the trigger pin of the sensor is connected
/// @param echoPin Digital pin to which the echo pin of the sensor is connected
void initializeUltrasound(uint8_t triggerPin, uint8_t echoPin) {
    ULTRASOUND_TRIGGER_PIN = triggerPin;
    ULTRASOUND_ECHO_PIN = echoPin;

    pinMode(ULTRASOUND_TRIGGER_PIN, OUTPUT);
    pinMode(ULTRASOUND_ECHO_PIN, INPUT);
}

/// @brief Gives the distance measured by the ultrasound sensor in centimeters (4-200 cm)
float getUltrasoundDistance() {
    // Clear the trigger pin
    digitalWrite(ULTRASOUND_TRIGGER_PIN, LOW);
    delayMicroseconds(2);

    // Send a 10 microsecond pulse to the trigger pin
    digitalWrite(ULTRASOUND_TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASOUND_TRIGGER_PIN, LOW);

    // Measure the duration of the pulse on the echo pin
    float duration = pulseIn(ULTRASOUND_ECHO_PIN, HIGH);

    // Calculate the distance in cm
    return duration * 0.034 / 2;
}

/// @brief Prints the distance measured by the ultrasound sensor in centimeters (4-200 cm) to the Serial Monitor
void printUltrasoundDistance() {
    Serial.print("Distance: ");
    Serial.print(getUltrasoundDistance());
    Serial.println(" cm");
}

// Gas sensor functions
uint8_t GAS_SENSOR_PIN = A0;
// IR sensor functions

/// @brief Initializes the gas sensor
/// @param pin Analog pin to which the sensor is connected
void initializeGasSensor(uint8_t pin) {
    GAS_SENSOR_PIN = pin;
}

/// @brief Gives the value of the gas sensor as a percentage (0-100)
int getGasSensorValue() {
    return map(analogRead(GAS_SENSOR_PIN), 0, 1023, 0, 100);
}

/// @brief Prints the value of the gas sensor as a percentage (0-100) to the Serial Monitor
void printGasSensorValue() {
    Serial.print("Gas: ");
    Serial.print(getGasSensorValue());
    Serial.println("%");
}

// Soil moisture sensor functions
uint8_t SOIL_MOISTURE_SENSOR_PIN = A1;


/// @brief Initializes the soil moisture sensor
/// @param pin Analog pin to which the sensor is connected
void initializeSoilMoistureSensor(uint8_t pin) {
    SOIL_MOISTURE_SENSOR_PIN = pin;
}

/// @brief Gives the value of the soil moisture sensor as a percentage (0-100)
int getSoilMoistureSensorValue() {
    return map(analogRead(SOIL_MOISTURE_SENSOR_PIN), 0, 1023, 100, 0);
}

/// @brief Prints the value of the soil moisture sensor as a percentage (0-100) to the Serial Monitor
void printSoilMoistureSensorValue() {
    Serial.print("Soil Moisture: ");
    Serial.print(getSoilMoistureSensorValue());
    Serial.println("%");
}

// PIR sensor functions
uint8_t PIR_SENSOR_PIN = 2;

/// @brief Initializes the PIR sensor
/// @param pin Digital pin to which the sensor is connected
void initializePIRSensor(uint8_t pin) {
    PIR_SENSOR_PIN = pin;
    pinMode(PIR_SENSOR_PIN, INPUT);
}

/// @brief Checks if the PIR sensor has detected any motion. Returns `true` if motion is detected, `false` otherwise
bool isPIRMotionDetected() {
    return digitalRead(PIR_SENSOR_PIN);
}

/// @brief Prints if the PIR sensor has detected any motion to the Serial Monitor
void printPIRMotion() {
    Serial.println(isPIRMotionDetected() ? "Motion Detected!" : "No Motion");
}

// IR sensor functions
uint8_t IR_SENSOR_PIN = 3;

/// @brief Initializes the IR sensor
/// @param pin Digital pin to which the sensor is connected
void initializeIRSensor(uint8_t pin) {
    IR_SENSOR_PIN = pin;
    pinMode(IR_SENSOR_PIN, INPUT);
}

/// @brief Checks if the IR sensor has detected any object. Returns `true` if object is detected, `false` otherwise
bool isIRObjectDetected() {
    return digitalRead(IR_SENSOR_PIN);
}

/// @brief Prints if the IR sensor has detected any object to the Serial Monitor
void printIRObject() {
    Serial.println(isIRObjectDetected() ? "Object Detected!" : "No Object");
}