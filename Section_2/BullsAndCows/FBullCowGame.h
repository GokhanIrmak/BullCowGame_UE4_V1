/*
The Game logic (no view or direct user interaction)
The game is a simple guess the word game based on Mastermind
*/

#pragma once
#include <string>

//to make syntax unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus 
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	//counts bulls & cows, and increases try number(#) assuming valid guess
	FBullCowCount SubmitValidGuess(FString);


private:
	//see const for initialization
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon=false;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};