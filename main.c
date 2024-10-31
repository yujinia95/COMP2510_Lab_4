/**
 * Author: Yujin Jeong
 * Date: 26th Sep 2024
 * Purpose: Creating a simple number guessing game (Using Array and pointers for better understanding)
 */

#include <stdio.h>
// Provides functions for performing operations like memory allocation.
#include <stdlib.h>
// Provides functions for manipulating and retrieving time-related data.
#include <time.h>

#define MAX_ATTEMPTS 10

// Function call
int playGame();

// Function call
void displayGuesses(int *guesses, int attempts);

// main
int main() {
    // Seeding the random number generator with the current time. Ensuring that each execution of the program generates
    // a unique sequence of random numbers.
    // *Seeding = the process of initializing a random number generator with a specific starting value to determine the
    // sequence of random numbers its produces.
    srand(time(0));

    char playAgain;

    int win = 0;
    int loss = 0;
    int gameResult;

    do {
        gameResult = playGame();

        if(gameResult == 0) {           // If return is 0(Loss)
            loss++;                     // Increment loss
        } else if(gameResult == 1) {    //If return is 1(Win)
            win++;                      // Increment win
        }

        printf("\nYou have won: %d, lost: %d\n",win, loss);     // Printing number of win and loss
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

int playGame() {
    int number = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    int guessArr[MAX_ATTEMPTS];     // Declare an array to store guesses. Setting the array size as 10.

    int *p = guessArr;       // Declare a pointer to manipulate guesses. Setting a pointer for array.

    printf("Guess the number between 1 and 100:\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d: ", attempts + 1);
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Please enter a number between 1 and 100. \n");
            continue;
        }

        *(p + attempts) = guess;         // Store the guess at the current attempt index in the array using pointer.

        attempts++;

        if (guess < number) {
            printf("Too low!\n");
        } else if (guess > number) {
            printf("Too high!\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            printf("=====All your guesses=====\n");
            displayGuesses(p, attempts);
            return 1;   // Indicating win
        }

    }

    printf("Sorry, you've used all %d attempts. The number was %d.\n", MAX_ATTEMPTS, number);
    return 0;    // Indicating loss

}

// Function to display all guesses, go through the array from index 0 to number of attempts.
void displayGuesses(int *guesses, int attempts) {
    for (int i = 0; i < attempts; i++) {
        printf("%d ", *(guesses + i)); // Display the guess stored at the ith index of the array using pointer.
    }
}




