#include <SoftwareSerial.h>

const int joystickXPin = A0;
const int joystickYPin = A1;

const int bluetoothTx = 2;
const int bluetoothRx = 3;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

const int centerThreshold = 512;
const int deadZone = 50;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(joystickXPin, INPUT);
  pinMode(joystickYPin, INPUT);
}

void loop() {
  int joystickXValue = analogRead(joystickXPin);
  int joystickYValue = analogRead(joystickYPin);

  if (joystickYValue > (centerThreshold + deadZone)) {
    bluetooth.println("F");
    Serial.println("Sending: F (Forward)");
  } else if (joystickYValue < (centerThreshold - deadZone)) {
    bluetooth.println("B");
    Serial.println("Sending: B (Backward)");
  } else if (joystickXValue > (centerThreshold + deadZone)) {
    bluetooth.println("R");
    Serial.println("Sending: R (Right)");
  } else if (joystickXValue < (centerThreshold - deadZone)) {
    bluetooth.println("L");
    Serial.println("Sending: L (Left)");
  } else {
    bluetooth.println("T");
    Serial.println("Sending: T (Stop)");
  }

  delay(100);
}
