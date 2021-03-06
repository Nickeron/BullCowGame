// main.cpp : Defines the entry point for the console application.
//
//   ______   __  __   __       __       ______          ______   ______   __     __   ______    
//  /\  == \ /\ \/\ \ /\ \     /\ \     /\  ___\        /\  ___\ /\  __ \ /\ \  _ \ \ /\  ___\   
//  \ \  __< \ \ \_\ \\ \ \____\ \ \____\ \___  \       \ \ \____\ \ \/\ \\ \ \/ ".\ \\ \___  \  
//   \ \_____\\ \_____\\ \_____\\ \_____\\/\_____\       \ \_____\\ \_____\\ \__/".~\_\\/\_____\ 
//    \/_____/ \/_____/ \/_____/ \/_____/ \/_____/        \/_____/ \/_____/ \/_/   \/_/ \/_____/ 
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
			cout << "\n\tBulls = " << bullCowCount.Bulls << " Cows = " << bullCowCount.Cows << endl;
		else {
			cout << "\n\t###############################################################\n";
			cout << "\t#                                                             #\n";
			cout << "\t#             You WON!!! Congratulations!        /\\           #\n";
			cout << "\t#                                              _(  )_         #\n";
			cout << "\t#                                             ( `==' )        #\n";
			cout << "\t#                                               '\\/`          #\n";
			cout << "\t#                                                             #\n";
			cout << "\t###############################################################\n";
		}
	}
	if (!BullCowGame.isGameWon())
		cout << "\n\n\tI am sorry, but you lost :-(\n";
}

void PrintIntro()
{
	// Introduce the game
	BullCowGame.Reset();
	string printNum;
	int32 maxTries = BullCowGame.GetMaxTries();
	if (maxTries > 9)
		printNum = to_string(maxTries);
	else
		printNum = " "+to_string(maxTries);
	cout << "\n\n\t###############################################################\n";
	cout << "\t#                                                             #\n";
	cout << "\t#   ((...))         ((...))         ((...))           L...L   #\n";
	cout << "\t#   ( o o )         ( x x )         ( O O )          < o o >  #\n";
	cout << "\t#    \\   /           \\   /           \\   /            \\   /   #\n";
	cout << "\t#     ^_^             ^_^            (`_`)             ^_^    #\n";
	cout << "\t#                                                             #\n";
	cout << "\t###############################################################\n";
	cout << "\t#                                                             #\n";
	cout << "\t#              Welcome to Bulls and Cows!                     #\n";
	cout << "\t#          A find-the-word-I-am-thinking-of game!             #\n";
	cout << "\t#   Can you guess the " << BullCowGame.GetHiddenWordLength() << " letter isogram I'm thinking of?       #\n";
	cout << "\t#                                                             #\n";
	cout << "\t#                  You'll have " << printNum << " tries:                      #\n";
	cout << "\t#                                                             #\n";
	cout << "\t###############################################################\n";
}

FText GetUserGuess()
{
	EWordStatus guessStatus = NotIsogram;
	FText Guess = "";
	do {
		// Get a guess from the player
		cout << "\n\tCurrent Try " << BullCowGame.GetCurrentTry() << "/" ;
		cout << BullCowGame.GetMaxTries() << ". Enter your guess below:\n\t> ";
		getline(cin, Guess);
		guessStatus = BullCowGame.checkGuessValidity(Guess);
		switch (guessStatus)
		{
		case Shorter:
			cout << "\n\t*** Your answer is shorter than expected!" << endl;
			break;
		case Longer:
			cout << "\n\t*** Your answer is longer than expected!" << endl;
			break;
		case NotAlpha:
			cout << "\n\t*** Your answer contains not permitted characters!" << endl;
			break;
		case NotIsogram:
			cout << "\n\t*** Your answer is NOT an ISOGRAM \n\t*** (Contains repeated letters)!" << endl;
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
	cout << "\n\t\t\tDo you want to play again?\n\t>";
	FText response = "";
	getline(cin, response);
	yesHeDoes = (response[0]=='y') || (response[0] == 'Y');
	return yesHeDoes;
}