#pragma once
#include "FBullCowGame.h"
#include <map>
//unreal engine syntax
#define TMap std::map

FBullCowGame::FBullCowGame()
{
	Reset();
}

//getters
int FBullCowGame::GetCurrentTry() const{ return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const{ return bGameIsWon; }

/*
Reinitializes the status of the game.
TODO add more hidden words (isograms).
*/
EResetStatus FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";

	bGameIsWon = false;
	MyMaxTries = GetMaxTries();
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	return EResetStatus::OK;
}

int FBullCowGame::GetMaxTries() const { 
	TMap<int32, int32> WordLengthToMaxTries{ {3,4},{4,7},{5,10},{6,15},{7,15} }; //first number is the length of the hidden word, second is the number of turns
	return WordLengthToMaxTries[MyHiddenWord.length()]; 
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) { //not isogram
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) { //not lowercase TODO implement new method
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) { //length wrong
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK; 
	}
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length(); //assuming same length as guess word

	//lop all leter in the hidden word
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		//compare letters against the guess
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { // increments bulls
					BullCowCount.Bulls++;
				}
				else { // increments cows
					BullCowCount.Cows++;
				}

			}
		}
	}
	if (BullCowCount.Bulls == HiddenWordLength) {
		bGameIsWon = true;
	}
	else{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{	
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; //setup map
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}

	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	for (auto Letter : Word) {
		if (!islower(Letter)) { //if its cap return false
			return false;
		}
	}
	return true;
}

