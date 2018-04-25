#pragma once
#include<string>

class FBullCow {
public:
	void Reset(); //Adjust after
	int MaxTries();
	int CurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string); //Adjust after

private:
	int MyCurrentTries();
	int MyMaxTries;
};