#include <Servo.h>

Servo servo1;
int servoPin = 9;  // Pin for the servo

const int in1 = 7;  // Connect to IN1 on L298 motor driver
const int in2 = 6;  // Connect to IN2 on L298 motor driver
const int ConA = 10;  // Connect to ENA on L298 motor driver

#define trigPinLeft 2
#define echoPinLeft 3
#define trigPinFront 4
#define echoPinFront 5
#define trigPinRight 8
#define echoPinRight 11

int motorSpeed = 150;  // Adjust motor speed as needed
int leftDistance, frontDistance, rightDistance;

// Safe distances for obstacle avoidance
int safeFrontDistance = 30;
int safeTurnDistance = 60;

void setup() {
  servo1.attach(servoPin);
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Measure distances
  leftDistance = getDistance(trigPinLeft, echoPinLeft);
  frontDistance = getDistance(trigPinFront, echoPinFront);
  rightDistance = getDistance(trigPinRight, echoPinRight);

  // Obstacle avoidance logic
  obstacleAvoidance();
}

int getDistance(int trigPin, int echoPin) {
  // Function to measure distance with ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return (pulseIn(echoPin, HIGH) / 2) * 0.0343;
}

void moveForward() {
  // Code to move forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ConA, motorSpeed);
  servo1.write(90);  // Set servo to center for straight movement
}

void moveLeft() {
  // Code to turn left
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ConA, motorSpeed);
  servo1.write(45);  // Set servo to left position for turning left
}

void moveRight() {
  // Code to turn right
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ConA, motorSpeed);
  servo1.write(135);  // Set servo to right position for turning right
}

void obstacleAvoidance() {
  if (frontDistance < safeFrontDistance) {
    if (leftDistance > rightDistance) {
      moveLeft();
    } else {
      moveRight();
    }
  } else if (leftDistance > safeTurnDistance) {
    moveLeft();
  } else if (rightDistance > safeTurnDistance) {
    moveRight();
  } else {
    moveForward();
  }
}
