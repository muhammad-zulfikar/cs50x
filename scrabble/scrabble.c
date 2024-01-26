#include <stdio.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int getPoints(char word[]);

int main() {

  char word1[20], word2[20];

  printf("Player 1, enter your word: ");
  scanf("%s", word1);

  printf("Player 2, enter your word: ");
  scanf("%s", word2);

  int score1 = getPoints(word1);
  int score2 = getPoints(word2);

  if (score1 > score2) {
      printf("Player 1 wins!\n");
  } else if (score2 > score1) {
      printf("Player 2 wins!\n");
  } else {
      printf("Tie!\n");
  }

  return 0;
}


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
