#include <Servo.h>  // Include the Servo library

Servo s1;  // Define Servo object s1
Servo s2;  // Define Servo object s2
Servo s3;  // Define Servo object s3
Servo s4;  // Define Servo object s4

long soundTime;  // Variable to store sound time
int distance;    // Variable to store distance
const int trigPin = 10;  // Define trigger pin
const int echoPin = 11;  // Define echo pin

int deg = 0;  // Initialize deg variable to 0

int pickup = 0;          // Variable for pickup action
int rotate_servo = 1;    // Variable for servo rotation action

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
  s1.attach(3);  // Attach servo s1 to pin 3
  s2.attach(5);  // Attach servo s2 to pin 5
  s3.attach(6);  // Attach servo s3 to pin 6
  s4.attach(9);  // Attach servo s4 to pin 9

  pinMode(trigPin, OUTPUT);  // Set trigPin as output
  pinMode(echoPin, INPUT);   // Set echoPin as input
}

void loop() {
  Serial.println("Start");  // Print "Start" message
  delay(3000);  // Delay for 3000 milliseconds

  // Starting up servos initial position
  deg = 0;  // Reset deg variable to 0
  turnSlow(s1, 0);   // Turn servo s1 to default angle 0 (front)
  turnSlow(s2, 90);  // Turn servo s2 to default angle 90 (up)
  turnSlow(s3, 90);  // Turn servo s3 to default angle 90 (up)
  turnSlow(s4, 90);  // Turn servo s4 to default angle 90 (front)

  if (rotate_servo == 1) {  // Condition for servo rotation
    Serial.println("before while");  // Print "before while" message
    while (deg <= 180) {  // Loop until deg is less than or equal to 180
      // Measure distance using ultrasonic sensor
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      soundTime = pulseIn(echoPin, HIGH);
      distance = soundTime * 0.034 / 2;
      Serial.print("distance: ");
      Serial.println(distance);  // Print distance
      
      if (distance < 8) {  // Condition for pickup action
        Serial.println("pickup");  // Print "pickup" message
        pickupDrop();  // Call pickupDrop function
        break;  // Exit the loop
      }
      
      deg = deg + 1;  // Increment deg by 1
      turnSlow(s1, deg);  // Turn servo s1 to deg angle
      Serial.print("deg: ");
      Serial.println(deg);  // Print deg
      if (deg == 180) {  // Condition for ending the loop
        break;  // Exit the loop
      }
    }
    Serial.println("after while");  // Print "after while" message
  }

  // Reset position of servos
  Serial.println("reset position");  // Print "reset position" message
  turnSlow(s3, 90);  // Turn servo s3 to default angle 90 (up)
  turnSlow(s2, 90);  // Turn servo s2 to default angle 90 (up)
  turnSlow(s1, 0);   // Turn servo s1 to default angle 0 (front)
  turnSlow(s4, 90);  // Turn servo s4 to default angle 90 (front)
} 

void pickupDrop() {
    // Pickup action
    turnSlow(s3, 0);   // Turn servo s3 to 0 degrees
    turnSlow(s2, 142); // Turn servo s2 to 142 degrees
    turnSlow(s4, 35);  // Turn servo s4 to 35 degrees

    // Drop action
    turnSlow(s2, 125);  // Turn servo s2 to 125 degrees
    turnSlow(s3, 45);   // Turn servo s3 to 45 degrees
    turnSlow(s1, 0);    // Turn servo s1 to 0 degrees
    turnSlow(s4, 115);  // Turn servo s4 to 115 degrees
}

void turnSlow(Servo servo, int angle) {
  int currentAngle = servo.read();  // Read current angle of the servo

  // Turn servo to the desired angle slowly
  if (currentAngle < angle) {  // If current angle is less than desired angle
    while (currentAngle < angle) {  // Loop until current angle is less than desired angle
      servo.write(currentAngle + 1);  // Increment angle by 1
      delay(15);  // Delay for smooth movement
      currentAngle = servo.read();  // Read current angle
    }
    servo.write(angle);  // Set servo to the desired angle
  }
  
  if (currentAngle > angle) {  // If current angle is greater than desired angle
    while (currentAngle > angle) {  // Loop until current angle is greater than desired angle
      servo.write(currentAngle - 1);  // Decrement angle by 1
      delay(15);  // Delay for smooth movement
      currentAngle = servo.read();  // Read current angle
    }
    servo.write(angle);  // Set servo to the desired angle
  }
}