// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/****************************************************
* Programmer: Yiannis Poulos                        *
*													*
* Date: 1/16/19										*
*													*
* Purpose: This program functions as a simple		*
*          Rock, Paper, Scissors game between the	*
*		   user and the computer. 					*
*													*
*****************************************************/

#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int playerTotalWins = 0;
int computerTotalWins = 0;

//Generate a random move for the computer to play
char computerMove()
{
	char choice = NULL;

	int max = 3;
	int min = 1;

	//Generate random number between 1 and 3
	int randNum = rand() % (max - min + 1) + min;

	if (randNum == 1)	//If number is 1
		choice = 'R';   //Computer plays Rock

	else if (randNum == 2)	//If number is 2
		choice = 'P';		//Computer plays Paper

	else if (randNum == 3)	//If number is 3
		choice = 'S';		//Computer plays Scissors
	
	return choice;	//Return the computer's choice
}

//Display total wins for current round
void displayRoundStats(int player, int computer)
{
	cout << "Your Score: " << player
	     << "\tComputer Score: " << computer << endl;
}

//Display total wins for entire game
void displayFinalStats()
{
	cout << "\nYour total games won: " << playerTotalWins << endl;
	cout << "Computer's total games won: " << computerTotalWins << endl;
}

//Main function for the actual game
void playGame()
{	
	//int roundsPlayed = 0;
	int roundsToWin = 3;
	int playerRoundWins = 0;
	int computerRoundWins = 0;

	char playerChoice = NULL;
	char computerChoice = NULL;
	char playAgain = NULL;

	string playerInput = "";

	do
	{
		//Reset all counters at beginning of new set
		playerRoundWins = 0;
		computerRoundWins = 0;

		//While neither player has the required number of wins...
		while (playerRoundWins < roundsToWin && computerRoundWins < roundsToWin)
		{
			//Ask user for their move
			cout << "Enter your move: ";			
			cin >> playerInput;

			playerChoice = toupper(playerInput[0]);	//Retrieve first character of User's input

			//Check for invalid input
			while (playerChoice != 'R' && playerChoice != 'P' && playerChoice != 'S')
			{
				cout << "Invalid move. Please enter a valid move (R/P/S): ";
				cin >> playerInput;

				playerChoice = toupper(playerInput[0]);	//Retrieve first character of User's input
			}

			//Display player's chosen move
			if (playerChoice == 'R')
				cout << "\nYou played Rock\n";

			else if (playerChoice == 'P')
				cout << "\nYou played Paper\n";

			else if (playerChoice == 'S')
				cout << "\nYou played Scissors\n";

			computerChoice = computerMove();	//Generate the computer's move

			//Display computer's move
			if (computerChoice == 'R')
				cout << "Computer played Rock\n\n";

			else if (computerChoice == 'P')
				cout << "Computer played Paper\n\n";

			else if (computerChoice == 'S')
				cout << "Computer played Scissors\n\n";

			//Determine winner of current round
			if (playerChoice == computerChoice)
				cout << "It's a tie!\n\n";

			else if (playerChoice == 'R' && computerChoice == 'S')
			{
				cout << "Rock beats Scissors. You win!\n\n";
				playerRoundWins++;
				playerTotalWins++;
			}

			else if (playerChoice == 'R' && computerChoice == 'P')
			{
				cout << "Paper beats Rock. You lose.\n\n";
				computerRoundWins++;
				computerTotalWins++;
			}

			else if (playerChoice == 'P' && computerChoice == 'S')
			{
				cout << "Scissors beat Paper. You lose.\n\n";
				computerRoundWins++;
				computerTotalWins++;				
			}

			else if (playerChoice == 'P' && computerChoice == 'R')
			{
				cout << "Paper beats Rock. You win!\n\n";
				playerRoundWins++;
				playerTotalWins++;
			}

			else if (playerChoice == 'S' && computerChoice == 'R')
			{
				cout << "Rock beats Scissors. You lose.\n\n";
				computerRoundWins++;
				computerTotalWins++;
			}

			else if (playerChoice == 'S' && computerChoice == 'P')
			{
				cout << "Scissors beat Paper. You win!\n\n";
				playerRoundWins++;
				playerTotalWins++;				
			}

			//Display current round scores
			displayRoundStats(playerRoundWins, computerRoundWins);

			cout << "-----------------------------------------------" << endl;
		}

		//If computer won more rounds than player...
		if (playerRoundWins < computerRoundWins)		
			cout << "Better luck next time :(" << endl << endl;

		//If player won more rounds than computer...
		else if (playerRoundWins > computerRoundWins)
			cout << "\nYOU WON!!! :D" << endl << endl;
		
		//Ask user to play another round
		cout << "\nWould you like to play again? (y/n): ";
		cin >> playAgain;
	}

	while (playAgain == 'y' || playAgain == 'Y');
}

int main()
{
	srand((unsigned int)time(NULL));

	//Display game introduction
	cout << "Welcome to Rock, Paper Scissors!\n\n";
	cout << "R = Rock    P = Paper    S = Scissors\n\n";

	playGame();		//Begin playing the game
	displayFinalStats();	//Display final game stats	

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu