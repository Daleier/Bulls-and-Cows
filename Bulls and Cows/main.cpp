#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
std::string GetGuess();
void PlayGame();
bool AskToPlayAgain();

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
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

std::string GetGuess() 
{
	//get a guess from the player
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

void PlayGame()
{
	FBullCowGame BCGame; //create a new instance of the game

	//loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 0;NUMBER_OF_TURNS > count; count++) {
		std::string Guess = GetGuess();
		//repeat the guess back to the player
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y'); //exit the application
}
