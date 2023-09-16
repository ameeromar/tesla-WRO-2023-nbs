#include <Servo.h>
char c;

Servo servo1;
int servoPin = 9;

const int leftUltrasonicTrigPin = 2;
const int leftUltrasonicEchoPin = 3;

const int rightUltrasonicTrigPin = 4;
const int rightUltrasonicEchoPin = 5;

const int frontUltrasonicTrigPin = 6;
const int frontUltrasonicEchoPin = 7;

const int motorEnablePin = 10;
const int motorInput1 = 11;
const int motorInput2 = 12;

void setup() {
  servo1.attach(servoPin);
  Serial.begin(9600);


  pinMode(leftUltrasonicTrigPin, OUTPUT);
  pinMode(leftUltrasonicEchoPin, INPUT);
  
  pinMode(rightUltrasonicTrigPin, OUTPUT);
  pinMode(rightUltrasonicEchoPin, INPUT);
  
  pinMode(frontUltrasonicTrigPin, OUTPUT);
  pinMode(frontUltrasonicEchoPin, INPUT);

  pinMode(motorEnablePin, OUTPUT);
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);

  servo1.write(90);
  delay(1000);
}
void loop()
{
  if(Serial.available()&gt;0)   
  {
  c=Serial.read();
  
  long leftDistance = measureDistance(leftUltrasonicTrigPin, leftUltrasonicEchoPin);
  long rightDistance = measureDistance(rightUltrasonicTrigPin, rightUltrasonicEchoPin);
  long frontDistance = measureDistance(frontUltrasonicTrigPin, frontUltrasonicEchoPin);

  if (leftDistance > 60 && frontDistance <= 30) 
  {
      // Turn left
      digitalWrite(motorInput1, HIGH);   // Move forward
      digitalWrite(motorInput2, LOW);
      analogWrite(motorEnablePin, 200);
      servo1.write(45);
      delay(500);  
      servo1.write(90);  
      delay(500);
  }
  else if (frontDistance <= 30 && leftDistance > 60  )
  {
      digitalWrite(motorInput1, HIGH);   // Move forward
      digitalWrite(motorInput2, LOW);
      analogWrite(motorEnablePin, 200);
      servo1.write(135);
      delay(500); 
      servo1.write(90);
      delay(500);
  }
  else
  {
    servo1.write(90);
    
    digitalWrite(motorInput1, HIGH);   // Move forward
    digitalWrite(motorInput2, LOW);
    analogWrite(motorEnablePin, 220);
  }
  
  {
  if(c=='r')
    {
    delay(1000);
    Serial.print("red");
    digitalWrite(motorInput1, HIGH);   // Move forward
    digitalWrite(motorInput2, LOW);
    analogWrite(motorEnablePin, 200);
    servo1.write(45);
    delay(300); 
    servo1.write(90);
    delay(200);
    servo1.write(135);
    delay(300);
    }
  if(c=='g')
    {
    delay(1000);
    Serial.print("green");
    digitalWrite(motorInput1, HIGH);   // Move forward
    digitalWrite(motorInput2, LOW);
    analogWrite(motorEnablePin, 200);
    servo1.write(135);
    delay(300); 
    servo1.write(90);
    delay(300);
    servo1.write(45);
    delay(300);
    }
  }

  delay(1000); 
}
}
long measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}
