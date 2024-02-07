//Author: Katelyn Junker
// ask about the year, month and day, and give results based on those values.
#include <iostream>
#include <cmath>
using namespace std;
int month, day, year,monthValue, dayValue, centuryValue,yearValue, option = 1;
bool leap;
string dayName;
// declare funtions
void testMenue();
bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month, int year);
int dayOfWeek(int month, int day, int year);
string nameOfDay(int day);
int main()
{
	do
	{
		testMenue();
		cout << "please enter a year." << endl;
		cin >> year;
		if (year < 1582)
		{
			cout << "invalid, please enter a year after 1582." << endl;
			cin >> year;
		}
		switch (option)
		{
		case 1:
			isLeapYear(year);
			if (leap == true)
			{
				cout << year << "is a leap year." << endl;
			}
			else
			{
				cout << year << "is not a leap year." << endl;
			}
			break;
		case 2:
			getCenturyValue(year);
			cout << "century value is " << centuryValue << endl;
			break;
		case 3:
			cout << "Please enter a month (1-12)" << endl;
			cin >> month;
			getYearValue(year);
			cout << "year value is " << yearValue << endl;
			break;
		case 4:
			cout << "Please enter a month (1-12)" << endl;
			cin >> month;
			getMonthValue(month, year);
			cout << "month value is " << monthValue << endl;
			break;
		case 5:
			cout << "Please enter a month (1-12)" << endl;
			cin >> month;
			cout << "please enter the day." << endl;
			cin >> day;
			dayOfWeek(month, day, year);
			nameOfDay(day);
			cout << "name of the day of week is " << dayName << endl;
			break;
		case 6:
			break;
		}
	} while (option != 6);
}
void testMenue()
{
	cout << "Please select one of the following:"<< endl;
	cout << "1: is leap year" << endl;
	cout << "2: get century value" << endl;
	cout << "3: get year value" << endl;
	cout << "4: get month value" << endl;
	cout << "5: get day of the week" << endl;
	cout << "6: Quit" << endl;
	cin >> option;
	if ((option > 6) || (option < 1))
	{
		cout << "invalid, please pick an option between 1 and 7." << endl;
		cin >> option;
	}
}
//post: user selects which option they would like.
//pre: user has entered the year.
bool isLeapYear(int Year)
{
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
	{
		leap = true;
	}
	else
	{
		leap = false;
	}
	return leap;
}
//post: if the year has no remainder after being devided by 400 it is a leap year (returns true).
//pre: user enters year value.
int getCenturyValue (int year)
{
	int century = 0;
	if ((year >= 2000) && (year < 21000))
	{
		century = 20;
	}
	if ((year >= 1900) && (year < 2000))
	{
		century = 19;
	}
	if ((year >= 1800) && (year < 1900))
	{
		century = 18;
	}
	if ((year >= 1700) && (year < 1800))
	{
		century = 17;
	}
	if ((year >= 1600) && (year < 1700))
	{
		century = 16;
	}
	if ((year >= 1500) && (year < 1600))
	{
		century = 15;
	}
	centuryValue = (((century % 4) - 0) * 2);
	return centuryValue;
}
//post: century is determined and is then converted into a value.
//pre: user enters the year.
int getYearValue(int year)
{
	if ((year >= 2000) && (year < 21000))
	{
		year -= 2000;
	}
	if ((year >= 1900) && (year < 2000))
	{
		year -= 1900;
	}
	if ((year >= 1800) && (year < 1900))
	{
		year -= 1800;
	}
	if ((year >= 1700) && (year < 1800))
	{
		year -= 1700;
	}
	if ((year >= 1600) && (year < 1700))
	{
		year -= 1600;
	}
	if ((year >= 1500) && (year < 1600))
	{
		year -= 1500;
	}
	yearValue = ((year / 2) + year);
	return yearValue;
}
//post: first two numbers are removed and a value is calculated.
//pre:user enters month and year.
int getMonthValue(int month, int year)
{
	isLeapYear(year);
	if (leap == true)
	{
		if (month == 1)
		{
			monthValue = 6;
		}
		if (month == 2)
		{
			monthValue = 2;
		}
	}
	else
	{
		switch (month)
		{
			case 1:
				monthValue = 0;
				break;
			case 2:
				monthValue = 3;
				break;
			case 3:
				monthValue = 3;
				break;
			case 4:
				monthValue = 6;
				break;
			case 5:
				monthValue = 1;
				break;
			case 6:
				monthValue = 4;
				break;
			case 7:
				monthValue = 2;
				break;
			case 8:
				monthValue = 5;
				break;
			case 9:
				monthValue = 5;
				break;
			case 10:
				monthValue = 0;
				break;
			case 11:
				monthValue = 3;
				break;
			case 12:
				monthValue = 5;
				break;
		}
	}
	return monthValue;
}
//post: month value is determined based on month and if leap == true.
//pre: user enters month, day, and year.
int dayOfWeek(int month, int day, int year)
{
	if ((month == 1) && (day > 31))
	{
		cout << "January only has 31 days." << endl;
		cin >> day;
	}
	if (month == 2)
	{
		isLeapYear(year);
		if ((leap == false) && (day >28))
		{
			cout << "February only has 28 days." << endl;
			cin >> day;
		}
		else
		{
			cout << "February only has 29 days." << endl;
			cin >> day;
		}
	}
	if ((month == 3) && (day > 31))
	{
		cout << "March only has 31 days." << endl;
		cin >> day;
	}
	if ((month == 4) && (day >30))
	{
		cout << "April only has 30 days" << endl;
		cin >> day;
	}
	if ((month == 5) && (day > 31))
	{
		cout << "May only has 31 days." << endl;
		cin >> day;
	}
	if ((month == 6) && (day > 30))
	{
		cout << "June only has 30 days." << endl;
		cin >> day;
	}
	if ((month == 7) && (day > 31))
	{
		cout << "July only has 31 days." << endl;
		cin >> day;
	}
	if ((month == 8) && (day > 31))
	{
		cout << "August only has 31 days." << endl;
		cin >> day;
	}
	if ((month == 9) && (day > 30))
	{
		cout << "May only has 30 days." << endl;
		cin >> day;
	}
	if ((month == 10) && (day > 31))
	{
		cout << "May only has 31 days." << endl;
		cin >> day;
	}
	if ((month == 11) && (day > 30))
	{
		cout << "May only has 30 days." << endl;
		cin >> day;
	}
	if ((month == 12) && (day > 31))
	{
		cout << "May only has 31 days." << endl;
		cin >> day;
	}
	dayValue = (((day + (getMonthValue(month,year)) + (getYearValue(year)) + (getCenturyValue(year))) % 7));
	return dayValue;
}
//Post: number of days is checked and a value is calculated with the help of three other functions.
//Pre: user has entered a day month and year.
string nameOfDay(int day)
{
	dayOfWeek(month, day, year);
	switch (dayValue)
	{
	case 0:
		dayName = "Sunday";
		break;
	case 1:
		dayName = "Monday";
		break;
	case 2:
		dayName = "Tuesday";
		break;
	case 3:
		dayName = "Wednesday";
		break;
	case 4:
		dayName = "Thursday";
		break;
	case 5:
		dayName = "Friday";
		break;
	case 6:
		dayName = "Saturday";
		break;
	}
	return dayName;
}
//post: name of day is given based on the value of the day recived from dayOfWeek function.