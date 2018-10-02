#include <Servo.h>
#include <arc.h>
Servo BaseMotor;
Servo ShoulderMotor;
Servo ElbowMotor;
Servo WristMotor;
Servo test;

const int BaseEquilAngle = 90;
const int ShoulderEquilAngle = 90; 
const int ElbowEquilAngle = 90; 
const int WristEquilAngle = 90; 
const int BaseOffsetAngle = -5;
const int ShoulderOffsetAngle = 5;
const int ElbowOffsetAngle = 5;
const int WristOffsetAngle = 0;

void servoWrite(Servo& servo, int angle) {
  servo.write(clip(angle, 0, 180));
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  BaseMotor.attach(2, 700, 2300);
  servoWrite(BaseMotor, BaseEquilAngle);
  ShoulderMotor.attach(3, 400, 3100);
  servoWrite(ShoulderMotor, ShoulderEquilAngle + ShoulderOffsetAngle);
  ElbowMotor.attach(4, 700, 2300);
  servoWrite(ElbowMotor, ElbowEquilAngle + ElbowOffsetAngle);
  WristMotor.attach(5, 700, 2300);
  servoWrite(WristMotor, WristEquilAngle + WristOffsetAngle);

  
  
}

void loop() {




  
  
  float sine_counter = 0;
  int sine_amp = 70;
  int sine_mid = 0;
  
  while(true) {
    int sine_addition = (int)((float)sine_amp * sin(sine_counter)) + sine_mid;
    sine_counter += 0.0001;
    servoWrite(ShoulderMotor, ShoulderEquilAngle + sine_addition + ShoulderOffsetAngle);
    //servoWrite(ElbowMotor, ElbowEquilAngle + sine_addition + ElbowOffsetAngle);
    //servoWrite(WristMotor, WristEquilAngle + sine_addition + WristOffsetAngle);    
    //servoWrite(BaseMotor, BaseEquilAngle + sine_addition + BaseOffsetAngle);

  
  }
  
  
}
