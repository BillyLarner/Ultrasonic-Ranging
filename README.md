# Ultrasonic Ranging

A simple embedded systems project using an Arduino Uno and an ultrasonic ranging module to measure distance to an object.

## Overview

This project was developed using the Freenove starter set as an introduction to sensor interfacing and embedded programming.

The system measures the time taken for an ultrasonic pulse to travel to an object and return to the sensor. This time is then used to calculate the distance between the sensor and the object.

The system is designed to measure distances of up to approximately 2 metres and reports the measured distance through the Arduino serial monitor.

## Hardware

- Arduino Uno
- Ultrasonic ranging module
- 4 × Male/Female jumper cables
- USB cable

## How It Works

The Arduino controls the ultrasonic sensor using two digital pins:

- **Trigger pin:** Digital pin 12
- **Echo pin:** Digital pin 11

A short trigger pulse is sent to the sensor, which emits an ultrasonic pulse. The Arduino then measures the duration of the returning echo signal using `pulseIn()`.

The distance is calculated using the relationship:

$$
d = \frac{t \times v}{2}
$$

where:

- `d` is the distance
- `t` is the measured round-trip time
- `v` is the speed of sound in air

The factor of 2 accounts for the ultrasonic pulse travelling to the object and back.

## Implementation

The program:

1. Configures the trigger and echo pins.
2. Initialises serial communication at 9600 baud.
3. Generates a 10 μs trigger pulse.
4. Measures the echo pulse duration.
5. Calculates the distance in centimetres.
6. Outputs the measured distance through the serial monitor.
7. Repeats the measurement every 100 ms.
