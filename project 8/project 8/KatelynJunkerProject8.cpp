// Katelyn Junker
// scores and palindromes
#include<iostream>
#include<vector>
#include<numeric>
#include <algorithm>
using namespace std;
char againScores, againPalindrome;
bool palindrome;
int minimum, maximum, average,numScores, numCharacters;
string scentence;
vector<int> scores;
//Declaring functions
void getScores(vector<int>& v);
void printScores(vector<int>& v);
bool is_palindrome(string scentence);
int findMinimum(vector<int> &v);
int findMaximum(vector<int> &v);
int calculateAverage(vector<int> &v);
bool isSpace(unsigned char c);
int main()
{
	againScores = 'y';
	againPalindrome = 'y';
	do
	{
		getScores(scores);
		printScores(scores);
		findMinimum(scores);
		cout << "The minimum score is " << minimum << endl;
		findMaximum(scores);
		cout << "The maximum score is " << maximum << endl;
		calculateAverage(scores);
		cout << "The average score is " << average << endl;
		cout << "Would you like to enter scores again (y or n)" << endl;
		cin >> againScores;
		if ((againScores != 'y') && (againScores != 'n'))
		{
			cout << "Please enter y or n" << endl;
			cin >> againScores;
		}
	} while (againScores == 'y');
	do
	{
		cout << "Please enter a scentence." << endl;
		cin >> scentence;
		is_palindrome(scentence);
		if (palindrome == false)
		{
			cout << "Thise scentence is not a palindrome." << endl;
		}
		else
		{
			cout << "This scentence is a palindrome." << endl;
		}
		cout << "Would you like to enter another scentence (y or n)" << endl;
		cin >> againPalindrome;
		if ((againPalindrome != 'y') && (againPalindrome != 'n'))
		{
			cout << "Please enter y or n" << endl;
			cin >> againPalindrome;
		}
	} while (againPalindrome == 'y');

}
// defining functions
//precondition: user inputs scores
void getScores(vector<int> &v)
{
	int index = 0;
	int next;
	cout << "Please enter your scores. (enter a negative number when finished)" << endl;
	for (int i = 0; ; i++)
	{
		cin >> next;
		if (next < 0)
		{
			break;
		}
		index++;
		scores.push_back(next);
	}
	numScores = index;
}
//postcondition: vector is filled with all of the scores and the number of scores is saved
//precondition: min,max,average, and number of scores is found
void printScores(vector<int>& v)
{
	for (int i = 0; i < numScores; i++)
	{
		cout << scores[i] << endl;
	}
	cout << "There are " << numScores << " scores." << endl;
}
//postcondition: all values are printed out on the screen
//precondition: user enters a scentence
bool is_palindrome(string scentence)
{
	palindrome = false;
	numCharacters = sizeof(scentence);
	int x = numCharacters;
	std::transform(scentence.begin(), scentence.end(), scentence.begin(),
			[](unsigned char c) { return std::tolower(c); });
	scentence.erase(std::remove_if(scentence.begin(), scentence.end(), isSpace), scentence.end());
	if (equal(scentence.begin(), scentence.begin() + scentence.size() / 2, scentence.rbegin()))
	{
		palindrome = true;
	}
	return palindrome;
}
//postcondition: true is returned if scentence is a palindrome otherwise it returns false
//precondition: scores are entered
int findMinimum(vector<int> &v)
{
	minimum = *min_element(scores.begin(), scores.end());
	return minimum;
}
// postcondition: smallest value in vector is found and saved
//precondition: scores are entered
int findMaximum(vector<int> &v)
{
	maximum = scores[0];
	for (int i = 0; i < numScores; i++)
	{
		if (scores[i] > maximum)
		{
			maximum = scores[i];
		}
	}
	return maximum;
}
//postcondition: largest value is found
//precondition: scores are entered
int calculateAverage(vector<int>& v)
{
	average =accumulate(scores.begin(), scores.end(), 0);
	average = (average / numScores);
	return average;
}
// postcondition: the average of the scores is calculated
bool isSpace(unsigned char c) 
{
	return (c == ' ' || c == '\n' || c == '\r' ||
		c == '\t' || c == '\v' || c == '\f');
}