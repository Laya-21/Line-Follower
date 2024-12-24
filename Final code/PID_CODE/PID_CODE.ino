#include <Sensor_Array.h>
#include <TB6612FNG.h>

TB1266FNG Motor_driver(3,6,5,11,9,10);
Sensor_Array IRsensor(A0,A1,A2,A3,A4,A5,A6);
void setup(){
  Motor_driver.pinSetup();
  IRsensor.pinSetup();
}

//Threshold Loop


//while loop
void loop() {
  // put your main code here, to run repeatedly:
  int reading = IRsensor.binary();
  float PID_SPEED = IRsensor.pid();

  const float base_speed = 140;
  const float max_speed = 230;
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


  if(reading == 0)
  {
    Motor_driver.BACKWARD(150,150);
  }
  
  else if(reading == 255)
  {
    Motor_driver.FORWARD(150,150);
  }

  else {
    Motor_driver.FORWARD(speed_l, speed_r);
  }

}