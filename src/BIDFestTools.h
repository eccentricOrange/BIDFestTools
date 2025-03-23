#if !defined(BIDFestTools_h)
#define BIDFestTools_h

#include <Arduino.h>

void initializeLED();
void blinkLED(int duration);
void blinkLED(int duration, int times);

void initializeUltrasound(uint8_t triggerPin, uint8_t echoPin);
float getUltrasoundDistance();
void printUltrasoundDistance();

void initializeGasSensor(uint8_t analogPin);
int getGasSensorValue();
void printGasSensorValue();

void initializeSoilMoistureSensor(uint8_t analogPin);
int getSoilMoistureSensorValue();
void printSoilMoistureSensorValue();

void initializePIRSensor(uint8_t digitalPin);
bool isPIRMotionDetected();
void printPIRMotionDetected();

void initializeIRSensor(uint8_t digitalPin);
bool isIRObjectDetected();
void printIRObjectDetected();

void initializeDHTSensor(uint8_t digitalPin);
float getDHTTemperature();
float getDHTHumidity();
void printDHTTemperature();
void printDHTHumidity();
void printDHTData();

void initializeLDR(uint8_t analogPin);
int getLDRValue();  
void printLDRValue();

void initializeTemperatureSensor(uint8_t analogPin);
float getTemperature();
void printTemperature();

void initializeServo(uint_8 digitalPin);
void sweepServo(int angle);
void rotateServo(int angle);

#endif  // BIDFestTools_h
