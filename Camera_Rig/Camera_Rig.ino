// letsarduino.com
// [Project 11] - 2 Servos Using a Joystick 
//  (thumbstick) + Arduino

#include <Servo.h>  

int ServoHorizontalPin = 9;   
int ServoVerticalPin =  11;  
int ServoHorizontalPin2 = 10; 
int HorizontalPotPin = A0;  
int VerticalPotPin = A1;  
int ServoH_Min = 0;  
int ServoH_Max = 180; 
int ServoV_Min = 0; 
int ServoV_Max = 180; 

Servo HorizontalServo;  
Servo VerticalServo;    
Servo HorizontalServo2;

int HorizontalPotValue;         
int HorizontalServoPosition=90;    
int VerticalPotValue;         
int VerticalServoPosition=90;    

void setup()   
{
  Serial.begin(9600);
  HorizontalServo.attach(ServoHorizontalPin);   
  VerticalServo.attach(ServoVerticalPin);  
  HorizontalServo2.attach(ServoHorizontalPin2);       
}

void loop()  
{
  HorizontalPotValue  = analogRead(HorizontalPotPin); 
  VerticalPotValue  = analogRead(VerticalPotPin);  
  if(HorizontalPotValue>=900)
  {
    HorizontalServoPosition++;
  }
  if(HorizontalPotValue<=300)
  {
    HorizontalServoPosition--;
  }
  if(VerticalPotValue>=900)
  {
    VerticalServoPosition++;
  }
  if(VerticalPotValue<=300)
  {
    VerticalServoPosition--;
  }

  if(HorizontalServoPosition>120)
  {
    HorizontalServoPosition=120;
  }
  if(HorizontalServoPosition<60)
  {
    HorizontalServoPosition=60;
  }
//  HorizontalServoPosition  = map(HorizontalPotValue, 0, 1023, ServoH_Min , ServoH_Max); 
//  VerticalServoPosition  = map(VerticalPotValue, 1023, 0, ServoH_Max , ServoH_Min);   
  Serial.print(HorizontalServoPosition);
  Serial.print(",");
  Serial.println(VerticalServoPosition);
  HorizontalServo.write(HorizontalServoPosition);       
  HorizontalServo2.write(180-HorizontalServoPosition);
  VerticalServo.write(VerticalServoPosition);      
  delay(100);    
}
