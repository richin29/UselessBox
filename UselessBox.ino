/**************************************************************/

/************************** INCLUDES **************************/

/************************** VARIABLES *************************/
#define SERVO_PIN ((unsigned char) 3)
#define INIT_ANGLE ((unsigned short int) 30)

int button_gpio = 2;
int servo_pin = 3;
int led_gpio = LED_BUILTIN;
int button_val;

/************************** FUNCTIONS *************************/
void setup() 
{
  pinMode(button_gpio, INPUT);
  CreateCreature();
} 
  
void loop() 
{
  
  TurnOffSwitch(); 
 
  delay(1000);
  button_val = digitalRead(button_gpio);     // read the input pin
  digitalWrite(led_gpio, button_val);    // sets the LED to the button's value
  GetBackInside();
  delay(1000);
}
