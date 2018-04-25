#include <iostream>
#include <string>
#include "Main.h"

using namespace std;

void printIntro();
string getGuessprint();
bool askReplay();
int main() {

	printIntro();
	playGame();
	
	return 0;
}

void playGame()
{
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
	cout << "Welcome to Bulls and Cows!\n";
	cout << "Guess the " << LENGHT << " letter isogram word.\n\n";
	return;
}

string getGuessprint() {
	//Get a guess
	string Guess = "";

	cout << "Enter your guess: ";
	getline(cin, Guess);

	//repeat the guess back
	cout << "Guess is: " << Guess << "\n\n";

	return Guess;
}

bool askReplay() {
	cout << "Do you want to play again? (y/n): ";
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}