// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the Bull Cows game."));
    PrintLine(TEXT("Press Enter to continue"));

    InitGame();

    //prompt player to guess
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();

    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You have won!"));
    }
    else
    {
        PrintLine(TEXT("You lose!"));
    }
    //Check if Isogram
    //Prompt to guess again
    //Check right number char
    //Prompt to guess again

    //Remove life

    //Check if lives > 0
    //IF yes guess again
    //Show remaining lives
    //If no show game over and hidden word
    //prompt play again, press enter to play again
    //check user input
    //Play again or quit
}

void UBullCowCartridge::InitGame()
{
    //Setting up game
    HiddenWord = TEXT("cake");
    Lives = 4;
}