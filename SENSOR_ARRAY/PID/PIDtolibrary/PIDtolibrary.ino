class Sensor_Array
{
  private:
    int ir1;
    int ir2;
    int ir3;
    int ir4; 
    int ir5;
    int ir6;
    int ir7;

    int digital_IR1 = 0;
    int digital_IR2 = 0;
    int digital_IR3 = 0;
    int digital_IR4 = 0;
    int digital_IR5 = 0;
    int digital_IR6 = 0;
    int digital_IR7 = 0;
    int array = {digital_IR1, digital_IR2, digital_IR3, digital_IR4, digital_IR5, digital_IR6, digital_IR7};

    int last_error = 0;
    int error = 0;

  public:

};