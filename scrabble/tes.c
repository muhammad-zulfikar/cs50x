#include <stdio.h>

// Function prototypes
int getPoints(char word[]);
void promptForWord(char player[], char word[]);
void printWinnerOrTie(int score1, int score2);
void printPlayerScore(char player[], int* score);

// Global array for letter scores
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main() {
    char word1[20], word2[20];

    // Prompt for Player 1's word
    promptForWord("Player 1", word1);
    int score1 = getPoints(word1);

    // Prompt for Player 2's word
    promptForWord("Player 2", word2);
    int score2 = getPoints(word2);

    // Print each player's score
    printPlayerScore("Player 1", &score1);
    printPlayerScore("Player 2", &score2);

    // Print the winner or tie
    printWinnerOrTie(score1, score2);

    return 0;
}

// Function to calculate the score of a word
int getPoints(char word[]) {
    int score = 0;
    int i = 0;

    while (word[i] != '\0') {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            score += points[word[i] - 'A'];
        }

        i++;
    }

    return score;
}

// Function to prompt the user for a word
void promptForWord(char player[], char word[]) {
    printf("%s, enter your word: ", player);
    scanf("%s", word);
}

// Function to print each player's score
void printPlayerScore(char player[], int* score) {
    printf("%s's score: %d\n", player, *score);
}

// Function to print the winner or tie
void printWinnerOrTie(int score1, int score2) {
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
}
