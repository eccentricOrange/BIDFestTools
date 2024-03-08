#if !defined(BIDFestTools_h)
#define BIDFestTools_h

#include <Arduino.h>

class BIDFestTools {
   private:
    uint8_t ULTRASOUND_TRIGGER_PIN = 12;
    uint8_t ULTRASOUND_ECHO_PIN = 13;

    uint8_t GAS_SENSOR_PIN = A0;

    uint8_t SOIL_MOISTURE_SENSOR_PIN = A1;

    uint8_t PIR_SENSOR_PIN = 2;

    uint8_t IR_SENSOR_PIN = 3;

   public:
    BIDFestTools() {};
    ~BIDFestTools() {};

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
};

#endif  // BIDFestTools_h
