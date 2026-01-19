// Midterms Laboratory Exam - Smart Lighting System Using Arduino

#define PHOTO_PIN A0
#define GREEN_LED 11
#define YELLOW_LED 12
#define RED_LED 13

int lowThreshold = 40;
int highThreshold = 70;

bool isAutomatic = false;
String currentEnvironment = "Clear";
unsigned long previousMillis = 0;

int readLightPercentage() {
  int sensorValue = analogRead(PHOTO_PIN);
  int lightPercent = map(sensorValue, 0, 1023, 0, 100);
  return lightPercent;
}

void setActiveLED(String level) {
  digitalWrite(GREEN_LED, level == "LOW" ? HIGH : LOW);
  digitalWrite(YELLOW_LED, level == "MED" ? HIGH : LOW);
  digitalWrite(RED_LED, level == "HIGH" ? HIGH : LOW);
}

void updateEnvironment(int lightPercent) {
  if (lightPercent <= 40) {
    currentEnvironment = "Cloudy";
  } 
  else if (lightPercent <= 70) {
    currentEnvironment = "Clear";
  } 
  else {
    currentEnvironment = "Clear";
  }
}

void displayStatus(int lightPercent, String activeLED) {
  Serial.print("Light Intensity: ");
  Serial.print(lightPercent);
  Serial.println("%");

  Serial.print("Current Mode: ");
  Serial.println(isAutomatic ? "Automatic" : "Manual");

  Serial.print("Active LED: ");
  Serial.println(activeLED);

  if (isAutomatic) {
    Serial.print("Environment: ");
    Serial.println(currentEnvironment);
  }

  Serial.println("----------------------");
}

void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  Serial.println("Smart Lighting System Initialized");
  Serial.println("Default mode: MANUAL");
  Serial.println("----------------------");
}

void loop() {
  int lightPercent = readLightPercentage();
  String activeLED = "";

  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    String commandUpper = command;
    commandUpper.toUpperCase();

    if (command.equalsIgnoreCase("MODE AUTO")) {
      isAutomatic = true;
      lowThreshold = 40;
      highThreshold = 70;
      Serial.println("Switched to AUTOMATIC mode. Thresholds reset to default (40% / 70%).");
    } 
    else if (command.equalsIgnoreCase("MODE MANUAL")) {
      isAutomatic = false;
      Serial.println("Switched to MANUAL mode.");
    } 
    else if (commandUpper.startsWith("SET LOW ")) {
    if (isAutomatic) {
        Serial.println("Error: Cannot change thresholds in AUTOMATIC mode.");
    } else {
        int newLow = command.substring(8).toInt();
        if (newLow < 0 || newLow > 100) {
            Serial.println("Error: Low threshold must be between 0 and 100%");
        } else if (newLow >= highThreshold) {
            Serial.println("Error: Low threshold must be less than High threshold (" + String(highThreshold) + "%)");
        } else {
            lowThreshold = newLow;
            Serial.print("Low threshold set to ");
            Serial.print(lowThreshold);
            Serial.println("%");
        }
    }
} 
else if (commandUpper.startsWith("SET HIGH ")) {
    if (isAutomatic) {
        Serial.println("Error: Cannot change thresholds in AUTOMATIC mode.");
    } else {
        int newHigh = command.substring(9).toInt();
        if (newHigh < 0 || newHigh > 100) {
            Serial.println("Error: High threshold must be between 0 and 100%");
        } else if (newHigh <= lowThreshold) {
            Serial.println("Error: High threshold must be greater than Low threshold (" + String(lowThreshold) + "%)");
        } else {
            highThreshold = newHigh;
            Serial.print("High threshold set to ");
            Serial.print(highThreshold);
            Serial.println("%");
        }
    }
}
    else {
      Serial.println("Error: Wrong command");
    }
  }

  if (isAutomatic) {
    updateEnvironment(lightPercent);
  }

  if (lightPercent <= lowThreshold) {
    setActiveLED("LOW");
    activeLED = "Green";
  } 
  else if (lightPercent <= highThreshold) {
    setActiveLED("MED");
    activeLED = "Yellow";
  } 
  else {
    setActiveLED("HIGH");
    activeLED = "Red";
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    displayStatus(lightPercent, activeLED);
  }
}
