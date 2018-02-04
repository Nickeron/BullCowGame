#include "FBullCowGame.h"
#include <iostream>

using int32 = int;
using FString = string;
using namespace std;


FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return myMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return myHiddenWord.length(); }

bool FBullCowGame::isGameWon() const { return bIsGameWon; }

EWordStatus FBullCowGame::checkGuessValidity(FString Guess) const {
	for (char letter : Guess)
	{
		if (!isalpha(letter))
			return NotIsogram;
	}
	if (Guess.length() < GetHiddenWordLength())
		return Shorter;
	else if (Guess.length() > GetHiddenWordLength())
		return Longer;
	else 
		return OK;
}

void FBullCowGame::Reset()
{
	myCurrentTry = 1;
	constexpr int32 MAX_TRIES = 5;
	myMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "kogiou";
	myHiddenWord = HIDDEN_WORD;
	bIsGameWon = false;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString guessWord)
{
	myCurrentTry++;
	FBullCowCount bullCowCounter;

	int32 lengthHiddenWord = myHiddenWord.length();

	for (int32 hiddenLetter = 0; hiddenLetter < lengthHiddenWord; hiddenLetter++) {
		for (int32 guessLetter = 0; guessLetter < lengthHiddenWord; guessLetter++) {
			if (guessWord[guessLetter] == myHiddenWord[hiddenLetter]) {
				if (guessLetter == hiddenLetter)	bullCowCounter.Bulls++;
				else bullCowCounter.Cows++;
			}
		}
	}
	if (bullCowCounter.Bulls == lengthHiddenWord)
		bIsGameWon = true;
	else
		bIsGameWon = false;
	return bullCowCounter;
}
