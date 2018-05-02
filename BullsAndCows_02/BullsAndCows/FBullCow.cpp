#include "FBullCow.h"
#include <map>
#define TMap std::map

FBullCow::FBullCow() { Reset(); }

int32 FBullCow::MaxTries() const { return MyMaxTries; }
int32 FBullCow::CurrentTry() const { return MyCurrentTries; }
int32 FBullCow::GetHiddenWordLenght() const { return MyHiddenWord.length(); }
bool FBullCow::IsGameWon() const { return bGameIsWon; }


void FBullCow::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTries = 1;

	bGameIsWon = false;
	return;
}


EGuessStatus FBullCow::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLower(Guess)) {
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
	if (BullCowCount.Bulls == HiddenWordLenght)
		bGameIsWon = true;
	else bGameIsWon = false;
	return BullCowCount;
}

bool FBullCow::IsIsogram(FString Word) const {

	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) {
		Letter = tolower(Letter);
		if (LetterSeen[Letter] == true)
			return false;
		else
			LetterSeen[Letter] = true;
	}

		return true;
}

bool FBullCow::IsLower(FString Word) const
{
	for (auto Letter : Word) {
		if (!islower(Letter))
			return false;
	}
	return true;
}
