An IR sensor is a sensor that measures the distance from an object by emitting an infrared light and measuring the time it takes for the light to reflect back to the sensor. The sensor has an adjustable threshold that can be used to detect objects within a certain range. The sensor can be used to detect objects in front of it, or to detect the presence of an object in a certain area.

# Hardware
- IR Sensor
- Arduino
- Jumper Wires

# Circuit
Connect the IR sensor to the Arduino as shown in the diagram. Here is a table of the connections for your reference:

| IR Sensor | Arduino |
| --- | --- |
| VCC | 5V |
| GND | GND |
| OUT | Digital Pin 9 |

![diagram](diagram.png)

You're free to use any digital pin for the OUT pin, from 2 to 12. Just make sure to update the pin number in the code, as shown below in the `void setup()` function.

```cpp
void setup() {
    initializeIRSensor(2);  // Initialize the IR sensor on digital pin 2
}
```