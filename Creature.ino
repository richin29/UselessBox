/************************** INCLUDES **************************/
#include "Servo.h"

/************************** VARIABLES *************************/
static unsigned char current_angle = INIT_ANGLE;
static unsigned short int delay_val = 0;
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

void Tease( void )
{
  for(current_angle; current_angle <= 165; current_angle += 5)
  {                                  
    creature_servo.write(current_angle);
    delay(5);
  }
  delay_val = random(5, 11) * 100;
  delay(delay_val);

  for(current_angle; current_angle>=140; current_angle-=5)
  {                                
    creature_servo.write(current_angle);
    delay(5);                       
  }
  delay_val = random(3, 7) * 100;
  delay(delay_val);

  for(current_angle; current_angle <= 165; current_angle += 5)
  {                                  
    creature_servo.write(current_angle);
    delay(5);
  }
  delay_val = random(5, 11) * 100;
  delay(delay_val);

  for(current_angle; current_angle>=140; current_angle-=5)
  {                                
    creature_servo.write(current_angle);
    delay(5);                       
  }

  for(current_angle; current_angle>=INIT_ANGLE; current_angle-=5)
  {                                
    creature_servo.write(current_angle);
    delay(5);                       
  }
}
