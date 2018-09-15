#include "Servo.h"

unsigned char current_angle = INIT_ANGLE;
Servo creature_servo;

void CreateCreature( void )
{
  creature_servo.attach(SERVO_PIN);
}

void TurnOffSwitch( void )
{
  for(current_angle; current_angle < 180; current_angle += 5)
  {                                  
    creature_servo.write(current_angle);
    delay(10);
  } 
}

void GetBackInside( void )
{
  for(current_angle; current_angle>=1; current_angle-=5)
  {                                
    creature_servo.write(current_angle);
    delay(5);                       
  } 
}
