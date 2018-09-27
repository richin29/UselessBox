

/**************************************************************/

/************************** INCLUDES **************************/
#include "StdTypes.h"
#include "ButtonMngTypes.h"

/************************** DEFINES ***************************/
#define BUTTON_PIN         ((uint8) 2)
#define SERVO_PIN          ((uint8) 3)
#define INIT_ANGLE         ((uint8) 30)
#define END_ANGLE          ((uint8) 160)
#define IDLE_TIME          ((uint64) 300000)
#define TEASE_TIME         ((uint64) 5000)
#define MIN_TEASE_PRESSES  ((uint8) 3)
#define NUM_TEASES         ((uint8) 2)

/************************** VARIABLES *************************/
uint8 button_press_count = 0;
static uint64 elapsed_time = 0;
static uint8 num_teases = 0;

/************************** FUNCTIONS *************************/
void setup() 
{
  ButtonMngInit();
  CreateCreature();
} 
  
void loop() 
{
  ButtonMngTask();
  MonitorButtonPress();
  MonitorCreatureIdle();
}

void MonitorButtonPress( void )
{
  t_button_val button_val = (t_button_val)ButtonMngRead(TOGGLE_SWITCH_BUTTON);
  if (button_val == BUTTON_ON) {
    TurnOffSwitch();
    ResetTime();
    delay(100);
  }
  else {
    GetBackInside();
  }
}
void MonitorCreatureIdle( void )
{
  elapsed_time = GetElapsedTime();
  button_press_count = ButtonMngGetCount(TOGGLE_SWITCH_BUTTON);
  if ((num_teases < NUM_TEASES) && (button_press_count >= MIN_TEASE_PRESSES) && (elapsed_time >= TEASE_TIME)) {
    ResetTime();
    Tease();
    num_teases++;
  }
  else if ((num_teases >= NUM_TEASES) && (button_press_count >= MIN_TEASE_PRESSES)) {
    ButtonMngResetCount(TOGGLE_SWITCH_BUTTON);
    num_teases = 0;
  }
  else if ((button_press_count < MIN_TEASE_PRESSES) && (elapsed_time >= IDLE_TIME)) {
    ResetTime();
    Tease();
    ButtonMngResetCount(TOGGLE_SWITCH_BUTTON);
  }
  else {
    /* Do Nothing */
  }
}
