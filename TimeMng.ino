/************************** INCLUDES **************************/

/************************** VARIABLES *************************/
static unsigned long timemng_start_time = millis();
static unsigned long timemng_current_time = 0;

/************************** FUNCTIONS *************************/
void ResetTime( void )
{
  timemng_start_time = millis();
}

unsigned long GetElapsedTime( void )
{
  timemng_current_time = millis();
  
  return timemng_current_time - timemng_start_time;
}
