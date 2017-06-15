#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();
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
		cout << endl;
	} 
	while (bPlayAgain);
	
	return 0; //end of the applications
}

void PrintIntro() 
{
	//introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	cout << endl;
}

string GetGuess() 
{
	//get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

void PlayGame()
{
	//loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 0;NUMBER_OF_TURNS > count; count++) {
		string Guess = GetGuess();
		//repeat the guess back to the player
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? (y/n) ";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y'); //exit the application
}
