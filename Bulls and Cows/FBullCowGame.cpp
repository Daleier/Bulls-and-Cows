#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

EResetStatus FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 3;
	const FString HIDDEN_WORD = "planet";

	bGameIsWon = false;
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
	return bGameIsWon;
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
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length(); //assuming same length as guess

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

