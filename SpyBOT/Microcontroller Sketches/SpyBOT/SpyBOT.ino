#include <BluetoothSerial.h>
#include <ESP32Servo.h>
#include <Motor.h>
#include <analogWrite.h>

#define e1 14
#define m11 32
#define m12 33
#define m21 25
#define m22 26
#define e2 27

#define e3 4
#define m31 16
#define m32 17
#define m41 5
#define m42 18
#define e4 19

#define servoPin 13

BluetoothSerial rx;
Servo camServo;


Motor m1(e1, m11, m12);
Motor m2(e2, m21, m22);
Motor m3(e3, m31, m32);
Motor m4(e4, m41, m42);

void setup() {
  m1.Setup();
  m2.Setup();
  m3.Setup();
  m4.Setup();

  m1.SetSpeed(0);
  m2.SetSpeed(0);
  m3.SetSpeed(0);
  m4.SetSpeed(0);
  camServo.attach(servoPin);
  Serial.begin(115200);
  rx.begin(); 

}

void loop() {
  if (rx.available()){
   String msg = rx.readStringUntil('\n');  
   String strs[6];
    int StringCount=0;
      while (msg.length() > 0)
  {
    int index = msg.indexOf(' ');
    if (index == -1) // No space found
    {
      strs[StringCount++] = msg;
      break;
    }
    else
    {
      strs[StringCount++] = msg.substring(0, index);
      msg = msg.substring(index+1);
    }
  }
  m1.SetSpeed(strs[0].toInt());
  m2.SetSpeed(strs[1].toInt());
  m3.SetSpeed(strs[2].toInt());
  m4.SetSpeed(strs[3].toInt());

  camServo.write(strs[4].toInt());
  }
  else{
    m1.SetSpeed(0);
    m2.SetSpeed(0);
    m3.SetSpeed(0);
    m4.SetSpeed(0);
  }

}
