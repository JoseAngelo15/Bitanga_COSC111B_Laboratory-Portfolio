int Green = 12;
int Yellow = 11;
int Orange = 10;
int Blue = 9;
int Red = 8;

void setup(){
  // The OUTPUT function serves as a voltage signal from the Arduino board to the LED 
  pinMode (Green, OUTPUT);
  pinMode (Yellow, OUTPUT);
  pinMode (Orange, OUTPUT);
  pinMode (Blue, OUTPUT);
  pinMode (Red, OUTPUT);
}

void loop(){
  //HIGH means turn on the LED which it produces 5V, and LOW means to turn off the LED which it produces 0V 
  digitalWrite(Green, HIGH);
  delay (1000); // 1 second = 1000 milliseconds
  digitalWrite(Yellow, HIGH);
  delay (1000);
  digitalWrite(Orange, HIGH);
  delay (1000);
  digitalWrite(Blue, HIGH);
  delay (1000);
  digitalWrite(Red, HIGH);
  delay (1000);
  digitalWrite(Green, LOW);
  delay (1000);
  digitalWrite(Yellow, LOW);
  delay (1000);
  digitalWrite(Orange, LOW);
  delay (1000);
  digitalWrite(Blue, LOW);
  delay (1000);
  digitalWrite(Red, LOW);
  delay (1000);
}
//Reference:https://www.youtube.com/watch?v=e1FVSpkw6q4
