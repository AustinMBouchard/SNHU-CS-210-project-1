#include "timeFunctions.hpp"
#include <iostream>
#include <string>
#include <regex>
#include <limits>
#include <algorithm>
#include <cctype>

using namespace std;

/**
 * Checks if the given time string is valid in 24-hour format.
 *
 * @param time The time string to be validated.
 * @return True if the time is valid, false otherwise.
 */
bool isTimeValid24Hours(string time)
{
    regex timePattern("([01]?[0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]");
    return regex_match(time, timePattern);
}

/**
 * Checks if the given time string is valid in 12-hour format.
 *
 * @param time The time string to be validated.
 * @return True if the time is valid, false otherwise.
 */
bool isTimeValid12Hours(string time)
{
    regex timePattern("^([0]?[1-9]|1[0-2]):[0-5][0-9]:[0-5][0-9]( [AaPp][Mm])$");
    return regex_match(time, timePattern);
}

/**
 * Retrieves the time from the user in either 12-hour or 24-hour format.
 *
 * @return A pair of strings representing the time in both 12-hour and 24-hour formats.
 */
pair<string, string> getTime()
{
    string time;
    int formatChoice = 0;
    bool validTime = false;
    string time12, time24;

    while (formatChoice != 1 && formatChoice != 2)
    {
        cout << "Please select your preferred time format:"
             << "\n1. 12-hour format"
             << "\n2. 24-hour format"
             << "\nSelect your choice: ";

        cin >> formatChoice;

        if (formatChoice != 1 && formatChoice != 2)
        {
            cout << "Invalid selection. Please enter 1 or 2.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (formatChoice == 1)
    {
        while (!validTime)
        {
            cout << "Enter the time in 12-hour format (hh:mm:ss AM/PM): ";
            getline(cin, time);

            transform(time.begin(), time.end(), time.begin(),
                      [](unsigned char c)
                      { return toupper(c); });

            validTime = isTimeValid12Hours(time);

            if (!validTime)
            {
                cout << "Invalid time format.\n";
            }
        }
    }
    else
    {
        while (!validTime)
        {
            cout << "Enter the time in 24-hour format (hh:mm:ss): ";
            getline(cin, time);
            validTime = isTimeValid24Hours(time);

            if (!validTime)
            {
                cout << "Invalid time format.\n";
            }
        }
    }

    if (formatChoice == 1)
    {
        time12 = time;
        time24 = convert12HourTo24Hour(time);
    }
    else
    {
        time24 = time;
        time12 = convert24HourTo12Hour(time);
    }

    return make_pair(time12, time24);
}