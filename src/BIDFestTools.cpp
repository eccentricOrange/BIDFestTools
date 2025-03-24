#include "BIDFestTools.h"

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

DHT* dht;

uint8_t ULTRASOUND_TRIGGER_PIN = 12;
uint8_t ULTRASOUND_ECHO_PIN = 13;
uint8_t GAS_SENSOR_PIN = A0;
uint8_t SOIL_MOISTURE_SENSOR_PIN = A1;
uint8_t PIR_SENSOR_PIN = 2;
uint8_t IR_SENSOR_PIN = 3;
uint8_t DHT_SENSOR_PIN = 4;
uint8_t LDR_PIN = A2;
uint8_t TEMPERATURE_SENSOR_PIN = A3;

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
void printPIRMotionDetected() {
    Serial.println(isPIRMotionDetected() ? "Motion Detected!" : "No Motion");
}

/// @brief Initializes the IR sensor
/// @param pin Digital pin to which the sensor is connected
void initializeIRSensor(uint8_t pin) {
    IR_SENSOR_PIN = pin;
    pinMode(IR_SENSOR_PIN, INPUT);
}

/// @brief Checks if the IR sensor has detected any object. Returns `true` if object is detected, `false` otherwise
bool isIRObjectDetected() {
    return !digitalRead(IR_SENSOR_PIN);
}

/// @brief Prints if the IR sensor has detected any object to the Serial Monitor
void printIRObjectDetected() {
    Serial.println(isIRObjectDetected() ? "Object Detected!" : "No Object");
}

/// @brief Initializes the DHT sensor
/// @param pin Digital pin to which the sensor is connected
void initializeDHTSensor(uint8_t pin) {
    DHT_SENSOR_PIN = pin;
    dht = new DHT(DHT_SENSOR_PIN, DHT11);
    dht->begin();
}

/// @brief Gives the temperature measured by the DHT sensor in Celsius
float getDHTTemperature() {
    return dht->readTemperature();
}

/// @brief Gives the humidity measured by the DHT sensor in percentage
float getDHTHumidity() {
    return dht->readHumidity();
}

/// @brief Prints the temperature measured by the DHT sensor in Celsius to the Serial Monitor
void printDHTTemperature() {
    Serial.print("Temperature: ");
    Serial.print(getDHTTemperature());
    Serial.println(" °C");
}

/// @brief Prints the humidity measured by the DHT sensor in percentage to the Serial Monitor
void printDHTHumidity() {
    Serial.print("Humidity: ");
    Serial.print(getDHTHumidity());
    Serial.println("%");
}

/// @brief Prints the temperature and humidity measured by the DHT sensor to the Serial Monitor
void printDHTData() {
    printDHTTemperature();
    printDHTHumidity();
}

/// @brief Initializes the LDR sensor
/// @param pin Analog pin to which the sensor is connected
void initializeLDR(uint8_t pin) {
    LDR_PIN = pin;
}

/// @brief Gives the value of the LDR sensor as a percentage (0-100)
int getLDRValue() {
    return map(analogRead(LDR_PIN), 0, 1023, 0, 100);
}

/// @brief Prints the value of the LDR sensor as a percentage (0-100) to the Serial Monitor
void printLDRValue() {
    Serial.print("LDR: ");
    Serial.print(getLDRValue());
    Serial.println("%");
}

/// @brief Initializes the temperature sensor
/// @param pin Analog pin to which the sensor is connected
void initializeTemperatureSensor(uint8_t pin) {
    TEMPERATURE_SENSOR_PIN = pin;
}

/// @brief Gives the temperature measured by the temperature sensor in Celsius
float getTemperature() {
    uint16_t ADCValue;
    float temperature;
    ADCValue = analogRead(TEMPERATURE_SENSOR_PIN);	
    temperature = (ADCValue * 4.88);	
    temperature = (temperature / 10);	
    return temperature;
}

/// @brief Prints the temperature measured by the temperature sensor in Celsius to the Serial Monitor
void printTemperature() {
    Serial.print("Temperature: ");
    Serial.print(getTemperature());
    Serial.println(" °C");
}
