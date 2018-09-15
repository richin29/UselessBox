#include "Servo.h"

void TurnOffSwitch( Servo servo_handler )
{
    for(angle = 30; angle < 180; angle += 5)
    {                                  
        servo_handler.write(angle);
        delay(10);                       
    } 
}
