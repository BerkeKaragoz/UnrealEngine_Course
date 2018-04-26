#include <iostream>
#include <string>

using FText = std::string;
using int32 = int;

#include "Main.h"
#include "FBullCow.h"

/*
std::
*/

FBullCow BCGame;

int main() {
	std::cout << BCGame.CurrentTry();

	printIntro();
	playGame();

	return 0;
}

void playGame()
{
	BCGame.Reset();
	int32 Maxtries = BCGame.MaxTries();

	std::cout << Maxtries << std::endl;

	int32 i;

	do {
		for (i = 0; i < Maxtries; i++) {
			FText Guess = getGuessprint();
			BullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

			std::cout << "Bulls = " << BullCowCount.Bulls << ". Cows = " << BullCowCount.Cows << std::endl;

		}
	} while (askReplay());
	
}

void printIntro() {
	constexpr int32 LENGHT = 5;

	//Introduce
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Guess the " << BCGame.GetHiddenWordLenght() << " letter isogram word.\n\n";
	return;
}

FText getGuessprint() {
	int32 Currenttry = BCGame.CurrentTry();

	//Get a guess
	FText Guess = "";

	std::cout << "Try " << Currenttry << ". Enter your guess: ";
	std::getline(std::cin, Guess);

	//repeat the guess back
	std::cout << "Guess is: " << Guess << "\n\n";

	return Guess;
}

bool askReplay() {
	std::cout << "Do you want to play again? (y/n): ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}