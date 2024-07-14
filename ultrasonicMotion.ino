const int pinBuzzer =4; //define pins
const int  pinTrig = 33;
const int pinEcho= 32;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200); //initialize serial communication
pinMode(pinTrig,OUTPUT);
pinMode(pinEcho,INPUT);
pinMode(pinBuzzer,OUTPUT);
}
void loop(){
  // put your main code here, to run repeatedly:
digitalWrite(pinTrig,LOW);//trigger ultrasonic sound
delayMicroseconds(2);
digitalWrite(pinTrig,HIGH);
delayMicroseconds(10);
digitalWrite(pinTrig,LOW);
//read echo timne
long duration = pulseIn(pinEcho,HIGH);
//calculate distance in meters
int distance = duration * 0.034/2;
//print the distance for debugging purposes
Serial.print("Distance: ");
Serial.println(distance);
//determine buzzer frequency based on distance
int frequency;
if (distance<=10){
  frequency=2000; //highest frequency when distance<=10cm
}else if(distance<=20){
  frequency= 1500;
}else if(distance<=30){
  frequency= 1000;
}else if(distance<=40){
  frequency= 750;
}else if(distance<=50){
  frequency= 500;
}else if (distance >= 70){
  frequency =0; //no sound if the distance> 50cm
}
//Generate the beep sound
if(frequency>0){
  tone(pinBuzzer,frequency);
}else{
  noTone(pinBuzzer);
}
delay(1000);
}
