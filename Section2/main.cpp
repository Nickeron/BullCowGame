// main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame(string &Guess);
string GetUserGuess();

int main()
{
	// Introduce the game
	PrintIntro();

	// Get a guess from the player
	string Guess = "";

	PlayGame(Guess);

    return 0; // Exit the Application
}

void PlayGame(string &Guess)
{
	constexpr int NUMBER_OF_TURNS = 5;

	for (int repeat = 1; repeat <= NUMBER_OF_TURNS; repeat++) 
		{
		Guess = GetUserGuess();

		// Display the guess back to the user
		cout << "Your guess was " << Guess << endl;
	}
}

void PrintIntro()
{
	// Introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a first game!\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking off?\n";
}

string GetUserGuess()
{
	// Get a guess from the player
	string Guess = "";
	cout << "Enter your guess below:\n";
	getline(cin, Guess);
	return Guess;
}