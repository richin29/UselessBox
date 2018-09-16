/**************************************************************/

/************************** INCLUDES **************************/

/************************** DEFINES ***************************/
#define BUTTON_PIN   ((unsigned char) 2)
#define SERVO_PIN    ((unsigned char) 3)
#define INIT_ANGLE   ((unsigned short int) 60)

/************************** VARIABLES *************************/
int button_val;

/************************** FUNCTIONS *************************/
void setup() 
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  CreateCreature();
} 
  
void loop() 
{ 
  button_val = digitalRead(BUTTON_PIN);
  if (button_val == LOW) {
    TurnOffSwitch();
    delay(100);
  }
  else {
    GetBackInside();
  }
}
