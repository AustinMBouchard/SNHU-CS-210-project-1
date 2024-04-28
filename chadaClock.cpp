#include <iostream>
#include <string>
#include "timeFunctions.hpp"

using namespace std;

/**
 * Displays the time in both 12-hour and 24-hour formats.
 *
 * @param time12 The time in 12-hour format.
 * @param time24 The time in 24-hour format.
 */
void displayTime(const string &time12, const string &time24)
{
    cout << "\n**************************     **************************" << endl;
    cout << "*     12-Hour Clock      *     *      24-Hour Clock     *" << endl;
    cout << "*      " << time12 << "       *     *        " << time24 << "        *" << endl;
    cout << "**************************     **************************\n"
         << endl;
}

/**
 * Displays the menu options for the clock program.
 * The menu includes options to add one hour, one minute, one second, or exit the program.
 */
void displayMenu()
{
    cout << "Please select an option from the menu below:\n";
    cout << "**************************" << endl;
    cout << "* 1 - Add One Hour       *" << endl;
    cout << "* 2 - Add One Minute     *" << endl;
    cout << "* 3 - Add One Second     *" << endl;
    cout << "* 4 - Exit Program       *" << endl;
    cout << "**************************" << endl;
}

/**
 * @brief The main function of the program.
 *
 * This function displays a welcome message and initializes the clock display.
 * It then prompts the user to select an option from the menu and performs the corresponding action.
 * The program continues to display the updated time until the user chooses to exit.
 *
 * @return 0 indicating successful execution of the program.
 */
int main()
{
    cout << "Welcome to Chada Tech's 12 and 24-hour clock display program!" << endl;

    int menuChoice;
    pair<string, string> timePair;
    timePair = getTime();
    string time12 = timePair.first;
    string time24 = timePair.second;
    displayTime(time12, time24);

    do
    {
        displayMenu();
        cin >> menuChoice;

        if (cin.fail() || menuChoice < 1 || menuChoice > 4)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice.\n";
            continue;
        }

        switch (menuChoice)
        {
        case 1:
            addOneHourToTimes(time12, time24);
            break;

        case 2:
            addOneMinuteToTimes(time12, time24);
            break;

        case 3:
            addOneSecondToTimes(time12, time24);
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Select a valid option from the menu." << endl;
            break;
        }

        if (menuChoice != 4)
        {
            displayTime(time12, time24);
        }
    } while (menuChoice != 4);

    return 0;
}