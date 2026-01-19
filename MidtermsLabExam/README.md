# Midterms Laboratory Exam: Smart Lighting System Using Arduino

## 📖 Project Overview
This **Midterm Laboratory Exam** shows the implementation of a **Smart Lighting System**. The system utilizes a **Photoresistor** to measure ambient light intensity and intelligently controls a traffic-light style LED display (Green, Yellow, Red) based on environmental conditions.

The system features two distinct operational modes:
1.  **Manual Mode:** Allows the user to define custom light thresholds via Serial commands.
2.  **Automatic Mode:** Simulates environmental awareness (Cloudy/Clear) and locks thresholds to preset values.

## 🎯 Objectives
* To read and process analog sensor data from a Photoresistor (LDR).
* To implement a **State Machine** that switches between Manual and Automatic modes.
* To parse complex Serial strings (e.g., `SET LOW 45`) for dynamic system configuration.
* To utilize non-blocking timing (`millis()`) for status updates.

## 🛠️ Hardware & Tech Stack
* **Microcontroller:** Arduino Uno
* **Sensor:** Photoresistor (LDR) + 10kΩ Resistor (Voltage Divider)
* **Indicators:**
    * Green LED (Low Light)
    * Yellow LED (Medium Light)
    * Red LED (High Light)
* **Resistors:** 220Ω (for LEDs)

## 🔌 Circuit & Wiring Details
The system connects the sensor to the Analog-to-Digital Converter (ADC) and the LEDs to digital outputs.

| Component | Arduino Pin | Function |
| :--- | :--- | :--- |
| **Photoresistor** | `A0` | Light Sensor Input (0-1023) |
| **Green LED** | `Pin 11` | Indicates LOW Light Level |
| **Yellow LED** | `Pin 12` | Indicates MEDIUM Light Level |
| **Red LED** | `Pin 13` | Indicates HIGH Light Level |

## 💡 System Logic & Modes

### 1. The Logic (Thresholds)
The system maps the raw sensor data (0-1023) to a percentage (0-100%).
* **Green LED (ON):** Light % ≤ `Low Threshold`
* **Yellow LED (ON):** `Low Threshold` < Light % ≤ `High Threshold`
* **Red LED (ON):** Light % > `High Threshold`

### 2. Operational Modes
* **Manual Mode (Default):**
    * User has full control.
    * Thresholds can be adjusted using `SET LOW` and `SET HIGH` commands.
* **Automatic Mode:**
    * System simulates "Environment Detection" (Cloudy vs. Clear).
    * Thresholds are **locked** to standard values (Low: 40%, High: 70%).
    * User attempts to change thresholds will be rejected with an error.

## 💻 Serial Command List
The system accepts the following case-insensitive commands via the Serial Monitor:

| Command | Description | Example |
| :--- | :--- | :--- |
| `MODE AUTO` | Switches system to Automatic Mode. | `MODE AUTO` |
| `MODE MANUAL` | Switches system to Manual Mode. | `MODE MANUAL` |
| `SET LOW <value>` | Sets the lower threshold (Manual only). | `SET LOW 30` |
| `SET HIGH <value>` | Sets the upper threshold (Manual only). | `SET HIGH 80` |

> **Note:** The system prints a status report every **1 second** (using non-blocking `millis` delay).

## 🧠 Key Learnings
In completing this exam, our team demonstrated proficiency in:
1.  **Advanced String Parsing:** We learned how to process user input using `.startsWith()`, `.substring()`, and `.toInt()` to extract specific numerical values from text commands.
2.  **Input Validation:** We implemented logic to prevent user errors, such as setting a "Low Threshold" that is higher than the "High Threshold."
3.  **Non-Blocking Code:** Instead of using `delay(1000)` which freezes the system, we used `millis()` to print status updates. This ensures the system remains responsive to user commands at all times.
4.  **Dynamic Thresholding:** We learned how to make a system adaptable, allowing variables (thresholds) to be changed during runtime rather than hard-coding them.

## 👥 Team Members
**Team Leader:**
* Gerard Obey S. Francisco

**Members:**
* Merell Joy B. Barrion
* Jose Angelo B. Bitanga
* Maureen T. Roldan
* John Mark L. Serrona

---
### 📂 Code Snippet
*Command Parsing Logic Used:*
```cpp
if (commandUpper.startsWith("SET LOW ")) {
    if (isAutomatic) {
        Serial.println("Error: Cannot change thresholds in AUTOMATIC mode.");
    } else {
        int newLow = command.substring(8).toInt(); // Extract number after "SET LOW "
        // Validation Logic
        if (newLow >= highThreshold) {
             Serial.println("Error: Low threshold must be less than High threshold.");
        } else {
             lowThreshold = newLow;
        }
    }
}
