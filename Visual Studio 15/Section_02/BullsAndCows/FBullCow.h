#pragma once
#include<string>

using FString = std::string;
using int32 = int;

enum class EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Lenght,
	Not_Lowercase
};

enum class EResetStatus {
	No_Hidden_Word,
	OK
};

struct BullCowCount {	int32 Bulls = 0, Cows = 0;};

class FBullCow {
public:
	FBullCow();

	void Reset(); //Adjust after
	int32 MaxTries() const;
	int32 CurrentTry() const;
	int32 GetHiddenWordLenght() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; //Adjust after

	BullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTries = 1;
	int32 MyMaxTries = 5;
	FString MyHiddenWord;
	bool bGameIsWon;
};