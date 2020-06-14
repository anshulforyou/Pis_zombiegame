#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11); 
int ledpin1=13;
int ledpin2=4; 
int Data;
int Sensorvalue; 

int sensorPin = A0;   // select the analog input pin for the photoresistor

//Ultrasonic sensor code
const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

void setup() {
  Serial.begin(9600);
//    for ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
//  for bluetooth sensor
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
}

void loop() {
//  Serial.println(analogRead(sensorPin));
  Serial.print(analogRead(sensorPin));
  Serial.print('|');
  delay(200);

  if (mySerial.available())
  {
    Data=mySerial.read();
    if(Data=='1')
    {
      digitalWrite(ledpin1,HIGH);
    }
    else if(Data == '2')
    {
      digitalWrite(ledpin2,HIGH);
    }
    else if(Data == '0')
    {
      digitalWrite(ledpin1,LOW);
      digitalWrite(ledpin2,LOW);
    }
  }
  //    for ultrasonic sensor 
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;

//    Serial.print("Distance: ");
//  if (distance > 1200){
//    Serial.print('LOW');
//  }
//  else {
//    Serial.print('HIGH');
//  }
    
  Serial.print(distance);
  Serial.print('|');
//    delay(200);


  //Write on Bluetooth
  Sensorvalue = analogRead(A1);
  mySerial.println(Sensorvalue);
  mySerial.flush();
  delay(100);
}
