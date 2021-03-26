#include "sensor-validate.h"

bool isSensorReadingsHaveSuddenJumps_b(double currentValue, double nextValue, double maxDelta) {
  if(nextValue - currentValue > maxDelta) {
    return false;
  }
  return true;
}

bool validateSOCreadings_b(double* values, int numOfReadings) 
{
  for(int SOCReadingIndex = 0; SOCReadingIndex < (numOfReadings -1); SOCReadingIndex++) 
  {
    if(!isSensorReadingsHaveSuddenJumps_b(values[SOCReadingIndex], values[SOCReadingIndex + 1], 0.05)) 
    {
      return false;
    }
  }
  return true;
}

bool validateCurrentreadings_b(double* values, int numOfReadings) 
{
  for(int CurrentReadingIndex = 0; CurrentReadingIndex < (numOfReadings-1); CurrentReadingIndex++) 
  {
    if(!isSensorReadingsHaveSuddenJumps_b(values[CurrentReadingIndex], values[CurrentReadingIndex + 1], 0.1)) 
    {
      return false;
    }
  }
  return true;
}
