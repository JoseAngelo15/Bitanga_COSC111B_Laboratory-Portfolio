Objectives:
- Understand and implement Arduino Serial Connection
- Utilize Python as a tool for implementing serial connection, and implement a HTTP-based solution using FastAPI
- Create a simple circuit what will implement bi-directional connection between Arduino and Python using FastAPI

Instructions:
Using the laboratory guide, implement the following requirement
1. Use the following components:
- Arduino MCU
- 3 LEDs (Red, Green, Blue recommended)
- 3 Push Buttons
- Usual components (wires, breadboard, resistors, laptop with Python and pyserial installed)

2. Use the following pins:
- Red - 7    Green - 6    Blue - 5
- Button1 - 12    Button2 - 11    Button3 - 10

3. In your Arduino, create the sketch program that will do the following:
For Inbound signal
- When "1" is entered into the serial monitor, it should toggle only the red LED on/off
- When "2" is entered into the serial monitor, it should toggle only the green LED on/off
- When "3"  is entered into the serial monitor, it should toggle only the blue LED on/off
- Every input should be case insensitive.

4. Using FastAPI, create the following API that will do the following actions:
/led/<color> 
- value of color should be either "red", "green", "blue"
- for color value red, it should write back "1" back to Arduino to turn on the red LED
- for color value green, it should write back "2" back to Arduino to turn on the green LED
- for color value blue, it should write back "3" back to Arduino to turn on the blue LED
/led/on
- turns all LED on
/led/off
- turns all LED off
Required Output:
GitHub link containing the following
- Breadboard diagram
- Arduino code (any file name).ino
- Python code (should be same with Arduino code).py
- Grades of your members (if checked F2F, disregard)

Grading:
Speed: 30%
Algorithm: 30%
Output: 40%
