#include "BluetoothSerial.h"
#define ledPowerPin 4
BluetoothSerial serialBT;
char cmd;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  serialBT.begin("Esp32-BT");
  pinMode(ledPowerPin,OUTPUT);
  digitalWrite(ledPowerPin, HIGH);
  delay(3000);
  digitalWrite(ledPowerPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(serialBT.available()){
    cmd = serialBT.read();
    Serial.print("Command: ");
    Serial.println(cmd);
    if(cmd == '1'){
      digitalWrite(ledPowerPin, HIGH);
    }
    if(cmd == '0'){
      digitalWrite(ledPowerPin, LOW);
    }
  }
  else {
//    Serial.println("No serial Command Received or serialBT unavaialable");
  Serial.print(".");
  }
  delay(20);
}
