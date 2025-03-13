#include <L293D.h>

// Define motor control pins
const int motorPin1 = 2;  // Pin 1
const int motorPin2 = 3;  // Pin 2
const int motorPin3 = 4;  // Pin 3
const int motorPin4 = 5;  // Pin 4
L293D motor(motorPin1, motorPin2, motorPin3, motorPin4); // Create an instance of L293D

void setup() {
    motor.begin(); // Initialize motor
}

void loop() {
    motor.step(100, 60); // Step 100 steps at 60 RPM
    delay(2000); // Wait for 2 seconds
    motor.step(-100, 60); // Step back 100 steps at 60 RPM
    delay(2000); // Wait for 2 seconds
}