
bool isSensorReadingsHaveSuddenJumps_b(double value, double nextValue, double maxDelta);

bool getReadingStatus_b(double* values, int numOfReadings, double maxDelta);

bool validateSOCreadings_b(double* values, int numOfValues);

bool validateCurrentreadings_b(double* values, int numOfValues);
