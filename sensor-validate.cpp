#include "sensor-validate.h"

bool isSensorReadingsHaveSuddenJumps_b(double currentValue, double nextValue, double maxDelta) {
  if(nextValue - currentValue > maxDelta) {
    return false;
  }
  return true;
}

bool validateSOCreadings_b(double* values, int numOfReadings) 
{
  bool validationStatus = false;
  if (numOfReadings != 0)
  {
    for(int SOCReadingIndex = 0; SOCReadingIndex < (numOfReadings -1); SOCReadingIndex++) 
    {
      if(!isSensorReadingsHaveSuddenJumps_b(values[SOCReadingIndex], values[SOCReadingIndex + 1], 0.05)) 
      {
        validationStatus = false;
      }
    }
    validationStatus = true;
  }
  return validationStatus;
}

bool validateCurrentreadings_b(double* values, int numOfReadings) 
{
  if (numOfReadings == 0)
  {
    return false;
  }
  else
  {
    for(int CurrentReadingIndex = 0; CurrentReadingIndex < (numOfReadings-1); CurrentReadingIndex++) 
    {
      if(!isSensorReadingsHaveSuddenJumps_b(values[CurrentReadingIndex], values[CurrentReadingIndex + 1], 0.1)) 
      {
        return false;
      }
    }
  }
  return true;
}
