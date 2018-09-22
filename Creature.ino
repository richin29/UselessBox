/************************** INCLUDES **************************/
#include "Servo.h"
#include "StdTypes.h"
/************************** DEFINES ***************************/
#define TEASE_RANGE        ((uint8) 15)
#define TEASE_OFFSET       ((uint8) 40)
#define TEASE_START        (END_ANGLE - TEASE_OFFSET)
#define TEASE_STOP         (TEASE_START + TEASE_RANGE)

/************************** VARIABLES *************************/
static uint8 current_angle = INIT_ANGLE;
static uint16 delay_val = 0;
static Servo creature_servo;

/************************** FUNCTIONS *************************/
void CreateCreature( void )
{
  creature_servo.attach(SERVO_PIN);
}

void TurnOffSwitch( void )
{
  for(current_angle; current_angle <= END_ANGLE; current_angle += 5)
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
  for(current_angle; current_angle <= TEASE_STOP; current_angle += 5)
  {                                  
    creature_servo.write(current_angle);
    delay(5);
  }
  delay_val = random(5, 11) * 100;
  delay(delay_val);

  for(current_angle; current_angle>=TEASE_START; current_angle-=5)
  {                                
    creature_servo.write(current_angle);
    delay(5);                       
  }
  delay_val = random(3, 7) * 100;
  delay(delay_val);

  for(current_angle; current_angle <= TEASE_STOP; current_angle += 5)
  {                                  
    creature_servo.write(current_angle);
    delay(5);
  }
  delay_val = random(5, 11) * 100;
  delay(delay_val);

  for(current_angle; current_angle>=TEASE_START; current_angle-=5)
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
