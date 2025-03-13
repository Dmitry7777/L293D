#ifndef L293D_H
#define L293D_H

class L293D {
public:
    L293D(int pin1, int pin2, int pin3, int pin4); // Constructor to set the pins
    void begin(); // Initialize pins
    void step(int steps, int speed); // Function for stepping the motor
    void setSpeed(int speed); // Set motor speed

private:
    int _pin1, _pin2, _pin3, _pin4; // Motor control pins
    int _delayTime; // Delay time between steps for speed control
};

#endif