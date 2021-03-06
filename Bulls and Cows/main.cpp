/*This is the console executable, that makes use of the BullCow class
This acts ast the view in a MVC pattern, and is responsible for al user interaction.
For game logic see the FBullCowGame class*/
#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

//unreal engine syntax
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; //create a new instance of the game

int main()
{
	bool bPlayAgain;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
		std::cout << std::endl << std::endl;
	} 
	while (bPlayAgain);
	
	return 0; //end of the applications
}

void PrintIntro() 
{
	//introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "          (__)" << std::endl;
	std::cout << "          (oo)" << std::endl;
	std::cout << "   /-------\\/" << std::endl;	
	std::cout << "  / |     ||" << std::endl;
	std::cout << " *  ||----||" << std::endl;
	std::cout << "    ^^    ^^" << std::endl;

	std::cout << "Can you guess the " <<  BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n\n";
}

/*
Controls the general flow of a single the game.
*/
void PlayGame()
{
	BCGame.Reset();
	const int32 MaxTries = BCGame.GetMaxTries();
	//loop for the number of turns asking for guesses while the game is not won
	//and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries ) {
		FText Guess = GetValidGuess(); 
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " - Cows = " << BullCowCount.Cows << "\n\n";
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
		std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Enter a " << BCGame.GetHiddenWordLength() << " letters word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "You have to enter an isogram (no repeating leaters).\n";
			break;
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

/*
Asks the player if he wants to play again.
*/
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again using the same hidden word? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y'); //exit the application
}

/*
Prints a summary of every game after its finished.
*/
void PrintGameSummary() 
{
	if (BCGame.IsGameWon()) {
		std::cout << "YOU WIN! WELL DONE.\n";
	}
	else {
		std::cout << "YOU LOST! BETTER LUCK NEXT TIME.\n";
	}

}