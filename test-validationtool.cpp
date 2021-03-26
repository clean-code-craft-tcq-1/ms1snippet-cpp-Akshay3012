#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"

TEST_CASE("reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSOCreadings_b(socReadings, numOfSocReadings) == false);
}

TEST_CASE("No error when soc doesn't jump abruptly") {
  double socReadings[] = {0.0, 0.02, 0.06, 0.1};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSOCreadings_b(socReadings, numOfSocReadings) == true);
}

TEST_CASE("reports error when there is no reading of soc") { 
  double socReadings_empty[] = {};
  int numOfSocReadings_empty = sizeof(socReadings_empty) / sizeof(socReadings_empty[0]);
  REQUIRE(validateSOCreadings_b(socReadings_empty, numOfSocReadings_empty) == false);
}

TEST_CASE("reports error when current jumps abruptly") {
  double currentReadings[] = {0.03, 0.03, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateSOCreadings_b(currentReadings, numOfCurReadings) == false);
}

TEST_CASE("No error when current doesn't jump abruptly") {
  double currentReadings[] = {0.03, 0.04, 0.05, 0.06};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateSOCreadings_b(currentReadings, numOfCurReadings) == true);
}

TEST_CASE("reports error when there is no reading of current") { 
  double currentReadings_empty[] = {};
  int numOfCurReadings_empty = sizeof(currentReadings_empty) / sizeof(currentReadings_empty[0]);
  REQUIRE(validateSOCreadings_b(currentReadings_empty, numOfCurReadings_empty) == false);
}
