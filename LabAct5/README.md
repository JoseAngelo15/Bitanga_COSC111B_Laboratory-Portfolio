# Laboratory Activity #5: Receiving Serial Connection Using Arduino from Python

## 📖 Project Overview
This activity explores the **Cross-Platform Serial Communication** by interfacing a **Python script** (running on a laptop) with an **Arduino microcontroller**.

Instead of using the standard Arduino IDE Serial Monitor, we built a custom CLI (Command Line Interface) dashboard in Python. This Python script sends commands to the Arduino to control a set of LEDs, demonstrating how high-level software can control low-level hardware.

## 🎯 Objectives
* Understand and implement Arduino Serial Connection
* Utilize Python as a tool for implementing serial connection
* Create a simple circuit that can be controlled using Serial connection using Arduino and Python

## 🛠️ Hardware & Tech Stack
* **Microcontroller:** Arduino Uno
* **Software:**
    * **Arduino IDE** (Firmware)
    * **Python** (Controller Script)
    * **Library:** `pyserial` (Install via `pip install pyserial`)
* **Components:**
    * 3x LEDs (Red, Green, Blue)
    * 3x Resistors (10kΩ)
    * Breadboard & Jumper Wires

## 🔌 Circuit & Wiring Details
The LEDs are connected to digital output pins on the Arduino.

| LED Color | Arduino Pin |
| :--- | :--- |
| **Red** | `Pin 8` |
| **Green** | `Pin 9` |
| **Blue** | `Pin 10` |

## 💡 How It Works (The Logic)
The system operates in a **Looping Request-Response** cycle:

### 1. The Python Controller (`Arduino.py`)
* Displays a menu of options (Red, Green, Blue, All On/Off).
* Uses `os.system("cls")` to clear the console screen after every input for a clean UI.
* Captures user input, sanitizes it (removes spaces, converts to lowercase), and sends it to the Arduino via the Serial Port (e.g., `COM7`).

### 2. The Arduino Firmware (`.ino` + `.h`)
* **Header File (`ArduinoFromPythonHeader.h`):** To keep the main code clean, we moved all hardware logic here. It contains:
    * Pin definitions (`#define`).
    * State variables (tracking if an LED is currently ON or OFF).
    * Helper functions (`toggleRed()`, `allOn()`, etc.).
* **Main Logic:** The Arduino constantly listens to the Serial port. When it receives a character (e.g., `'r'`), it calls the corresponding function from the header file to toggle the specific LED.

## 📸 Breadboard Diagram

<img width="1707" height="728" alt="Bitanga_Olano_Paciente_Breadboard_diagram" src="https://github.com/JoseAngelo15/Bitanga_COSC111B_Laboratory-Portfolio/blob/main/LabAct5/Breadboard%20Diagram%20for%20Lab%20Act%20%235.png" />

## 🧠 Key Learnings
In this activity, our team learned:
1.  **Python-Arduino Integration:** We learned how to use the `pyserial` library to bridge the gap between high-level application software and hardware firmware.
2.  **Code Modularity (Header Files):** We practiced professional coding standards by moving our pin definitions and functions into a separate header file (`ArduinoFromPythonHeader.h`). This made the main `.ino` file much shorter and easier to read.
3.  **State Management:** We implemented logic to "remember" the state of each LED (using `bool redState`), allowing us to toggle them on/off rather than just turning them on blindly.
4.  **Data Encoding:** We learned that Python strings must be encoded (e.g., `.encode()`) into bytes before being sent over a serial connection.

## 👥 Team Members
**Leader:**
* Mark I. Sanguir

**Members:**
* Jose Angelo B. Bitanga
* John Robert L. Olaño
* Gwen Marinie C. Paciente
* Mark John Paul Pagarigan
* Rovick B. Padilla

---
### 📂 Code Snippet
*Python Serial Transmission Logic:*
```python
import serial
arduino = serial.Serial("COM7", 9600) # Open Port

# Sending Command
if user_choice in ["r", "g", "b", "a", "o", "v"]:
    arduino.write((user_choice + '\n').encode()) # Send as bytes
