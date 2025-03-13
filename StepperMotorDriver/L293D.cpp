#include "L293D.h"
#include <Arduino.h>

// Constructor initializes the pins
L293D::L293D(int pin1, int pin2, int pin3, int pin4) {
    _pin1 = pin1;
    _pin2 = pin2;
    _pin3 = pin3;
    _pin4 = pin4;
}

// Initialize the pins
void L293D::begin() {
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
    pinMode(_pin3, OUTPUT);
    pinMode(_pin4, OUTPUT);
}

// Set motor speed
void L293D::setSpeed(int speed) {
    _delayTime = 1000 / speed; // Calculate delay based on speed
}

// Step the motor
void L293D::step(int steps, int speed) {
    setSpeed(speed);
    for (int i = 0; i < steps; i++) {
        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, LOW);
        digitalWrite(_pin3, HIGH);
        digitalWrite(_pin4, LOW);
        delay(_delayTime);

        digitalWrite(_pin1, LOW);
        digitalWrite(_pin2, HIGH);
        digitalWrite(_pin3, HIGH);
        digitalWrite(_pin4, LOW);
        delay(_delayTime);

        digitalWrite(_pin1, LOW);
        digitalWrite(_pin2, HIGH);
        digitalWrite(_pin3, LOW);
        digitalWrite(_pin4, HIGH);
        delay(_delayTime);

        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, LOW);
        digitalWrite(_pin3, LOW);
        digitalWrite(_pin4, HIGH);
        delay(_delayTime);
    }
}