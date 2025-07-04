# Walksence

This project simulates a basic pedestrian and vehicle detection system using an Arduino UNO on the Arduino IDE platform. It uses one PIR sensor to detect pedestrian presence, and two ultrasonic sensors (HC-SR04) to measure the proximity of approaching vehicles.

##  Hardware Components

- Arduino UNO
- 1 x PIR motion sensor
- 2 x HC-SR04 ultrasonic distance sensors
- Jumper wires
- Breadboard

##  Functionality

- **PIR Sensor** detects motion (i.e., a pedestrian).
- **Ultrasonic Sensors** measure distances in front of and behind the detection zone.
- If a pedestrian is detected:
  - The system reads distances from both ultrasonic sensors.
  - If any vehicle is closer than 150 cm, a warning is printed in the Serial Monitor.
- If no pedestrian is detected:
  - The system prints a "No pedestrian detected" message.


##  Code Overview

The main logic is located in the `loop()` function, which:
1. Checks for pedestrian presence.
2. If present, reads distances via the `measureDistance()` function.
3. Prints alerts via the Serial Monitor.

### `measureDistance(trigPin, echoPin)`
A helper function that triggers the ultrasonic sensor and calculates the distance based on the duration of the echo pulse.
