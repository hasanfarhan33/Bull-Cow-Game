// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{

    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Else checking PlayerGuess
    {
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("You have won!"));
            EndGame();
        }
        else
        {
            if (Input.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The hidden word is %i characters long. \nYou have lost."), HiddenWord.Len());
                EndGame();
            }
        }
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

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to the Bull Cows game."));

    //Setting up game
    HiddenWord = TEXT("cake");
    Lives = 4;
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess. \nPress Enter to continue..."));

    //prompt player to guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again"));
}