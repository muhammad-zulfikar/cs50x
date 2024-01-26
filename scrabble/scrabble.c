#include <stdio.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

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

int main() {

  char word1[20], word2[20];

  

}
