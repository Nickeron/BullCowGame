#include "FBullCowGame.h"
#include <iostream>
#include <map>

#define TMap map

using int32 = int;
using FString = string;
using namespace std;


FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return lround(2.5 * GetHiddenWordLength()); }
int32 FBullCowGame::GetCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return myHiddenWord.length(); }

bool FBullCowGame::isGameWon() const { return bIsGameWon; }

EWordStatus FBullCowGame::checkGuessValidity(FString Guess) const {
	TMap<char, bool> letterSeen;
	for (auto letter : Guess)
	{
		if (!isalpha(letter))
			return NotAlpha;
		else
		{
			letter = tolower(letter);
			if (letterSeen[letter])
				return NotIsogram;
			else letterSeen[letter] = true;
		}
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
	int RandIndex = rand() % 30; //generates a random number between 0 and 3
	myHiddenWord = aIsograms[RandIndex];
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
