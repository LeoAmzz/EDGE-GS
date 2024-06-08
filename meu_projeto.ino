#include <Servo.h>
const int trigPin = 12;
const int echoPin = 11;
long   duration;
int distance;
Servo s1;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  s1.attach(9);
}

void   loop() {
  for (int i = 0; i < 180; i = i + 1) {
    s1.write(i);
    delay(30);
    distance = calDist();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
  for (int i = 180; i > 0; i = i - 1) {
    s1.write(i);
    delay(30);
    distance = calDist();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calDist() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,   LOW);
  duration =   pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
