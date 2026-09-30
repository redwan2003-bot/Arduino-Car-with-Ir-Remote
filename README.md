# Arduino Car Remote Control

Arduino Uno car controlled by an IR remote and an L298N motor driver.

This repository is a reorganized copy of the project published by **Lee Curiosity** on Arduino Project Hub:

- Original project: https://projecthub.arduino.cc/lee_curiosity/a-beginners-guide-controlling-an-arduino-car-with-a-remote-5d4418
- Original publication date: April 30, 2024
- Original license shown on the page: **CC BY 4+**

## Hardware

- Arduino Uno Rev3
- L298N motor driver
- Four 5 V DC motors and wheels
- IR receiver/sensor
- IR remote control
- Four 18650 battery cells
- Jumper wires
- 3D-printed chassis (`hardware/Chassis.stl`)

## Pin mapping

| Arduino pin | L298N / function |
| --- | --- |
| D3 | Motor input 1 |
| D5 | Motor input 2 |
| D6 | Motor input 3 |
| D9 | Motor input 4 |
| D8 | IR receiver signal |

The motor-driver output terminals connect to the motor pairs. Use the original project’s circuit image in `docs/circuit-diagram.png` as the wiring reference.

## Software

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the `IRremote` library through the Library Manager.
3. Open `src/arduino_car_remote.ino`.
4. Select **Arduino Uno** and the correct serial port.
5. Upload the sketch.
6. Test the remote buttons: up, down, left, right, and stop.

The IR command values in the sketch match the remote used in the original project. If your remote differs, use `docs/ir-sensor-setup.ino` to print received codes in the Serial Monitor and update the constants in the main sketch.

## Attribution and source assets

The chassis model is included unchanged from the original downloadable asset. Project images are included for build reference and remain subject to their original rights and attribution requirements.
