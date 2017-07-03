#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	void Reset();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string);
	// create method for checking and countig all the bulls and cows and increasing the turn count 

private:
	//initialisation in the constructor
	int MyCurrentTry;
	int MyMaxTries;
};