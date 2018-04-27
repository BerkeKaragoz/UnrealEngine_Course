#include "FBullCow.h"

FBullCow::FBullCow() { Reset(); }

int32 FBullCow::MaxTries() const { return MyMaxTries; }
int32 FBullCow::CurrentTry() const { return MyCurrentTries; }

int32 FBullCow::GetHiddenWordLenght() const{	return MyHiddenWord.length();}

void FBullCow::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTries = 1;

	return;
}

bool FBullCow::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCow::CheckGuessValidity(FString Guess) const
{
	if (false) {
		return EGuessStatus::Not_Isogram;
	}
	else if (false) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLenght()) {
		return EGuessStatus::Wrong_Lenght;
	}
	else {
		return EGuessStatus::OK;
	}
}

BullCowCount FBullCow::SubmitGuess(FString Guess)
{
	MyCurrentTries++;

	BullCowCount BullCowCount;

	int32 HiddenWordLenght = MyHiddenWord.length();

	int32 i, j;
	for (i = 0; i < HiddenWordLenght; i++) {
		for (j = 0; j < HiddenWordLenght; j++) {
			if (MyHiddenWord[i] == Guess[j]) {
				if (j == i)
					BullCowCount.Bulls++;
				else
					BullCowCount.Cows++;
			}
		}
	}

	return BullCowCount;
}
