// main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using namespace std;
using FText = string;
using int32 = int;

void PrintIntro();
void PlayGame(FText &Guess);
FText GetUserGuess();
bool AskToPlayAgain();

FBullCowGame BullCowGame;

int main()
{
	bool playAgain = false;
	FText Guess = "";

	do
	{
	// Introduce the game
	PrintIntro();
	
	// Get a guess from the player
	PlayGame(Guess);

	// Ask the player if they want to play again
	playAgain = AskToPlayAgain();

	}while (playAgain);
	
	return 0; // Exit the Application
}

void PlayGame(FText &Guess)
{
	int32 maxTries = BullCowGame.GetMaxTries();

	while (!BullCowGame.isGameWon() && BullCowGame.GetCurrentTry() <= maxTries)
	{
		Guess = GetUserGuess();
		FBullCowCount bullCowCount = BullCowGame.SubmitValidGuess(Guess);
		if (!BullCowGame.isGameWon())
			cout << "\nBulls = " << bullCowCount.Bulls << " Cows = " << bullCowCount.Cows << endl;
		else
			cout << "\n\nYou WON!!! Congratulations! :-)\n";
	}
	if (!BullCowGame.isGameWon())
		cout << "\n\nI am sorry, but you lost :-(\n";
}

void PrintIntro()
{
	// Introduce the game
	cout << "\n\nWelcome to Bulls and Cows, a find-the-word-I-am-thinking-of game!\n";
	cout << "\nCan you guess the " << BullCowGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
	cout << "\nYou'll have " << BullCowGame.GetMaxTries() << " tries:\n";
	BullCowGame.Reset();
}

FText GetUserGuess()
{
	EWordStatus guessStatus = NotIsogram;
	FText Guess = "";
	do {
		// Get a guess from the player
		cout << "\nCurrent Try " << BullCowGame.GetCurrentTry() << ". Enter your guess below:\n> ";
		getline(cin, Guess);
		guessStatus = BullCowGame.checkGuessValidity(Guess);
		switch (guessStatus)
		{
		case Shorter:
			cout << "\n*** Your answer is shorter than expected!" << endl;
			break;
		case Longer:
			cout << "\n*** Your answer is longer than expected!" << endl;
			break;
		case NotIsogram:
			cout << "\n*** Your answer contains not permitted characters!" << endl;
			break;
		default:
			break;
		}
	} while (guessStatus != OK);
	return Guess;
}

bool AskToPlayAgain() 
{
	bool yesHeDoes = false;
	cout << "\nDo you want to play again?\n";
	FText response = "";
	getline(cin, response);
	yesHeDoes = (response[0]=='y') || (response[0] == 'Y');
	return yesHeDoes;
}