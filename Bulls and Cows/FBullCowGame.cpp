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

EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
	return EWordStatus::OK; // TODO make actual error
}

// receive valid Guess, increment turn, returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment turn number
	MyCurrentTry++;

	//setup turn struct var
	FBullCowCount FBullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	//loop checking guess with the hidding word
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
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

