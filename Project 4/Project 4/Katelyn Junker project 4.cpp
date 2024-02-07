// Author: Katelyn Junker
// tempeture at depth
#include <iostream>
#include <cmath>
using namespace std;
// declaring varriables.
double depth, celcius, farhrenheit;
char again;
void print_introduction() // prints introduction.
{
	cout << "Hello! This program will caalculate the temperature of the earth at any depth!" << endl;
}
double celcius_at_depth(double depth) // calculate celcius based on fahrenheit.
{
	celcius = ((10 * depth) + 20);
	return celcius;
}
double celsius_to_fahrenheit(double celcius) // calculate fahrenheit based on celcius.
{
	farhrenheit = ((1.8 * celcius) + 32);
	return farhrenheit;
}
void print_conclution(double depth) // read out the two temperatures.
{
	 celcius_at_depth(depth);
	 celsius_to_fahrenheit(celcius);
	cout << "The temperature of the earth at " << depth << "kms is " << celcius << " celcius and " << farhrenheit << " fahrenheit." << endl;
}
int main()
{
	again = 'y';
	print_introduction();
	do
	{
		cout << "please enter a depth in km." << endl;
		cin >> depth;
		print_conclution(depth);
		cout << "Would you like to enter another depth? (y or n)" << endl;
		cin >> again;
	} while ((again == 'y') || (again == 'Y')); // while the user is entering y or Y the program will continue.
	return 0;
}