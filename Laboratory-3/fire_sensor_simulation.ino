// ---------------------------
// Fire Sensor System
// ---------------------------

// --- Pin Naming ---
#define THERMISTOR A0
#define PHOTORESISTOR A2
#define ALERT 12   // LED + buzzer pin

// --- Thresholds & Constants ---
const int TEMP_THRESHOLD = 50;      
const int BRIGHT_THRESHOLD = 220;    
const int BETA = 3950;               
const int RESISTANCE = 10;            


void setup() {
  Serial.begin(9600);
  pinMode(ALERT, OUTPUT);
  Serial.println("=== FIRE SENSOR SYSTEM STARTING ===");
  delay(1000);
  Serial.println("------------------------------------------------------------");
  Serial.println("Temperature (°C)\tBrightness\t");
  Serial.println("------------------------------------------------------------");
}


// ---------------------------
// FUNCTIONS
// ---------------------------

// Function to read and convert thermistor value into Celsius
float readTemperature() {
  int analogValue = analogRead(THERMISTOR);

    float temperatureC= BETA / (log((1023.0 * RESISTANCE / analogValue - RESISTANCE) / RESISTANCE) + BETA / 298.0) - 273.0;

  
  return temperatureC;
}

// Function to read photoresistor brightness value (analog)
int readBrightness() {
  int rawBrightness = analogRead(PHOTORESISTOR);
  int Brightness =map(rawBrightness,0,1023,0,255);
  return Brightness;
  

}



void loop() {
  // --- Sensor Readings ---
  float temperature = readTemperature();
  int Brightness = readBrightness();               // analog light reading (0–1023)

 
  // --- Display Readings ---
  Serial.print(temperature, 2);      // print temperature with 2 decimal places
  Serial.print("°C\t\t");
  Serial.print(Brightness); 
  Serial.print("\t\t");      // print actual photoresistor value
  
 // --- Fire Detection Logic ---

  if (temperature >= TEMP_THRESHOLD && Brightness >= BRIGHT_THRESHOLD) {
    Serial.println("FIRE DETECTED!");
    digitalWrite(ALERT, HIGH);
    delay(100);
    digitalWrite(ALERT, LOW);
    delay(100);
  } else {
    Serial.println("No Fire");
    digitalWrite(ALERT, LOW);
    delay(500);
  }
}

// Code has been updated based on what has been checked during class. Thank you so much.
