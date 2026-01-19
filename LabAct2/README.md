# Laboratory Activity #2: Working with Analog Signal

## 📖 Project Overview
The **Laboratory Activity #2** which builds upon the logic of the previous activity but introduces **Analog Signals** and **Pulse Width Modulation (PWM)**. 

Instead of simply turning LEDs on and off, this system uses `analogWrite()` to create a smooth "breathing" or fading effect. The logic is implemented using **Arrays** and **`while` loops** to manage the sequence and pin configurations efficiently.

## 🎯 Objectives
* Discuss analog signals and its implementation in a Arduino circuit.
* Understand analog to digital signal conversion using the map() function.

## 🛠️ Hardware & Tech Stack
* **Microcontroller:** Arduino Uno
* **Components:**
    * 5x LEDs
    * Breadboard & Jumper Wires
* **Language:** C++ (Arduino)

## 🔌 Circuit & Wiring Details
**Important Note on PWM:** Standard Arduino pins 8 and 12 are digital-only and do not support fading. To achieve the analog dimming effect required by the instructions, the circuit re-maps the outer LEDs to **PWM-enabled pins** (Pins 5 and 6).

| LED Position | Variable Name | Actual Arduino Pin (PWM) |
| :--- | :--- | :--- |
| LED 1 (Start) | `p12` | **Pin 6** |
| LED 2 | - | **Pin 11** |
| LED 3 | - | **Pin 10** |
| LED 4 | - | **Pin 9** |
| LED 5 (End) | `p8` | **Pin 5** |

## 💡 How It Works (The Logic)
The firmware uses a nested `while` loop structure to control the sequence:

1.  **Pin Configuration (Setup):**
    * An array `LedPINS[]` holds the pin numbers `{6, 11, 10, 9, 5}`.
    * A `while` loop iterates through this array to set all pins as `OUTPUT`.

2.  **Fading Sequence (Loop):**
    * **Fade ON:** The code iterates through the array. For each LED, a nested `while` loop increases brightness from 0 to 255 (Max) with a short delay (5ms) to create a smooth fade-in effect.
    * **Hold:** Once fully lit, the LED stays on for 1 second.
    * **Fade OFF:** After the sequence completes, a second loop reverses the process, fading LEDs from 255 down to 0.

## 📸 Breadboard Diagram

<img width="1707" height="728" alt="Bitanga_Olano_Paciente_Breadboard_diagram" src="https://github.com/JoseAngelo15/Bitanga_COSC111_Laboratory-Portfolio/blob/main/LabAct2/Breadboard%20Diagram%20for%20Lab%20Act%20%232.png" />

## 🧠 Key Learnings
In completing this activity, our group learned:
1.  **Pulse Width Modulation (PWM):** We learned that `analogWrite()` simulates analog voltages by rapidly toggling the pin on and off, allowing us to control LED brightness (0-255 range) rather than just binary on/off states.
2.  **Hardware Constraints:** We discovered that not all digital pins support analog output. We had to utilize **PWM pins** (marked with `~` on the board) to make the fading effect work.
3.  **Arrays & Loops:** We moved away from repetitive code by using **Arrays** to store pin numbers and **`while` loops** to iterate through them. This made our code cleaner and easier to modify than writing individual commands for every pin.
4.  **Nested Logic:** We implemented "loops inside loops"—an outer loop to select the LED, and an inner loop to increment the brightness values.

## 👥 Team Members
**Leader:**
* John Robert L. Olaño

**Members:**
* Jose Angelo B. Bitanga
* Gwen Marinie C. Paciente

---
### 📂 Code Snippet
*For a quick view of the logic implemented:*
```cpp
// Array Setup
int p8=5;
int p12=6;
int LedPINS[] = {p12,11,10,9,p8};

// Example of Fading Logic
while (brightness <= 255) {
  analogWrite(LedPINS[x], brightness);
  delay(5); 
  brightness++;
}
