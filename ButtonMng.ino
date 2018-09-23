/************************** INCLUDES **************************/
#include "StdTypes.h"
#include "ButtonMngTypes.h"

/************************** DEFINES ***************************/

/************************** VARIABLES *************************/

static t_button_data button_data[MAX_NUM_BUTTONS] = {
  /* button_pin,  button_mode */
  {       2    ,  INPUT_PULLUP }
};

/********************* FUNCTIONS PROTOTYPES *******************/

/************************** FUNCTIONS *************************/

void ButtonMngInit( void )
{
  uint8 button_index = 0;

  for (; button_index < MAX_NUM_BUTTONS; button_index++) {
    button_data[button_index].last_button_val = BUTTON_OFF;
    button_data[button_index].button_on_count = 0;
    pinMode(button_data[button_index].button_pin, button_data[button_index].button_mode);
  }
}

void ButtonMngTask( void )
{
  uint32 button_val;
  uint8 button_index = 0;

  for (; button_index < MAX_NUM_BUTTONS; button_index++) {
    button_val = digitalRead(button_data[button_index].button_pin);
    ButtonMngUpdateButtonState(button_index, button_val);
  }
}

void ButtonMngUpdateButtonState( uint8 button_index, uint32 button_val )
{
  t_button_val button_state = BUTTON_OFF;
  
  if (button_val == LOW) {
    if (button_data[button_index].button_mode == INPUT_PULLUP) {
      button_state = BUTTON_ON;
    }
  }
  else {
    if (button_data[button_index].button_mode == INPUT) {
      button_state = BUTTON_ON;
    }
  }

  if ((button_state == BUTTON_ON) && (button_val != button_data[button_index].last_button_val)) {
    button_data[button_index].button_on_count += (uint8) 1;
  }

  if (button_state != button_data[button_index].last_button_val) {
    button_data[button_index].last_button_val = button_state;
  }
}

uint8 ButtonMngRead( uint8 button_index )
{
  return (uint8)button_data[button_index].last_button_val;
}

uint32 ButtonMngGetCount( uint8 button_index )
{
  return button_data[button_index].button_on_count;
}

void ButtonMngResetCount( uint8 button_index )
{
  button_data[button_index].button_on_count = (uint8) 0;
}
