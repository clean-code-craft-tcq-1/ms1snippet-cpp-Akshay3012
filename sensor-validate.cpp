#include "sensor-validate.h"

bool isSensorReadingsHaveSuddenJumps_b(double currentValue, double nextValue, double maxDelta) {
  if((nextValue - currentValue) > maxDelta) {
    return true;
  }
  return false;
}

bool getReadingStatus_b(double* values, int numOfReadings, double maxDelta)
{
   for(int ReadingIndex = 0; ReadingIndex < (numOfReadings -1); ReadingIndex++) 
    {
      if(isSensorReadingsHaveSuddenJumps_b(values[ReadingIndex], values[ReadingIndex + 1], maxDelta)) 
      {
        return false;
      }
    }
  return true;
}

bool validateSOCreadings_b(double* values, int numOfReadings) 
{
  if (numOfReadings == 0)
  {
    return false;
  }
  else
  {
    return getReadingStatus_b(values, numOfReadings, 0.05);
  }
}

bool validateCurrentreadings_b(double* values, int numOfReadings) 
{
  if (numOfReadings == 0)
  {
    return false;
  }
  else
  {
    return getReadingStatus_b(values, numOfReadings, 0.1);
  }
}
