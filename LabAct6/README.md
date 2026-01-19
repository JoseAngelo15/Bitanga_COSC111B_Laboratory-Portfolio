# Laboratory Activity #6: Bidirectional Control Using Arduino and Python

## 📖 Project Overview
This project demonstrates **Bidirectional Serial Communication** (Full-Duplex) between an Arduino microcontroller and a Python script.

Unlike previous activities where data flowed only one way, this system implements a **Closed-Loop Control System**:
1.  **Input:** The user presses a button on the Arduino circuit.
2.  **Process (Outbound):** Arduino detects the press and sends a request signal ('R', 'G', or 'B') to Python.
3.  **Logic (Python):** The Python script processes the request and sends a command back ('1', '2', or '3').
4.  **Output (Inbound):** Arduino receives the command and toggles the corresponding LED.

This architecture mimics real-world IoT systems where "Edge Devices" (Arduino) send data to a "Server" (Python), which then commands the device to act.

## 🎯 Objectives
* Understand and implement Arduino Serial Connection
* Utilize Python as a tool for implementing serial connection
* Create a simple circuit what will implement bi-directional connection between Arduino and Python

## 🛠️ Hardware & Tech Stack
* **Microcontroller:** Arduino Uno
* **Software:** Python 3.x (`pyserial` library), Arduino IDE
* **Components:**
    * 3x LEDs (Red, Green, Blue)
    * 3x Push Buttons
    * Resistors (Current limiting for LEDs)
    * Internal Pull-up Resistors (Enabled in software for buttons)

## 🔌 Circuit & Wiring Details
The circuit separates inputs (Buttons) and outputs (LEDs) into distinct pin groups.

| Component | Arduino Pin | Mode |
| :--- | :--- | :--- |
| **Red LED** | `Pin 7` | Output |
| **Green LED** | `Pin 6` | Output |
| **Blue LED** | `Pin 5` | Output |
| **Button 1** (Red Control) | `Pin 12` | Input (Pull-up) |
| **Button 2** (Green Control) | `Pin 11` | Input (Pull-up) |
| **Button 3** (Blue Control) | `Pin 10` | Input (Pull-up) |

## 💡 How It Works (The Logic Loop)
The system relies on a "Handshake" protocol between the two devices:

### 1. Arduino Side ( The Client)
* **Input Handling:** It monitors the buttons using **State Change Detection**. It only sends a signal when the button goes from `HIGH` to `LOW` (pressed), preventing it from spamming the serial port while the button is held down.
* **Listening:** Inside the `loop()`, it constantly checks `Serial.available()`. If it receives '1', '2', or '3', it calls the corresponding toggle function from `myFunctions.h`.

### 2. Python Side (The Server)
* **The Relay:** The script runs an infinite loop.
* **Step A:** It reads the serial line. If it sees 'R', it prints a log message and immediately sends back '1'.
* **Step B:** It flushes the buffer to ensure the command leaves the computer immediately, ensuring the **< 1 second response time** requirement is met.

## 📸 Breadboard Diagram

<img width="1707" height="728" alt="Bitanga_Olano_Paciente_Breadboard_diagram" src="https://github.com/JoseAngelo15/Bitanga_COSC111B_Laboratory-Portfolio/blob/main/LabAct6/Breadboard%20Diagram%20for%20Lab%20Act%20%236.jpeg" />
## 🧠 Key Learnings
In this activity, our team learned:
1.  **Closed-Loop Architecture:** We learned that the button didn't turn on the LED directly. The signal had to travel to the computer and back. This taught us about **latency** and the importance of efficient code to keep the delay unnoticeable.
2.  **Edge Detection:** We implemented logic to detect *when* a button is pressed (the edge), rather than *if* it is pressed (the state). This prevents the "machine gun effect" where one press sends 100 characters to Python.
3.  **Internal Pull-ups:** We used `INPUT_PULLUP` to simplify our circuit, removing the need for physical external resistors on the buttons.
4.  **Protocol Design:** We created a simple communication protocol (Chars 'R'/'G'/'B' for requests, '1'/'2'/'3' for commands) to ensure the two separate programs "understood" each other.

## 👥 Team Members
**Leader:**
* Mark John Paul Pagarigan

**Members:**
* Jose Angelo B. Bitanga
* John Robert L. Olaño
* Gwen Marinie C. Paciente
* Mark I. Sanguir
* Rovick B. Padilla

---
### 📂 Code Snippet
*The "Handshake" Logic:*

**Arduino (Sending Request):**
```cpp
// Only send 'R' if button CHANGED from High to Low
if (lastBtn1State == HIGH && currentBtn1 == LOW) {
    Serial.print("R\n"); 
}
