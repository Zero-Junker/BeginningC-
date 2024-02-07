// author: Katelyn Junker
// a simple game of 23
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	// declare and initialise variables
	int toothpicks, usersLastPick, computerPick;
	char playAgain;
	playAgain = 'y';
	toothpicks = 23;
	// welsome message
	cout << "Let's play a game of 23!" << endl;
	// game
	do
	{
		// ask for and record the number of toothpicks the user wishes to take.
		cout << "enter the number of sticks you wish to take (between 1 and 3):" << endl;
		cin >> usersLastPick;
		if ((usersLastPick != 1) && (usersLastPick != 2) && (usersLastPick != 3))
		{
			cout << "Invalid input, please enter 1,2, or 3." << endl;
			cin >> usersLastPick;
		}
		if ((toothpicks == 1) && ((usersLastPick == 2) || (usersLastPick == 3)))
		{
			cout << "There is only 1 toothpick left please enter 1" << endl;
			cin >> usersLastPick;
		}
		else
		{
			if ((toothpicks == 2) && (usersLastPick == 3))
			{
				cout << "There are only 2 toothpicks left please enter 1 or 2." << endl;
				cin >> usersLastPick;
			}
		}
		toothpicks = (toothpicks - usersLastPick);
		cout << "There are " << toothpicks << " toothpicks left." << endl;
		if (toothpicks == 0) // result of taking the last toothpick
		{
			cout << "You Loose!" << endl;
			cout << "Play again?" << endl;
			cin >> playAgain;
			if ((playAgain == 'y') || (playAgain == 'Y')) // should the game begin again
			{
				toothpicks = 23;
			}
			else
			{
				if ((playAgain == 'n') || (playAgain == 'N'))
				{
					cout << "Thanks for playing!" << endl;
					break;
				}
				else
				{
					cout << "invalid input, please enter Y or N" << endl; // result of entering anything other than y,Y,n, or N
					cin >> playAgain;
				}
			}
		}
		else
		{
			switch (toothpicks) // computer's plays
			{
			case 1: // computer looses
				toothpicks--;
				cout << "Computer takes the last toothpick." << endl;
				cout << "You win!" << endl;
				cout << "Play again?" << endl;
				cin >> playAgain;
				if ((playAgain == 'y') || (playAgain == 'Y'))
				{
					toothpicks = 23;
				}
				else
				{
					if ((playAgain == 'n') || (playAgain == 'N'))
					{
						cout << "Thanks for playing!" << endl;
						break;
					}
					break;
			case 2: // computer leaves one toothpick
				toothpicks--;
				cout << "Computer takse 1 toothpick." << endl;
				cout << "There is 1 toothpick left." << endl;
				break;
			case 3: // computer leaves one toothpick
				toothpicks -= 2;
				cout << "Computer takes 2 toothpicks." << endl;
				cout << "There is 1 toothpick left." << endl;
				break;
			default: // how many toothpicks should the computer take
				computerPick = (4 - usersLastPick);
				toothpicks -= computerPick;
				cout << "Computer takes " << computerPick << " toothpicks." << endl;
				cout << "There are " << toothpicks << " toothpicks left." << endl;
				}
			}
		}
	} while ((toothpicks > 0) && ((playAgain == 'y') || (playAgain == 'Y'))); // while there is more than 0 toothpicks and the player answers y or Y to play again
	return 0;
}