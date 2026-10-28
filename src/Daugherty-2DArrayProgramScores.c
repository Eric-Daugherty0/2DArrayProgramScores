/*
Name: Eric Daugherty
Date: 9/19/2026
Purpose: This is a program that will allow the user to enter game scores,
display the current record, display all games won, and display
all game results ordered.
*/

#include <stdio.h>
#include "Daugherty-2DArrayProgramScores.h"

// Main function to execute the program
int main(void)
{
    // Declares a 2D array to hold the scores and a variable to track the number of games
    int scores[50][2];
    int games = 0;
    char choice;

    // Main loop to display the menu and process user input
    do
    {
        // Displays the main menu
        scoresMenu();

        // Gets the users menu choice
        scanf(" %c", &choice);

        // If statements determine which function to call based on the users menu choice
        if (choice == 'A' || choice == 'a')
        {
            enterResults(scores, &games);
        }
        else if (choice == 'B' || choice == 'b')
        {
            currentRecord(scores, games);
        }
        else if (choice == 'C' || choice == 'c')
        {
            gameWins(scores, games);
        }
        else if (choice == 'D' || choice == 'd')
        {
            inOrderResults(scores, games);
        }
        else if (choice == 'E' || choice == 'e')
        {
            // Ends the program
        }
        else
        {
            printf("\nPlease enter A, B, C, D, or E.\n");
        }

    } while (choice != 'E' && choice != 'e');

    return 0;
}

// Function to display the main menu
void scoresMenu(void)
{
    printf("\n*****************************************\n");
    printf("*           Game Scores Menu            *\n");
    printf("*****************************************\n");
    printf("*****************************************\n");
    printf("* A) Enter game results                 *\n");
    printf("* B) Current Record                     *\n");
    printf("* C) Results from games won             *\n");
    printf("* D) The results from lowest to highest *\n");
    printf("* E) Quit                               *\n");
    printf("*****************************************\n");
    printf("Enter your choice: ");
}

// Function to enter a single game result
void enterResults(int scores[][2], int *games)
{
    int result;

    // Checks if the array is full
    if (*games >= 50)
    {
        printf("\nThe saved game results are full.\n");
        return;
    }

    // Gets the users score and checks for invalid input
    do
    {
        printf("\nEnter your scores: ");

        result = scanf("%d", &scores[*games][0]);

        if (result != 1)
        {
            printf("Please enter a whole number.\n");

            while (getchar() != '\n')
            {
                
            }
        }
        else if (scores[*games][0] < 0)
        {
            printf("Scores cannot be negative.\n");
        }

    } while (result != 1 || scores[*games][0] < 0);

    // Gets the opponents score and checks for invalid input
    do
    {
        printf("Enter the opponents score: ");

        result = scanf("%d", &scores[*games][1]);

        if (result != 1)
        {
            printf("Please enter a whole number.\n");

            while (getchar() != '\n')
            {
                // Clears invalid input
            }
        }
        else if (scores[*games][1] < 0)
        {
            printf("Scores cannot be negative.\n");
        }

    } while (result != 1 || scores[*games][1] < 0);

    // Increases the number of games after a valid result is entered
    (*games)++;

    printf("Game result saved.\n");
}

// Function to display the current record of wins losses and ties
void currentRecord(int scores[][2], int games)
{
    int wins = 0;
    int losses = 0;
    int ties = 0;
    int i;

    // Checks if any games have been entered
    if (games == 0)
    {
        printf("\nNo results have been entered yet.\n");
        return;
    }

    // Goes through every game and determines the result
    for (i = 0; i < games; i++)
    {
        if (scores[i][0] > scores[i][1])
        {
            wins++;
        }
        else if (scores[i][0] < scores[i][1])
        {
            losses++;
        }
        else
        {
            ties++;
        }
    }

    printf("\nCurrent Record\n");
    printf("Wins: %d\n", wins);
    printf("Losses: %d\n", losses);
    printf("Ties: %d\n", ties);
}

// Function to display all results from games that were won
void gameWins(int scores[][2], int games)
{
    int i;
    int foundWin = 0;

    // Checks if any games have been entered
    if (games == 0)
    {
        printf("\nNo results are saved. Please enter results first.\n");
        return;
    }

    printf("\nGames Won\n");

    // Goes through every game and displays only wins
    for (i = 0; i < games; i++)
    {
        if (scores[i][0] > scores[i][1])
        {
            printf("Your Score: %d | Opponent Score: %d\n",
                   scores[i][0], scores[i][1]);

            foundWin = 1;
        }
    }

    // Displays a message if there were no wins
    if (foundWin == 0)
    {
        printf("No games have been won.\n");
    }
}

// Function to display all results ordered by opponent score
void inOrderResults(int scores[][2], int games)
{
    int orderedScores[50][2];
    int i;
    int j;
    int temp;

    // Checks if any games have been entered
    if (games == 0)
    {
        printf("\nNo results are saved. Please enter results first.\n");
        return;
    }

    // Copies the game results into a separate array
    for (i = 0; i < games; i++)
    {
        orderedScores[i][0] = scores[i][0];
        orderedScores[i][1] = scores[i][1];
    }

    // Sorts the copied array by opponent score using bubble sort
    for (i = 0; i < games - 1; i++)
    {
        for (j = 0; j < games - 1 - i; j++)
        {
            if (orderedScores[j][1] > orderedScores[j + 1][1])
            {
                temp = orderedScores[j][1];
                orderedScores[j][1] = orderedScores[j + 1][1];
                orderedScores[j + 1][1] = temp;

                temp = orderedScores[j][0];
                orderedScores[j][0] = orderedScores[j + 1][0];
                orderedScores[j + 1][0] = temp;
            }
        }
    }

    // Displays the sorted results
    printf("\nOpponents Scores (Low to High)\n");

    for (i = 0; i < games; i++)
    {
        printf("Your Score: %d | Opponent Score: %d\n",
               orderedScores[i][0], orderedScores[i][1]);
    }
}
