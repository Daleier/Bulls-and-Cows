#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	void Reset();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString);
	// create method for checking and countig all the bulls and cows and increasing the turn count 

private:
	//initialisation in the constructor
	int32 MyCurrentTry;
	int32
		MyMaxTries;
};