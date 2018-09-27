/************************** INCLUDES **************************/
#include "StdTypes.h"
#ifndef BUTTONMNGTYPES_H
#define BUTTONMNGTYPES_H

/************************** DEFINES ***************************/

typedef enum {
  TOGGLE_SWITCH_BUTTON = 0,
  /* add your button above this line */
  MAX_NUM_BUTTONS
} t_button;

typedef enum {
  BUTTON_OFF = 0,
  BUTTON_ON = 1
} t_button_val;

typedef struct {
  uint8 button_pin;
  uint8 button_mode;
  uint8 last_button_val;
  uint32 button_on_count;
} t_button_data;

#endif /* BUTTONMNGTYPES_H */
