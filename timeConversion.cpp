#include "timeFunctions.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstring>

using namespace std;

/**
 * @brief Converts a 12-hour time string to a 24-hour time string.
 *
 * @param time12 The 12-hour time string to be converted.
 * @return The converted 24-hour time string.
 */
string convert12HourTo24Hour(const string &time12)
{
    istringstream inStream(time12);
    int hour, minute, second;
    char colon1, colon2, meridiem[3];
    inStream >> hour >> colon1 >> minute >> colon2 >> second >> meridiem;

    if (strcmp(meridiem, "PM") == 0)
    {
        if (hour != 12)
        {
            hour += 12;
        }
    }
    else if (hour == 12)
    {
        hour = 0;
    }

    ostringstream outStream;
    outStream << (hour < 10 ? "0" : "") << hour << colon1 << (minute < 10 ? "0" : "") << minute << colon2 << (second < 10 ? "0" : "") << second;
    return outStream.str();
}

/**
 * @brief Converts a 24-hour time string to a 12-hour time string.
 *
 * This function takes a 24-hour time string in the format "HH:MM:SS" and converts it to a 12-hour time string
 * in the format "HH:MM:SS AM/PM". If the hour is greater than or equal to 12, it is considered as PM, otherwise it is considered as AM.
 *
 * @param time24 The 24-hour time string to be converted.
 * @return The converted 12-hour time string.
 */
string convert24HourTo12Hour(const string &time24)
{
    istringstream inStream(time24);
    int hour, minute, second;
    char colon1, colon2;
    inStream >> hour >> colon1 >> minute >> colon2 >> second;

    string meridiem = "AM";
    if (hour >= 12)
    {
        meridiem = "PM";
        if (hour > 12)
        {
            hour -= 12;
        }
    }
    else if (hour == 0)
    {
        hour = 12;
    }

    return (hour < 10 ? "0" : "") + to_string(hour) + time24.substr(2, 6) + " " + meridiem;
}

/**
 * @brief Adds one hour to the given 12-hour and 24-hour time representations.
 *
 * This function takes in two string references representing a 12-hour time (in the format "hh:mm AM/PM")
 * and a 24-hour time (in the format "hh:mm"). It adds one hour to both time representations and updates
 * the input strings accordingly.
 *
 * @param time12 The reference to the 12-hour time string to be modified.
 * @param time24 The reference to the 24-hour time string to be modified.
 */
void addOneHourToTimes(string &time12, string &time24)
{

    int hour24 = stoi(time24.substr(0, 2));
    hour24 = (hour24 + 1) % 24;

    time24.replace(0, 2, hour24 < 10 ? "0" + to_string(hour24) : to_string(hour24));

    int hour12 = stoi(time12.substr(0, 2));
    string meridiem = time12.substr(9, 2);

    if (hour12 == 11)
    {
        hour12 = 12;
        meridiem = (meridiem == "AM") ? "PM" : "AM";
    }
    else if (hour12 == 12)
    {
        hour12 = 1;
    }
    else
    {
        hour12 += 1;
    }

    time12.replace(0, 2, hour12 < 10 ? "0" + to_string(hour12) : to_string(hour12));
    time12.replace(9, 2, meridiem);
}
/**
 * @brief Adds one minute to the given time in both 12-hour and 24-hour formats.
 *
 * This function takes a time in 12-hour format and 24-hour format as input and adds one minute to it.
 * If the minute value reaches 60, it wraps around to 00 and increments the hour value accordingly.
 *
 * @param time12 A reference to a string representing the time in 12-hour format (e.g., "08:30:45 PM").
 * @param time24 A reference to a string representing the time in 24-hour format (e.g., "20:30:45").
 */
void addOneMinuteToTimes(string &time12, string &time24)
{
    int hour = stoi(time24.substr(0, 2));
    int minute = stoi(time24.substr(3, 2));
    int second = stoi(time24.substr(6, 2));

    minute = (minute + 1) % 60;
    if (minute == 0)
    {
        addOneHourToTimes(time12, time24);
        time24.replace(3, 2, "00");
        time12.replace(3, 2, "00");
    }
    else
    {
        time24.replace(3, 2, minute < 10 ? "0" + to_string(minute) : to_string(minute));
        time12.replace(3, 2, minute < 10 ? "0" + to_string(minute) : to_string(minute));
    }
}

/**
 * @brief Adds one second to the given time in both 12-hour and 24-hour formats.
 *
 * This function takes two string references representing the time in 12-hour and 24-hour formats.
 * It extracts the hour, minute, and second components from the 24-hour format, adds one second to the second component,
 * and updates both the 12-hour and 24-hour formats accordingly. If the second component becomes zero after adding one second,
 * the function calls another function addOneMinuteToTimes to update the minute component as well.
 *
 * @param time12 A reference to a string representing the time in 12-hour format (e.g., "08:30:45 PM").
 * @param time24 A reference to a string representing the time in 24-hour format (e.g., "20:30:45").
 */
void addOneSecondToTimes(string &time12, string &time24)
{
    int hour = stoi(time24.substr(0, 2));
    int minute = stoi(time24.substr(3, 2));
    int second = stoi(time24.substr(6, 2));

    second = (second + 1) % 60;
    if (second == 0)
    {
        addOneMinuteToTimes(time12, time24);
        time24.replace(6, 2, "00");
        time12.replace(6, 2, "00");
    }
    else
    {
        time24.replace(6, 2, second < 10 ? "0" + to_string(second) : to_string(second));
        time12.replace(6, 2, second < 10 ? "0" + to_string(second) : to_string(second));
    }
}