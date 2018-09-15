#include "Servo.h"

Servo servo_test;
int angle = 0;
int button_gpio = 2;
int servo_gpio = 3;
int led_gpio = LED_BUILTIN;
int button_val;
 
void setup() 
{
  pinMode(button_gpio, INPUT);
  servo_test.attach(servo_gpio);      // attach the signal pin of servo to pin9 of arduino
} 
  
void loop() 
{ 
  TurnOffSwitch(servo_test); 
 
  delay(1000);
  button_val = digitalRead(button_gpio);     // read the input pin
  digitalWrite(led_gpio, button_val);    // sets the LED to the button's value
  
  for(angle = 180; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle);              //command to rotate the servo to the specified angle
    delay(5);                       
  } 

    delay(1000);
}
