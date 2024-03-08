/**
 * LED example
 *
 * This example demonstrates how to use the LED functions
 * to create patterns on the LED built into the board.
 *
 * Simply run the example and see the LED blink in different
 * patterns.
 */

#include <Arduino.h>

#include "BIDFestTools.h"  // Include our library to ease the process

// The setup function runs once when you press reset or power the board
void setup() {
    initializeLED();  // Initialize the LED
}

// The loop then function runs over and over again forever
void loop() {
    // Flash the LED on and off for 100 ms 5 times
    for (size_t counter = 0; counter < 5; counter++) {
        blinkLED(100);  // Blink the LED on and off for 100 ms
    }

    // Blink the LED on and off for 200 ms 3 times
    blinkLED(200, 3);  // Blink the LED on and off for 200 ms 3 times
}