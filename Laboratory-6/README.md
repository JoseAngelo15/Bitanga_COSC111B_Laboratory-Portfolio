Objectives:
- Understand and implement Arduino Serial Connection
- Utilize Python as a tool for implementing serial connection
- Create a simple circuit what will implement bi-directional connection between Arduino and Python

Instructions:
Using the laboratory guide, implement the following requirement
1. Use the following components:
- Arduino MCU
- 3 LEDs (Red, Green, Blue recommended)
- 3 Push Buttons
- Usual components (wires, breadboard, resistors, laptop with Python and pyserial installed)

2. Use the following pins:
- Red - 7    Green - 6    Blue - 5
- Button1 - 12    Button2 - 11    Button3 - 10

3. In your Arduino, create the sketch program that will do the following:
For Outbound signal
- Button 1 prints 'R' ONCE when pressed
- Button 2 prints 'G' ONCE when pressed
- Button 3 prints 'B' ONCE when pressed
- When these buttons are clicked in Arduino, it should only show the signals passed. No LED actions should take place

For Inbound signal
- When "1" is entered into the serial monitor, it should toggle only the red LED on/off
- When "2" is entered into the serial monitor, it should toggle only the green LED on/off
- When "3"  is entered into the serial monitor, it should toggle only the blue LED on/off
- Every input should be case insensitive.

4. Using Python, create a non-terminating script that will do the following:
- When button 1 is clicked, and sent 'R' once, it should write back "1" back to Arduino
- When button 2 is clicked, and sent 'G' once, it should write back "2" back to Arduino
- When button 3 is clicked, and sent 'B' once, it should write back "3" back to Arduino

5. Response time should be < 1 second when button is clicked.

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
