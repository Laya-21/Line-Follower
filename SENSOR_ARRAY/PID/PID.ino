#include <TB6612FNG.h>

int IR_1 = A0;
int IR_2 = A1;
int IR_3 = A2;
int IR_4 = A3;
int IR_5 = A4;
int IR_6 = A5;
int IR_7 = A6;




void setup() {
  // put your setup code here, to run once:
  
}






void loop() {
  // put your main code here, to run repeatedly:
  float PID_SPEED = PID();

  const float base_speed = 100;
  const float max_speed = 210;
  const float min_speed = 0;

  float speed_l = base_speed - PID_SPEED;
  float speed_r = base_speed + PID_SPEED;

  if(speed_l > max_speed)
  {
    speed_l = max_speed;
  }

  if(speed_r > max_speed)
  {
    speed_r = max_speed;
  }


  if(array == {0,0,0,0,0,0,0})
  {
    BACKWARD(150,150);
  }

  else if(array == {1,1,1,1,1,1,1})
  {
    FORWARD(150,150);
  }

  else {
    FORWARD(speed_l, speed_r);
  }

}
