/************************** INCLUDES **************************/
#include "Servo.h"

/************************** VARIABLES *************************/
static unsigned char current_angle = INIT_ANGLE;
static Servo creature_servo;

/************************** FUNCTIONS *************************/
void CreateCreature( void )
{
  creature_servo.attach(SERVO_PIN);
}

void TurnOffSwitch( void )
{
  for(current_angle; current_angle <= 180; current_angle += 5)
  {                                  
    creature_servo.write(current_angle);
    delay(5);
  } 
}

void GetBackInside( void )
{
  for(current_angle; current_angle>=INIT_ANGLE; current_angle-=5)
  {                                
    creature_servo.write(current_angle);
    delay(5);                       
  } 
}
