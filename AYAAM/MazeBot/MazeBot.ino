#include <ESP32Servo.h>
#include <BluetoothSerial.h>
#include <analogWrite.h>
#define LED_BUILTIN 2
#define p1 14
#define d11 27
#define d12 26
#define d21 25
#define d22 33
#define p2 32
#define servPin 18

BluetoothSerial rx;
Servo servo;
char t;
void setup()
{
  //put your setup code here,to run code once:
 Serial.begin(115200);
 rx.begin();
 delay(1000);
 pinMode(d11,OUTPUT);
 pinMode(p1,OUTPUT);
 pinMode(d12,OUTPUT);
 pinMode(d21,OUTPUT);
 pinMode(p2,OUTPUT);
 pinMode(d22,OUTPUT);
 servo.attach(servPin);
 servo.write(0);
 delay(1000);
}
//Go forward

void f(){
  digitalWrite(d11,HIGH);digitalWrite(d12,LOW);analogWrite(p1,255);
  digitalWrite(d21,HIGH);digitalWrite(d22,LOW);analogWrite(p2,255);
}
// Go backward
void b(){
  digitalWrite(d11,LOW);digitalWrite(d12,HIGH);analogWrite(p1,255);
  digitalWrite(d21,LOW);digitalWrite(d22,HIGH);analogWrite(p2,255);
}

void l(){
  digitalWrite(d11,HIGH);digitalWrite(d12,LOW);analogWrite(p1,255);
  digitalWrite(d21,LOW);digitalWrite(d22,HIGH);analogWrite(p2,255);
}

void r(){
  digitalWrite(d11,LOW);digitalWrite(d12,HIGH);analogWrite(p1,255);
  digitalWrite(d21,HIGH);digitalWrite(d22,LOW);analogWrite(p2,255);
}

void lf(){
  digitalWrite(d11,HIGH);digitalWrite(d12,LOW);analogWrite(p1,255);
  digitalWrite(d21,HIGH);digitalWrite(d22,LOW);analogWrite(p2,140);
}

void rf(){
  digitalWrite(d11,HIGH);digitalWrite(d12,LOW);analogWrite(p1,140);
  digitalWrite(d21,HIGH);digitalWrite(d22,LOW);analogWrite(p2,255);
}

void rb(){
  digitalWrite(d11,LOW);digitalWrite(d12,LOW);analogWrite(p1,0);
  digitalWrite(d21,LOW);digitalWrite(d22,HIGH);analogWrite(p2,255);
}

void lb(){
  digitalWrite(d11,LOW);digitalWrite(d12,HIGH);analogWrite(p1,255);
  digitalWrite(d21,LOW);digitalWrite(d22,LOW);analogWrite(p2,0);
}
void s(){
  digitalWrite(d11,LOW);digitalWrite(d12,LOW);analogWrite(p1,0);
  digitalWrite(d21,LOW);digitalWrite(d22,LOW);analogWrite(p2,0);
}
void th(){
  servo.write(150);
  delay(1000);
  servo.write(0);
}
void loop()
{
//put your main code here ,to run repeatedly:
while (rx.available())
{
  t=rx.read();
  Serial.println(t);


if (t=='F'){
  f();
}
else if (t=='B'){
  b();
}
else if (t=='L'){
  l();
}
else if (t=='R'){
  r();
}
else if (t=='G'){
  lf();
}
else if (t=='I'){
  rf();
}
else if (t=='H'){
  lb();
}
else if(t=='J'){
  rb();
}

else if(t=='X' || t=='x'){
  th();
}
else if (t=='S'){
  s();
}

}
}
