#include <TB6612FNG.h>

TB1266FNG Motor_driver(3,6,5,11,9,10);
#define IR_1 A0
#define IR_2 A1
#define IR_3 A2
#define IR_4 A3
#define IR_5 A4
#define IR_6 A5
#define IR_7 8
#define IR_8 12

int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;
int val6 = 0;
int val7 = 0;
int val8 = 0;
int num = 128*val8 + 64*val7 + 32*val6 + 16*val5 + 8*val4 + 4*val3 + 2*val2 + 1*val1;

int last_error = 0;
int error = 0;
float kp = 0;
float kd = 0;

int color =1;
int count = 0;


void setup() {
  Motor_driver.pinSetup();
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);
  pinMode(IR_5, INPUT);
  pinMode(IR_6, INPUT);
  pinMode(IR_7, INPUT);
  pinMode(IR_8, INPUT);
  Serial.begin(9600);
}

void reading()
{
  val1 = digitalRead(IR_1);
  val2 = digitalRead(IR_2);
  val3 = digitalRead(IR_3);
  val4 = digitalRead(IR_4);
  val5 = digitalRead(IR_5);
  val6 = digitalRead(IR_6);
  val7 = digitalRead(IR_7);
  val8 = digitalRead(IR_8);
  // Serial.print(val1);
  // Serial.print(val2);
  // Serial.print(val3);
  // Serial.print(val4);
  // Serial.print(val5);
  // Serial.print(val6);
  // Serial.print(val7);
  // Serial.println(val8);
  
  num = 128*val8 + 64*val7 + 32*val6 + 16*val5 + 8*val4 + 4*val3 + 2*val2 + 1*val1;
}

int checkBW()
{
  if(val1 == 0 && val8 == 0)
  {
    color = 0;
  }
  else if(val1 == 1 && val8 == 1)
  {
    color = 1;
  }

  return color;
}

float pid()
{
  kp = 3.5; //2.5
  kd = 2.5; //1.30
  error = 30*val1 + 20*val2 + 10*val3 + 0*val4 - 0*val5 - 10*val6 - 20*val7 - 30*val8;
  int P = error;
  int D = error - last_error;
  
  float PID_speed = kp*P + kd*D;
  last_error = error;
  return PID_speed;
}

void loop() {

  reading();

  int COL = checkBW();
  float PID_SPEED = pid();

  const float base_speed = 125; //130
  const float max_speed = 160; //170
  const float min_speed = 0;

  float speed_l = base_speed - PID_SPEED;
  float speed_r = base_speed + PID_SPEED;


  if(speed_l <0)
  {
    speed_l = -1*speed_l;
  }

  if(speed_r <0)
  {
    speed_r = -1*speed_r;
  }

  if(speed_l > max_speed)
  {
    speed_l = max_speed;
  }

  if(speed_r > max_speed)
  {
    speed_r = max_speed;
  }

  // Serial.println(speed_l);
  // Serial.println(speed_r);
  Serial.println(num);

    // if(num == 255)
    // {
    //   Motor_driver.BACKWARD(70.0, 70.0);
    // }

    // else
    // {
    //   Motor_driver.FORWARD(speed_l, speed_r); 
    // }

  if(COL == 1)
  {
    if(num == 255)
    {
      count = count + 1;
      Motor_driver.BACKWARD(120.0, 120.0);
      // delay(500);
      if(count >= 1200)
      {
        Motor_driver.FORWARD(speed_l, speed_r);
        count = 0;
        delay(1000);
      }
    }

    else if(num==240 || num==224 || num == 192)
    {
      Motor_driver.EXT_LEFT(250.0, 250.0);
      // delay(250);
    }
    
    else if(num==15 || num==7 || num == 1)
    {
      Motor_driver.EXT_RIGHT(250.0, 250.0);
      // delay(250);
    }

    else
    {
      Motor_driver.FORWARD(speed_l, speed_r); 
    }
  }

  else if(COL == 0)
  {
    if(num == 0)
    {
      count = count + 1;
      Motor_driver.BACKWARD(120.0, 120.0);
      // delay(500);
      if(count >= 1200)
      {
        Motor_driver.FORWARD(speed_l, speed_r);
        count = 0;
        delay(1000);
      }
    }
    else if(num==240 || num==224 || num == 192)
    {
      Motor_driver.EXT_RIGHT(250.0, 250.0);
      // delay(250);
    }

    else if(num==15 || num==7 || num == 1)
    {
      Motor_driver.EXT_LEFT(250.0, 250.0);
      // delay(250);
    }

    else
    {
      Motor_driver.FORWARD(speed_r, speed_l); 
    }
  }

  // delay(500);
}
