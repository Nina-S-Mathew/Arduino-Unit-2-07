/* Created by Nina Mathew on April 5, 2022
*/
#include <Servo.h>
Servo servo1;
int trigPin = 7;
int echoPin = 3;
long distance;
long duration;
 
void setup() 
{
servo1.attach(5); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);// put your setup code here, to run once:
}
 
void loop() {
  ultra();
  servo1.write(0);
  if(distance < 50){
  servo1.write(180);
  }
  else if (distance>50){
    delay(4000);
  }
}
 
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  }
