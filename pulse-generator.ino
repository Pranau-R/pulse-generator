// Include the necessary libraries
#include <Arduino.h>

// Define the GPIO pin to generate the pulse on
const int pulsePin = 11; // You can change this to any available pin

// Define the pulse parameters
const unsigned long pulseDuration = 100; // Pulse duration in milliseconds
const unsigned long pulseInterval = 1900; // Interval between pulses in milliseconds

unsigned long previousMillis = 0;
bool pulseState = LOW;

void setup()
	{
	// Initialize the pulse pin as an output
	pinMode(pulsePin, OUTPUT);
	}

void loop()
	{
	unsigned long currentMillis = millis();

	// Check if it's time to toggle the pulse state
	if (currentMillis - previousMillis >= (pulseState == HIGH ? pulseDuration : pulseInterval))
		{
		// Save the last time the pulse state was toggled
		previousMillis = currentMillis;

		// Toggle the pulse state
		pulseState = !pulseState;
		Serial.println("State Changes");

		// Set the pulse pin to the current state
		digitalWrite(pulsePin, pulseState);
		}
	}