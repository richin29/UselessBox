/************************** INCLUDES **************************/
#include "StdTypes.h"

/************************** VARIABLES *************************/
static uint64 timemng_start_time = millis();
static uint64 timemng_current_time = 0;

/************************** FUNCTIONS *************************/
void ResetTime( void )
{
  timemng_start_time = millis();
}

uint64 GetElapsedTime( void )
{
  timemng_current_time = millis();
  
  return timemng_current_time - timemng_start_time;
}
