//https://create.arduino.cc/projecthub/Ayeon0122/reading-a-photoresistor-1e705e
//https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
int sensorPin = A1;   // select the analog input pin for the photoresistor

//Ultrasonic sensor code
const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

void setup() {
  Serial.begin(9600);
//    for ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
//  Serial.println(analogRead(sensorPin));
  Serial.print(analogRead(sensorPin));
  Serial.print('|');
  delay(200);
  
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
}
