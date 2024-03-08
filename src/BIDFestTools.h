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

#endif // BIDFestTools_h
