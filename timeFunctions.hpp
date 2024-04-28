// timeFunctions.hpp

#ifndef timeFunctions_HPP
#define timeFunctions_HPP

#include <string>

// Prompts the user to select their preferred time format and returns the entered time as a string.
std::pair<std::string, std::string> getTime();

// Convert 12-hour time format to 24-hour format
std::string convert12HourTo24Hour(const std::string &time12);

// Convert 24-hour time format to 12-hour format
std::string convert24HourTo12Hour(const std::string &time24);

// Adds one hour to the given 12-hour and 24-hour time strings.
void addOneHourToTimes(std::string &time12, std::string &time24);

// Adds one minute to the given 12-hour and 24-hour time strings.
void addOneMinuteToTimes(std::string &time12, std::string &time24);

// Adds one second to the given 12-hour and 24-hour time strings.
void addOneSecondToTimes(std::string &time12, std::string &time24);

#endif