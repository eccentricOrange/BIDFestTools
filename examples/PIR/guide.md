A PIR (passive infrared) sensor is a device that detects motion by measuring changes in the infrared levels emitted by surrounding objects. The sensor has a digital output that can be used to detect motion within a certain range. We'll simply get the status of the sensor, whether it detects motion or not.

# Hardware
- PIR Sensor
- Arduino
- Jumper Wires

# Circuit
Connect the PIR sensor to the Arduino as shown in the diagram. Here is a table of the connections for your reference:

| PIR Sensor | Arduino |
| --- | --- |
| VCC | 5V |
| GND | GND |
| OUT | Digital Pin 2 |

![diagram](diagram.png)

You're free to use any digital pin for the OUT pin, from 2 to 12. Just make sure to update the pin number in the code, as shown below in the `void setup()` function.

```cpp
void setup() {
    initializePIRSensor(2);  // Initialize the PIR sensor on digital pin 2
}
```