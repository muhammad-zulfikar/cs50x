#include <stdio.h>

int getPoints(char word[]);
void promptForWord(char player[], char word[]);
void printWinnerOrTie(int score1, int score2);
void printPlayerScore(char player[], int score);

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main() {
    char word1[20], word2[20];

    promptForWord("Player 1", word1);
    int score1 = getPoints(word1);
    promptForWord("Player 2", word2);
    int score2 = getPoints(word2);

    printPlayerScore("Player 1", score1);
    printPlayerScore("Player 2", score2);

    printWinnerOrTie(score1, score2);

    return 0;
}


int getPoints(char word[]) {
    int score = 0;
    int i = 0;

    while (word[i] != '\0') {
        char currentChar = word[i];

        if (currentChar >= 'A' && currentChar <= 'Z') {
            currentChar = currentChar - 'A' + 'a';
        }

        if (currentChar >= 'a' && currentChar <= 'z') {
            score += points[currentChar - 'a'];
        }

        i++;
    }
}

void promptForWord(char player[], char word[]) {
    printf("%s, enter your word: ", player);
    scanf("%s", word);
}

void printPlayerScore(char player[], int score) {
    printf("%s's score: %d\n", player, score);
}

void printWinnerOrTie(int score1, int score2) {
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
}
