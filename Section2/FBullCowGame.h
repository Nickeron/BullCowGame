#pragma once
#include <string>

using namespace std;
using FString = string;
using int32 = int;

enum EWordStatus
{
	OK,
	NotAlpha,
	NotIsogram,
	Longer,
	Shorter
};

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows	= 0;
};

class FBullCowGame
{
public:
	FBullCowGame();

	void Reset(); // Make a more rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool isGameWon() const;
	EWordStatus checkGuessValidity(FString) const;

	// Counts Bulls and Cows 
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 myCurrentTry = 1;
	FString myHiddenWord;
	bool bIsGameWon = false;
	string aIsograms[30] = { "sir", "sad", "mud", "rob", "his", "job", "harm",	"hume",
							"gasp",	"curl", "wore",	"enjoy", "capes", "honey", "chore",
							"posed", "surely", "inject", "tinker",	"morgue", "swamped",
							"objects", "conflates", "equator", "debtors", "workings",
							"cultivar", "grownups", "flatworks","fireblast" };
};

