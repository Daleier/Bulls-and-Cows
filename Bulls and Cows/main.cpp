/*This is the console executable, that makes use of the BullCow class
This acts ast the view in a MVC pattern, and is responsible for al user interaction.
For game logic see the FBullCowGame class*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; //create a new instance of the game

//start of the aplication
int main()
{
	bool bPlayAgain;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
		std::cout << std::endl;
	} 
	while (bPlayAgain);
	
	return 0; //end of the applications
}

void PrintIntro() 
{
	//introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " <<  BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

void PlayGame()
{
	BCGame.Reset();
	const int32 MaxTries = BCGame.GetMaxTries();
	//loop for the number of turns asking for guesses while the game is not won
	//and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries ) {	// TODO change from for to while loop
		FText Guess = GetValidGuess(); // TODO make loop checking valid guesses


		//Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
}

FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";

	do {
		int32 CurrentGuess = BCGame.GetCurrentTry();
		//get a guess from the player
		std::cout << "Try " << CurrentGuess << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Enter a " << BCGame.GetHiddenWordLength() << " letters word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "You have to enter an isogram.\n";
		case EGuessStatus::Not_Lowercase:
			std::cout << "Enter all letters in lowercase.\n";
			break;
		default: //valid guess
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); //loops until there are no input errors

	return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same word? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y'); //exit the application
}

void PrintGameSummary() 
{
	if (BCGame.IsGameWon()) {
		std::cout << "YOU WIN! WELL DONE.\n";
	}
	else {
		std::cout << "YOU LOST! BETTER LUCK NEXT TIME.\n";
	}

}