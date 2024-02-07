//author: Katelyn Junker
//Purpose:
#include<iostream>
#include<iomanip>
using namespace std;
int arr[];
int size, minimum, start_index,minimum_index,choice;
void fill_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is filled from keyboard
void print_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is printed to screen with 5 elements per line
int linear_search(int arr[], int size, int key);
// pre-condition: arr has given size
// post-condition: The index of first occurrence of key in arr is returned. If the key cannot be found in arr, -1 is returned
void swap_values(int& v1, int& v2);
// pre-condition: lower and higher value selected
// post-condition: lower value is placed in the index of the higher and vice versa
void select_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest
int smallest_index(const int arr[], int start_index, int size);
// pre-conditio: array filled
// post-condition: smallest value found and stored in min
void insert_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest
void bubble_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest
void menu();
// pre-condition: no choice is selected
// post-condition: choices are presented and one is selected
int main() {
	int a[9];
	cout << "1: Search for a number in an array.\n"
		<< "2: Sort an array from smallest to largest.\n "
		<< "3: Sort from smallest to largest with a insert sort\n"
		<< "4: Bubble sort used to sort array from smallest to largest\n"
		<< "5: Quit" << endl;
	menu();
	return 0;
}
void fill_array(int arr[], int size)
{
	cout << "please enter up to 9 numbers.\n"
		<<"if you wish to stop before 9 enter a negative number after your list"<< endl;
	size = 9;
	int index = 0;
	int next = 0;
	for (;index < size; index++)
	{
		cin >> next;
		if (next < 0)
		{
			break;
		}
		else
		{
			arr[index] = next;
		}
	}
	size = index;
}
void print_array(int arr[], int size)
{
	for (int index = 0; index < size; index++)
	{
		cout << arr[index] << " ";
	}
	cout << endl;
}
int linear_search(int arr[], int size, int key)
{
	bool found;
	found = false;
	int i = arr[0];
	while ((found == false) && (i < size))
	{
		if (i == key)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if (found == true)
	{
		return i;
	}
	else
	{
		return -1;
	}
}
void swap_values(int& v1, int& v2)
{
	int temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}
void select_sort(int arr[], int size)
{
	int i, j, imin;
	for (i = 0; i < size - 1; i++)
	{
		imin = i;
		for (j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[imin])
				imin = j;
			swap_values(arr[i], arr[imin]);
		}
	}
}
int smallest_index(const int arr[], int start_index, int size)
{
	minimum_index = start_index;
	minimum = arr[start_index];
	for (int index = start_index+1; index < size; index++)
	{
		if (arr[index] < minimum)
		{
			minimum = arr[index];
			minimum_index = index;
		}
	}
	return minimum_index;
}
void bubble_sort(int arr[], int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap_values(arr[j], arr[j + 1]);
			}
		}
	}
}
void menu()
{
	int a[9];
	do
	{
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				fill_array(a, 9);
				cout << "Enter the key you want to search: ";
				int key;
				cin >> key;
				int index = linear_search(a, 9, key);
				if (index == -1)
					cout << "The key " << key << " is not in array\n";
				else
					cout << "The key " << key << " is the " << (index + 1) << " element in array\n";
				break;
			}
			case 2:
			{
				fill_array(a, 9);
				select_sort(a, 9);
				cout << "After sort, the array is:\n";
				print_array(a, 9);
				break;
			}
			case 3:
			{
				fill_array(a, 9);
				insert_sort(a, 9);
				cout << "After sort, the array is:\n";
				print_array(a, 9);
				break;
			}
			case 4:
			{
				fill_array(a, 9);
				bubble_sort(a, 9);
				cout << "After sort, the array is:\n";
				print_array(a, 9);
				break;
			}
			case 5:
			{
				cout << "Thank you for using the array functions\n";
				break;
			}
			default:
			{
				cout << "Wrong choice. Please choose from menu: ";
				break;
			}
		}
	} while (choice != 5);
}
void insert_sort(int arr[], int size)
{
		int key, j;
		for (int i = 1; i < size; i++) {
			key = arr[i];
			j = i;
			while (j > 0 && arr[j - 1] > key) {
				arr[j] = arr[j - 1];
				j--;
			}
			arr[j] = key;
		}
}