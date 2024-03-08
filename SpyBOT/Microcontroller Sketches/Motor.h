#ifndef Motor_h
#define Motor_h
#include<Arduino.h>
class Motor{
  private:
    int e;
    int ina;
    int inb;
  public:
    Motor(int e, int in1, int in2);
    void Setup();
    void SetSpeed(int motorSpeed);
};
#endif
