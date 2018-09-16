

/**************************************************************/

/************************** INCLUDES **************************/

/************************** DEFINES ***************************/
#define BUTTON_PIN         ((unsigned char) 2)
#define SERVO_PIN          ((unsigned char) 3)
#define INIT_ANGLE         ((unsigned short int) 60)
#define IDLE_TIME          ((unsigned long) 300000)
#define TEASE_TIME         ((unsigned long) 5000)
#define MIN_TEASE_PRESSES  ((unsigned char) 3)
#define NUM_TEASES         ((unsigned char) 2)

/************************** VARIABLES *************************/
unsigned char button_press_count = 0;
static int button_val;
static unsigned long elapsed_time = 0;
static unsigned char num_teases = 0;

/************************** FUNCTIONS *************************/
void setup() 
{
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
