#include <iostream>
#include <string>
#include "Main.h"
#include "FBullCow.h"

/*
std::
*/

int main() {

	printIntro();
	playGame();


	return 0;
}

void playGame()
{
	FBullCow BCGame;

	int i;
	constexpr int TURNS = 5;

	do {
		for (i = 0; i < TURNS; i++)
			getGuessprint();
	} while (askReplay());

}

void printIntro() {
	constexpr int LENGHT = 5;

	//Introduce
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Guess the " << LENGHT << " letter isogram word.\n\n";
	return;
}

std::string getGuessprint() {
	//Get a guess
	std::string Guess = "";

	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess);

	//repeat the guess back
	std::cout << "Guess is: " << Guess << "\n\n";

	return Guess;
}

bool askReplay() {
	std::cout << "Do you want to play again? (y/n): ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}