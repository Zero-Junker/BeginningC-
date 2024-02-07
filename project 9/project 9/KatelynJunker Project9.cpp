//Katelyn Junker
// project 9 sums and string length
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int sumResult, intiger, length,counter;
char again;
char scentence[30];
int sum(int intiger);
int str_length(char* str);
int main()
{
	again = 'y';
	counter = 0;
	do
	{
		cout << "Please enter a positive intiger: ";
		cin >> intiger;
		cout << intiger << endl;
		sum(intiger);
		cout << "The sum of your intiger is: " << sumResult << endl;
		cout << "Please enter a sentence: ";
		cin >> scentence;
		cout << scentence << endl;
		counter = str_length(scentence);
		cout << "The scentence is " << counter << " characters long including spaces." << endl;
		cout << "would you like to go again?" << endl;;
		cin >> again;
		if ((again != 'y') && (again != 'n'))
		{
			cout << "Please enter y or n." << endl;
		}
	} while (again != 'n');
}
int sum(int intiger)
{

	if (intiger > 0)
	{
		sumResult += intiger;
		intiger--;
		sum(intiger);
	}
	return sumResult;
}
int str_length(char* str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + str_length(str + 1);
}