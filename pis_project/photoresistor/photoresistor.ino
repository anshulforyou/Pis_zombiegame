//https://create.arduino.cc/projecthub/Ayeon0122/reading-a-photoresistor-1e705e
const int sensorPin =0;

int lightCal;
int lightVal;

void setup()
{
  lightCal = analogRead(sensorPin);
}

void loop()
{
  //Take a reading using analogRead() on sensor pin and store it in lightVal
  lightVal = analogRead(sensorPin);
  Serial.print(lightVal);

  //if lightVal is less than our initial reading (lightCal) minus 50 it is dark and
  //turn pin 9 HIGH. The (-50) part of the statement sets the sensitivity. The smaller
  //the number the more sensitive the circuit will be to variances in light.
//  if (lightVal < lightCal - 50)
//  {
//    digitalWrite(9, HIGH);
//  }
//
//  //else, it is bright, turn pin 9 LOW
//  else
//  {
//    digitalWrite(9, LOW);
//  }

}
