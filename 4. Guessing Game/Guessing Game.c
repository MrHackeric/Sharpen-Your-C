#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the random number generator and generate a random number between 1 and 100
int generateRandomNumber() {
    srand(time(0)); // Seed the random number generator with the current time
    return (rand() % 100) + 1; // Generate a random number between 1 and 100
}

int main() {
    int randomNumber = generateRandomNumber();
    int guess;
    int attempts = 0;

    printf("Welcome to the Guessing Game!\n");
    printf("I have selected a number between 1 and 100. Can you guess it?\n");

    // Game loop
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        }
    }

    return 0;
}

/*
Explanation of the Code:

1. **generateRandomNumber Function:
Seeds the random number generator using the current time (`srand(time(0))`).
Generates a random number between 1 and 100 using `rand() % 100 + 1`.

2. Main Function:
Calls `generateRandomNumber` to get the target number.
Initializes `guess` and `attempts` variables.
Welcomes the user and explains the game.

3. Enters a game loop where the user is prompted to enter a guess:
Increments the `attempts` counter.
Provides feedback if the guess is too low or too high.
Exits the loop if the guess is correct, congratulating the user and displaying the number of attempts.
*/
