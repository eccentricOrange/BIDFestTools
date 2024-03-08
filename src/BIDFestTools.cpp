#include "BIDFestTools.h"

#include <Arduino.h>

// LED functions

/// @brief Initializes the LED pin
void BIDFestTools::initializeLED() {
    pinMode(LED_BUILTIN, OUTPUT);
}

/// @brief Turns the LED on and then off after provided duration
/// @param duration Duration for which the LED should be on
void BIDFestTools::blinkLED(int duration) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(duration);
    digitalWrite(LED_BUILTIN, LOW);
    delay(duration);
}

/// @brief Blinks the LED on and off for the provided number of times, each time for the provided duration
/// @param duration Duration for which the LED should be on
/// @param times Number of times the LED should blink (one cycle is on and off)
void BIDFestTools::blinkLED(int duration, int times) {
    for (int i = 0; i < times; i++) {
        blinkLED(duration);
    }
}

/// @brief Initializes the ultrasound sensor
/// @param triggerPin Digital pin to which the trigger pin of the sensor is connected
/// @param echoPin Digital pin to which the echo pin of the sensor is connected
void BIDFestTools::initializeUltrasound(uint8_t triggerPin, uint8_t echoPin) {
    ULTRASOUND_TRIGGER_PIN = triggerPin;
    ULTRASOUND_ECHO_PIN = echoPin;

    pinMode(ULTRASOUND_TRIGGER_PIN, OUTPUT);
    pinMode(ULTRASOUND_ECHO_PIN, INPUT);
}

/// @brief Gives the distance measured by the ultrasound sensor in centimeters (4-200 cm)
float BIDFestTools::getUltrasoundDistance() {
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
void BIDFestTools::printUltrasoundDistance() {
    Serial.print("Distance: ");
    Serial.print(getUltrasoundDistance());
    Serial.println(" cm");
}

/// @brief Initializes the gas sensor
/// @param pin Analog pin to which the sensor is connected
void BIDFestTools::initializeGasSensor(uint8_t pin) {
    GAS_SENSOR_PIN = pin;
}

/// @brief Gives the value of the gas sensor as a percentage (0-100)
int BIDFestTools::getGasSensorValue() {
    return map(analogRead(GAS_SENSOR_PIN), 0, 1023, 0, 100);
}

/// @brief Prints the value of the gas sensor as a percentage (0-100) to the Serial Monitor
void BIDFestTools::printGasSensorValue() {
    Serial.print("Gas: ");
    Serial.print(getGasSensorValue());
    Serial.println("%");
}

/// @brief Initializes the soil moisture sensor
/// @param pin Analog pin to which the sensor is connected
void BIDFestTools::initializeSoilMoistureSensor(uint8_t pin) {
    SOIL_MOISTURE_SENSOR_PIN = pin;
}

/// @brief Gives the value of the soil moisture sensor as a percentage (0-100)
int BIDFestTools::getSoilMoistureSensorValue() {
    return map(analogRead(SOIL_MOISTURE_SENSOR_PIN), 0, 1023, 100, 0);
}

/// @brief Prints the value of the soil moisture sensor as a percentage (0-100) to the Serial Monitor
void BIDFestTools::printSoilMoistureSensorValue() {
    Serial.print("Soil Moisture: ");
    Serial.print(getSoilMoistureSensorValue());
    Serial.println("%");
}

/// @brief Initializes the PIR sensor
/// @param pin Digital pin to which the sensor is connected
void BIDFestTools::initializePIRSensor(uint8_t pin) {
    PIR_SENSOR_PIN = pin;
    pinMode(PIR_SENSOR_PIN, INPUT);
}

/// @brief Checks if the PIR sensor has detected any motion. Returns `true` if motion is detected, `false` otherwise
bool BIDFestTools::isPIRMotionDetected() {
    return digitalRead(PIR_SENSOR_PIN);
}

/// @brief Prints if the PIR sensor has detected any motion to the Serial Monitor
void BIDFestTools::printPIRMotionDetected() {
    Serial.println(isPIRMotionDetected() ? "Motion Detected!" : "No Motion");
}

/// @brief Initializes the IR sensor
/// @param pin Digital pin to which the sensor is connected
void BIDFestTools::initializeIRSensor(uint8_t pin) {
    IR_SENSOR_PIN = pin;
    pinMode(IR_SENSOR_PIN, INPUT);
}

/// @brief Checks if the IR sensor has detected any object. Returns `true` if object is detected, `false` otherwise
bool BIDFestTools::isIRObjectDetected() {
    return digitalRead(IR_SENSOR_PIN);
}

/// @brief Prints if the IR sensor has detected any object to the Serial Monitor
void BIDFestTools::printIRObjectDetected() {
    Serial.println(isIRObjectDetected() ? "Object Detected!" : "No Object");
}