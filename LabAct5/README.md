# IoT_LaboratoryActivity-5

Objectives:
- Understand and implement Arduino Serial Connection
- Utilize Python as a tool for implementing serial connection
- Create a simple circuit that can be controlled using Serial connection using Arduino and Python

Instructions:
Using the laboratory guide, implement the following requirement
1. Use the following components:
- Arduino MCU
- 3 LEDs (Red, Green, Blue recommended)
- Usual components (wires, breadboard, resistors, laptop with Python and pyserial installed)

2. Use the following pins:
- Red - 8    Green - 9    Blue - 10

3. In your Arduino, create the sketch program that will allow serial input. The following actions are expected for the inputs
- R/r = it should toggle only the red LED on/off
- G/g = it should toggle only the green LED on/off
- B/b = it should toggle only the blue LED on/off
- A/a = it should turn all LEDs on
- O/o = it should turn all LEDs off
- all other inputs should return an error

4. Using Python, create a non-terminating script that will show the following choices, and be able to execute the same logic as in Arduino.

[R] Red ON/OFF
[G] Green ON/OFF
[B] Blue ON/OFF
[A] All ON
[O] All OFF
[X] Exit

5. When X/x is inputted, it should terminate the Python application from running.

6. All inputs should be case insensitive.
