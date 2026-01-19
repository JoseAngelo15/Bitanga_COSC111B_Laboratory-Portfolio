# Laboratory Activity #3: Working with Sensors (Fire Detection System)

## 📖 Project Overview
This project, created for **Laboratory Activity #3**, simulates a **Fire Detection System** using an Arduino. It integrates two distinct analog sensors—a **Thermistor** (temperature) and a **Photoresistor** (light)—to detect hazardous conditions.

The system uses specific threshold logic: an alarm (LED & Buzzer) is triggered **only** if the temperature exceeds 50°C **AND** the light level indicates a fire (Brightness value ≥ 220).

## 🎯 Objectives
* Familiarize students with the basic sensor components that can be used in IoT
* Integrate these sensor components in an Arduino circuit
* Create a simple implementation of a fire sensor

## 🛠️ Hardware & Tech Stack
* **Microcontroller:** Arduino Uno
* **Sensors:**
    * **Thermistor (NTC):** Used to measure temperature changes.
    * **Photoresistor (LDR):** Used to detect light intensity.
* **Output:**
    * Red LED (Visual Alarm)
    * Buzzer (Audible Alarm - Optional integration on same pin)
* **Resistors:** 10k Ω (for sensor voltage dividers).

## 🔌 Circuit & Wiring Details
The system utilizes the Analog-to-Digital Converter (ADC) pins for the sensors and a Digital PWM pin for the output.

| Component | Arduino Pin | Type | Notes |
| :--- | :--- | :--- | :--- |
| **Thermistor** | `A0` | Input | Uses voltage divider circuit |
| **Photoresistor** | `A2` | Input | Uses voltage divider circuit |
| **Alert (LED/Buzzer)**| `Pin 12` | Output | Active HIGH triggers alarm |

## 💡 How It Works (The Logic)
The firmware (`fire_sensor_simulation.ino`) is structured using **modular functions** rather than a cluttered `loop`.

1.  **Definitions:** We used `#define` for pin mapping and `const` for thresholds (`TEMP_THRESHOLD = 50`, `BRIGHT_THRESHOLD = 220`) to make the code easy to tune.
2.  **`readTemperature()`:** Reads the raw analog data from A0 and converts it to Celsius using the **Beta Parameter Equation** (Steinhart-Hart simplification) for accurate NTC thermistor readings.
3.  **`readBrightness()`:** Reads the raw analog data from A2 (0-1023) and maps it to a standard byte range (0-255) using the `map()` function.
4.  **`loop()` (Decision Making):**
    * It constantly monitors both sensors.
    * **IF** Temperature > 50°C **AND** Brightness > 220:
        * Triggers a **Fast Blink** (100ms delay) on Pin 12 to signal immediate danger.
    * **ELSE**:
        * Keeps the system quiet and prints "No Fire" to the Serial Monitor.

## 📸 Breadboard Diagram

<img width="1707" height="728" alt="Bitanga_Olano_Paciente_Breadboard_diagram" src="https://github.com/JoseAngelo15/Bitanga_COSC111_Laboratory-Portfolio/blob/main/LabAct3/Breadboard%20Diagram%20for%20Lab%20Act%20%233.png" />

## 🧠 Key Learnings
In this activity, our team learned:
1.  **Sensor Fusion:** We learned how to combine data from two different environmental sources (Heat + Light) to create a more reliable trigger condition, reducing false alarms.
2.  **Modular Programming:** By strictly separating `readTemperature()` and `readBrightness()` into their own functions, we improved code readability and debugging efficiency.
3.  **Analog Processing:** We gained experience in converting raw voltage values (0-1023) into human-readable units (Celsius) using mathematical formulas within C++.
4.  **Hardware Constants:** We practiced using `#define` and `const` variables. This makes the code "maintainable"—if we need to change a pin or threshold later, we only change it in one place at the top of the file.

## 👥 Team Members
**Leader:**
* Gwen Marinie C. Paciente

**Members:**
* Jose Angelo B. Bitanga
* John Robert L. Olaño

---
### 📂 Code Snippet
*Temperature Conversion Logic Used:*
```cpp
float readTemperature() {
  int analogValue = analogRead(THERMISTOR);
  // Beta Parameter Equation for NTC Thermistor
  float temperatureC = BETA / (log((1023.0 * RESISTANCE / analogValue - RESISTANCE) / RESISTANCE) + BETA / 298.0) - 273.0;
  return temperatureC;
}
