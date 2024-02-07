//Author:Katelyn Junker
//Date: 04/13/2022
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void convertTime24to12(int hour);
void getTime24();
void printTime12(int& hour, char& timeOfDay);
int hour, minute;
char ch, timeOfDay,repeat;
int main()
{
    repeat = 'y';
    do
    {
        hour = 0;
        getTime24();
        cout << "would you like to atart over? (y or n)" << endl;
        cin >> repeat;
    } while ((repeat == 'y') || (repeat == 'Y'));
}

void getTime24()
{
    cout << "Please enter time in 24-hour format. For example 22:03: " << endl;
    cin >> hour >> ch >> minute;
    while ((hour > 23) || (minute > 59))
    {
        cout << "invalid time please try again." << endl;
        cin >> hour >> ch >> minute;
    }
    convertTime24to12(hour);
}

void convertTime24to12(int hour)
{
    if (hour > 12) {
        hour = (hour-12);
        timeOfDay = 'p';
    }

    else
        timeOfDay = 'a';
    printTime12(hour, timeOfDay);
}


void printTime12(int& hour, char& timeOfDay)
{
    if (hour < 10)
    {
        cout << "The time entered in 12-hour format is ";
        cout << 0 << hour;
        cout << ch;
        if (minute < 10)
        {
            cout << 0 << minute;
        }
        else
        {
            cout << minute;
        }

    }
    else
    {
        cout << "The time entered in 12-hour format is " << hour << ch;
        if (minute < 10)
        {
            cout << 0 << minute;
        }
        else
        {
            cout << minute;
        }
    }

    if (timeOfDay == 'a')
        cout << "a.m." << endl;

    else
        cout << "p.m." << endl;
}