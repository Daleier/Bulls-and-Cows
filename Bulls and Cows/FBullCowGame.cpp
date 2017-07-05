#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

EResetStatus FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	return EResetStatus::OK;
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) { //not isogram
		return EGuessStatus::Not_Isogram;
	}
	else if (false) { //not lowercase
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) { //length wrong
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK; 
	}
}

// receives a VALID Guess, increment turn, returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount FBullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length(); //assuming same length as guess

	//lop all leter in the hidden word
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		//compare letters against the guess
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { // increments bulls
					FBullCowCount.Bulls++;
				}
				else { // increments cows
					FBullCowCount.Cows++;
				}

			}
		}
	}
	return FBullCowCount;
}

