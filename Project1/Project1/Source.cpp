#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void reverse(char* front, char* rear);
// Precondition: The front and rear are pointing to the front
//               and rear of a C-string, respectively
// Postcondition: The C-string is reversed

string* addEntry(string* dynamiccArray, int& size, string newEntry);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array

void print(const string* dynamicArray, int size);
// Precondition: dynamicArray point to a array of strings with give size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line forllowed by its index

int main()
{
	char inputString[40]; char* front, * rear;
	cout << "Please type a sentence:" << endl; //user input
	cin.getline(inputString, 40);
	cout << "You entered: " << inputString << endl; //print input
	front = inputString; //assigning the pointer var front tofirst mem add of inputString 
	rear = inputString + strlen(inputString) - 1; //assigning the pointer var rear to last mem add of inputString
	reverse(front, rear); //calling reverse function
	cout << "This sentence reversed is: " << inputString << endl; //print reversed input

	int size = 5; typedef string* StringPtr; StringPtr dynamicArray; dynamicArray = new string[size]; string newEntry, entryToDelete;
	for (int i = 0; i < 5; i++) {
		cout << "Enter name #" << i + 1 << ": "; //prompts user to input a name, in an array that will hold 5 names
		cin >> dynamicArray[i];
	}

	for (int i = 0; i < 5; i++)
	{
		cout << "You entered" << i + 1 << ": " << dynamicArray[i] << endl;
	}
	cout << "You entered: "; print(dynamicArray, size);//print out dynamicArray
	cout << "Enter the new name you would like to add to the list: "; //new entry user input
	cin >> newEntry; cout << "You entered " << newEntry << endl;
	dynamicArray = addEntry(dynamicArray, size, newEntry); //calling addEntry and print 												 
	cout << "The list now contains: "; print(dynamicArray, size);
	cout << "Enter the name you would like to remove from the list: "; //delete entry user input
	cin >> entryToDelete; cout << "You entered " << entryToDelete << endl;
	dynamicArray = deleteEntry(dynamicArray, size, entryToDelete); //calling deleteEntry and print   
	cout << "The list now contains: "; print(dynamicArray, size);
	return 0;
}

void reverse(char* front, char* rear)
{
	char temp; while (front < rear)
	{
		temp = *front; *front = *rear;
		*rear = temp;
		front++;
		rear--;
	}
}


string* addEntry(string* dynamicArray, int& size, string newEntry)
{
	string* newArray; newArray = new string[size + 1]; //newArray 1 larger than dynamicArray

	for (int i = 0; i < size; i++) //assigns value of each index in dynamicArray to newArray 
	{
		newArray[size] = newEntry;//adding the newEntry to the last position in new Array

		newArray[i] = dynamicArray[i];

	}
	size++; //incrementing by one

	return newArray;
}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
	string* newArray; newArray = new string[size];

	for (int i = 0; i < size; i++)
	{
		if (dynamicArray[i] == entryToDelete) string* newArray = new string[size - 1]; //this decrements the size of the array if there is an entry for deletion
		for (int j = 0; j < size; j++)
		{
			dynamicArray[j] != entryToDelete;
			newArray[j] = dynamicArray[j];
		}
	}
	delete[] dynamicArray;
	return newArray;
}

void print(const string* dynamicArray, int size)
{
	for (int i = 0; i < size; i++) //print value for every index of dynamicArray 
		cout << dynamicArray[i] << endl; cout << endl;
}