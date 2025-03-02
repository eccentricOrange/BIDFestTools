# BIDFestTools

BIDFestTools is a library designed to simplify the use of various sensors with Arduino. It provides easy-to-use functions to initialize sensors, read their values, and print the data to the Serial Monitor.

## Features

- **LED Control**: Initialize and blink the built-in LED.
- **Ultrasound Sensor**: Measure distance using the HC-SR04 sensor.
- **Gas Sensor**: Read values from various gas sensors like MQ-3, MQ-8, and MQ-135.
- **Soil Moisture Sensor**: Measure soil moisture levels.
- **PIR Sensor**: Detect motion using a PIR sensor.
- **IR Sensor**: Detect objects using an IR sensor.
- **DHT Sensor**: Measure temperature and humidity using the DHT11 sensor.
- **LDR Sensor**: Measure light intensity using an LDR sensor.
- **Temperature Sensor**: Measure temperature using the LM35 sensor.

## About BIDFest

BITFest is an annual make-a-thon organized by [SBE-VIT](https://linktr.ee/sbe_vit) at the [Vellore Institute of Technology](https://vit.ac.in/).

BIDFest focuses on **Biomimicry**. Students are given the opportunity to engineer innovative solutions for today's challenges by presenting a 3D model or prototype of their ideas. The problem statements cover a wide range of fields, from architecture to healthcare. This is a chance to apply nature-inspired solutions to unconventional problems.

The final round consists of a pitching session where teams present their proposals to a panel of entrepreneurs and business leaders, with the aim of converting their ideas into startups.

## Installation

> [!NOTE]
>
> If you do not have the Arduino IDE installed, please follow their guide to installing it.
>
> https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/

### Using the Arduino Library Manager

1. Open the Arduino IDE.
2. Go to the "Sketch" menu and select "Include Library" > "Manage Libraries...".
3. In the Library Manager, type "BIDFestTools" into the search bar.
4. Find "BIDFestTools" in the list and click the "Install" button.

### Manual Installation

1. Download the library from the [GitHub repository](https://github.com/eccentricOrange/BIDFestTools) or as a zip file.
2. Open the Arduino IDE.
3. Go to the "Sketch" menu and select "Include Library" > "Add .ZIP Library...".
4. Navigate to the location where you downloaded the zip file and select it.
5. The library will be installed and ready to use.

Please see Arduino's official guide for more guidance: https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-installing-a-library/

### Dependencies

This library depends on the Adafruit DHT11 library for the DHT sensor functionality. Normally it should automatically be installed, but if you get errors about it, please ensure you have it installed:

1. Open the Arduino IDE.
2. Go to the "Sketch" menu and select "Include Library" > "Manage Libraries...".
3. In the Library Manager, type "DHT sensor library" into the search bar.
4. Find "DHT sensor library by Adafruit" in the list and click the "Install" button.

## Usage

Include the library in your Arduino sketch:

```cpp
#include <BIDFestTools.h>
```

### Examples

The library comes with several examples demonstrating how to use the various sensors. You can find these examples in the `examples` folder.

Each sensor has a dedicated guide available in the examples:

- **LED**: Demonstrates how to blink the built-in LED.
- **Ultrasound**: Measures distance using the HC-SR04 sensor.
- **GasSensor**: Reads values from a gas sensor.
- **SoilMoisture**: Measures soil moisture levels.
- **PIR**: Detects motion using a PIR sensor.
- **IR**: Detects objects using an IR sensor.
- **Atmospheric**: Measures temperature and humidity using the DHT11 sensor.
- **LDR**: Measures light intensity using an LDR sensor.
- **Temperature**: Measures temperature using the LM35 sensor.
- **SensorArray**: Demonstrates using multiple sensors simultaneously.

### Example: Ultrasound Sensor

```cpp
#include <Arduino.h>
#include "BIDFestTools.h"

void setup() {
  initializeUltrasound(11, 12);  // Initialize the ultrasound sensor on digital pins 11 and 12
  Serial.begin(9600);  // Initialize the Serial Monitor
}

void loop() {
  printUltrasoundDistance();  // Print the ultrasound sensor value to the serial monitor
  delay(1000);  // Wait for a second
}
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

