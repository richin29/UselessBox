

/**************************************************************/

/************************** INCLUDES **************************/
#include "StdTypes.h"
//#include "ButtonMng.h"

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
static uint32 button_val;
static uint64 elapsed_time = 0;
static uint8 num_teases = 0;

/************************** FUNCTIONS *************************/
void setup() 
{
  //CreateButton(0, BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  CreateCreature();
} 
  
void loop() 
{
  MonitorButtonPress();
  MonitorCreatureIdle();
}

void MonitorButtonPress( void )
{
  button_val = digitalRead(BUTTON_PIN);
  if (button_val == LOW) {
    TurnOffSwitch();
    ResetTime();
    button_press_count++;
    delay(100);
  }
  else {
    GetBackInside();
  }
}
void MonitorCreatureIdle( void )
{
  elapsed_time = GetElapsedTime();
  if ((num_teases < NUM_TEASES) && (button_press_count >= MIN_TEASE_PRESSES) && (elapsed_time >= TEASE_TIME)) {
    ResetTime();
    Tease();
    num_teases++;
  }
  else if ((num_teases >= NUM_TEASES) && (button_press_count >= MIN_TEASE_PRESSES)) {
    button_press_count = 0;
    num_teases = 0;
  }
  else if ((button_press_count < MIN_TEASE_PRESSES) && (elapsed_time >= IDLE_TIME)) {
    ResetTime();
    Tease();
    button_press_count = 0;
  }
  else {
    /* Do Nothing */
  }
}
