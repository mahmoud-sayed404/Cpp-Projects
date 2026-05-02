#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
	int guesses = 5;
	int answer, guess;
	srand(time(0));
	answer = rand() % 20;
	cout << "Welcome Guessing game.\n";
	cout << "I'm thinking of anumber between 0 to 20.\n";
	for (int i = 0; i < guesses; i++)
	{
		cout << "Guess #" << i + 1 << ":";
		cin >> guess;
		if (guess != answer)
		{
			if (guess > answer)
				cout << "Too high!\n";
			if (guess < answer)
				cout << "Too low!\n";
		}
		else {

			cout << "you won\n";

		}


	}

	return 0;
}
