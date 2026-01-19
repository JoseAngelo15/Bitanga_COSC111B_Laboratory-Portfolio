int p8=5;
int p12=6;
int LedPINS[] = {p12,11,10,9,p8};

void setup() {
  int i = 0;
  while (i < 5) {
    pinMode(LedPINS[i], OUTPUT);
    i++;
  }
}

void loop() {
  int x = 0;

  // Fade ON from pin 12 to 8
  while (x < 5) {
    int brightness = 0;
    while (brightness <= 255) {
      analogWrite(LedPINS[x], brightness);
      delay(5); // small delay for fading effect smoothness
      brightness++;
    }
    delay(1000); // 1 second delay after each LED fully on
    x++;
  }

  int y = 0;
  
  // Fade OFF from pin 12 to 8
  while (y < 5) {
    int brightness = 255;
    while (brightness >= 0) {
      analogWrite(LedPINS[y], brightness);
      delay(5); // small fade delay
      brightness--;
    }
    delay(1000); // 1 second delay after each LED fully off
    y++;
  }
}
