#include <stdio.h>

// Function to calculate the score of a word
int calculateScore(char *word, int *indexToScore) {
    int score = 0;

    while (*word != '\0') {
        char currentChar = *word;

        // Manually convert lowercase to uppercase
        if (currentChar >= 'a' && currentChar <= 'z') {
            currentChar = currentChar - 'a' + 'A';
        }

        // Assuming 'A' has ASCII value 65
        // Subtracting 65 gives the index of the letter in the score array
        int index = currentChar - 'A';

        // Checking if the character is a valid uppercase letter
        if (index >= 0 && index < 26) {
            // Adding the corresponding score to the total
            score += (indexToScore[index]);
        }

        word++;
    }

    return score;
}

int main() {
    // Score array for each letter
    int indexToScore[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Input words for Player 1 and Player 2
    char word1[100], word2[100];

    // Prompting for Player 1's word
    printf("Player 1, enter your word: ");
    scanf("%s", word1);

    // Prompting for Player 2's word
    printf("Player 2, enter your word: ");
    scanf("%s", word2);

    // Calculating scores for both players
    int score1 = calculateScore(word1, indexToScore);
    int score2 = calculateScore(word2, indexToScore);

    // Determining the winner or if it's a tie
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}
