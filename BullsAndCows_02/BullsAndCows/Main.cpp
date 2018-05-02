#pragma once

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
	int32 i;

	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		BCGame.Reset();
		while ( !BCGame.IsGameWon() && BCGame.CurrentTry() <= BCGame.MaxTries()) {
			do {


				FText Guess = getGuessprint();

				Status = BCGame.CheckGuessValidity(Guess);
				switch (Status) {

				case EGuessStatus::Wrong_Lenght: std::cout << "Please write a " << BCGame.GetHiddenWordLenght() << " letter word.\n"; break;
				case EGuessStatus::OK: {
					BullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
					std::cout << "Bulls = " << BullCowCount.Bulls << ". Cows = " << BullCowCount.Cows << std::endl; break;}
				default:std::cout << "Error.\n";
					break;
				}
			} while (Status != EGuessStatus::OK);


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