// ---------------------------
// Serial Controlled Photoresistor System
// ---------------------------

// --- Pin Naming ---
#define PHOTORESISTOR A0
#define LED 8

// --- Threshold ---
const int BRIGHT_THRESHOLD = 220;   

// --- Control Variables ---
bool isBlinking = false;    // Tracks if LED should blink


void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.println("=== SERIAL CONTROLLED PHOTORESISTOR SYSTEM ===");
  Serial.println("Type 'stop' to stop LED blinking.");
  Serial.println("----------------------------------------------");
  delay(1000);
}

// ---------------------------
// FUNCTIONS
// ---------------------------

// Function to read photoresistor brightness value
int readBrightness() {
  int rawBrightness = analogRead(PHOTORESISTOR);
  int brightness = map(rawBrightness, 0, 1023, 0, 255);
  return brightness;
}

// ---------------------------
// MAIN LOOP
// ---------------------------
void loop() {
  // --- Read sensor value ---
  int brightness = readBrightness();
  Serial.print("Current Brightness: ");
  Serial.println(brightness);
  delay(100);

  // --- Check threshold ---
  if (brightness >= BRIGHT_THRESHOLD && !isBlinking) {
    isBlinking = true;
    Serial.println("Threshold reached! LED will start blinking.");
  }

  // --- Handle Serial Input ---
  if (Serial.available()) {
    String inputString = Serial.readStringUntil('\n');  // Read until newline
    inputString.trim();                                 // Remove spaces/newlines
    inputString.toLowerCase();                          // Make input lowercase

    if (inputString == "stop") {
      isBlinking = false;
      digitalWrite(LED, LOW);
      Serial.println("Blinking stopped.");
    }
  }

  // --- Blink LED if Active ---
  if (isBlinking) {
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
  } else {
    delay(100); 
  }
}
