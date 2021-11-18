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
        ProcessGuess(Input);
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
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i number of lives"), Lives);
    PrintLine(TEXT("Type in your guess. \nPress Enter to continue..."));

    //prompt player to guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You have won!"));
        EndGame();
    }
    else
    {
        --Lives;
        PrintLine(TEXT("Lost a life"));
        if (Lives > 0)
        {
            PrintLine(TEXT("%i lives remaining"), Lives);
        }

        if (Lives > 0)
        {
            PrintLine(TEXT("Try again, you have %i lives remaining"), Lives);
        }
        else
        {
            PrintLine(TEXT("You have no lives left"));
            EndGame();
        }
    }
}