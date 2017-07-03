/*This is the console executable, that makes use of the BullCow class
This acts ast the view in a MVC pattern, and is responsible for al user interaction.
For game logic see the FBullCowGame class*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();

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
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

FText GetGuess() 
{
	int32 CurrentGuess = BCGame.GetCurrentTry();
	//get a guess from the player
	std::cout << "Try " << CurrentGuess << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

void PlayGame()
{
	//loop for the number of turns asking for guesses
	constexpr int32 NUMBER_OF_TURNS = 5;
	// TODO change from for to while loop
	for (int32 count = 0;NUMBER_OF_TURNS > count; count++) {
		FText Guess = GetGuess(); // TODO make loop checking valid guesses

		//Submit valid guess to the game
		// Print number of bulls and cows

		//repeat the guess back to the player
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
	//TODO summarise game

}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y'); //exit the application
}
