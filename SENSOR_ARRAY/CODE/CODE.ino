#include <TB6612FNG.h>

int IR_1 = A0;
int IR_2 = A1;
int IR_3 = A2;
int IR_4 = A3;
int IR_5 = A4;
int IR_6 = A5;
int IR_7 = A6;

int digital_IR1 = 0;
int digital_IR2 = 0;
int digital_IR3 = 0;
int digital_IR4 = 0;
int digital_IR5 = 0;
int digital_IR6 = 0;
int digital_IR7 = 0;

int array = {digital_IR1, digital_IR2, digital_IR3, digital_IR4, digital_IR5, digital_IR6, digital_IR7};

void setup() {
  // put your setup code here, to run once:
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);
  pinMode(IR_5, INPUT);
  pinMode(IR_6, INPUT);
  pinMode(IR_7, INPUT);
}

void THRESHOLD(int value)
{
    if(analogRead(IR_1) > value)
    {
      digital_IR1 = 1;
    }

    if(analogRead(IR_2) > value)
    {
      digital_IR2 = 1;
    }

    if(analogRead(IR_3) > value)
    {
      digital_IR3 = 1;
    }

    if(analogRead(IR_4) > value)
    {
      digital_IR4 = 1;
    }

    if(analogRead(IR_5) > value)
    {
      digital_IR5 = 1;
    }

    if(analogRead(IR_6) > value)
    {
      digital_IR6 = 1;
    }

    if(analogRead(IR_7) > value)
    {
      digital_IR7 = 1;
    }
}


void loop() {
  // put your main code here, to run repeatedly:
  if(array == {0,0,0,0,0,0,0})
  {
    BACKWARD(150);
  }

  else if(array == {1,1,1,1,1,1,1})
  {
    FORWARD(150);
  }

  else {
    STOP();
  }

}
