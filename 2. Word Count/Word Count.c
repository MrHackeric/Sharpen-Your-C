#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to count words, lines, and characters in a file
void countWordsLinesChars(char *filename, int *word_count, int *line_count, int *char_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    char c;
    *word_count = 0;
    *line_count = 0;
    *char_count = 0;
    int in_word = 0; // Flag to track if we are inside a word

    while ((c = fgetc(file)) != EOF) {
        (*char_count)++;

        // Count lines
        if (c == '\n') {
            (*line_count)++;
        }

        // Count words
        if (isspace(c)) {
            in_word = 0;
        } else if (!in_word) {
            (*word_count)++;
            in_word = 1;
        }
    }

    // If the file doesn't end with a newline, count the last line
    if (*char_count > 0 && c != '\n') {
        (*line_count)++;
    }

    fclose(file);
}

int main() {
    char filename[100];
    int word_count, line_count, char_count;

    // Prompt the user for input file
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Count words, lines, and characters
    countWordsLinesChars(filename, &word_count, &line_count, &char_count);

    // Display the counts
    printf("\nFile Statistics:\n");
    printf("Words: %d\n", word_count);
    printf("Lines: %d\n", line_count);
    printf("Characters: %d\n", char_count);

    return 0;
}



/*
Explanation of the Code:

1. countWordsLinesChars Function:
Opens the specified file(e.g., WordCount.txt)and initializes counters for words, lines, and characters.
Iterates through each character in the file:
Counts characters and detects line breaks to count lines.
Counts sequences of characters separated by whitespace to count words.
Handles special cases such as files that do not end with a newline.

2. Main Function:
Prompts the user to enter the filename.
Calls `countWordsLinesChars` to compute the word, line, and character counts.
Prints the computed counts to the console.
*/
