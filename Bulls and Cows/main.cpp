#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void GetGuessAndPrintBack();

//start of the aplication
int main()
{
	PrintIntro();
	GetGuessAndPrintBack();

	return 0;
}

//introduce the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	cout << endl;
}

//get a guess from the player
void GetGuessAndPrintBack() 
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	//repeat the guess back to the player
	cout << "Your guess was: " << Guess << endl;
}