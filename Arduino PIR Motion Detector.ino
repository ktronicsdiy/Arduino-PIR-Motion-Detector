/*
 PIR Sensor Detection

 This example demonstrates the use of PIR sensor. It sends a
 digital input on pin 2 when a person or object passes infront 
 of it and rings the buzzer while lighting up the red LED. 
 It also prints a message to the serial monitor.
 
 OPEN THE SERIAL MONITOR TO SEE THE OUTPUT >>

 The circuit:
 * PIR sensor on pin 2
 * LED and Buzzer on pin 13

 created 10 February 2022
 by KtroniksDIY

 */
const int buzzer = 13;
const int sensor = 2;
int state = LOW;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  val = digitalRead(sensor);
  if (val==HIGH){
    digitalWrite(buzzer, HIGH);
    delay(500);
    if (state ==LOW){
      state = HIGH;
      Serial.println("Motion detected!!!");
    }
  }
  else {
    digitalWrite(buzzer, LOW);
    delay(500);
    if (state == HIGH) {
      Serial.println("Motion as stopped.");
      state = LOW;
    }
  }
}
