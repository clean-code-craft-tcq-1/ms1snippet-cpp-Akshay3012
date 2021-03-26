#include "sensor-validate.h"

bool isSensorReadingsHaveSuddenJumps_b(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return false;
  }
  return true;
}

bool validateSOCreadings_b(double* values, int numOfValues) {
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!isSensorReadingsHaveSuddenJumps_b(values[i], values[i + 1], 0.05)) {
      return false;
    }
  }
  return true;
}

bool validateCurrentreadings_b(double* values, int numOfValues) {
  int lastButOneIndex = numOfValues - 1;
  for(int j = 0; j < lastButOneIndex; j++) {
    if(!isSensorReadingsHaveSuddenJumps_b(values[j], values[j + 1], 0.1)) {
      return false;
    }
  }
  return true;
}
