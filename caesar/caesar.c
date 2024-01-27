#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encrypt(char *plaintext, int key);

int main(int argc, char argv[]) {
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++) {
        if (!isdigit(argv[1][i])) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    char plaintext[1000];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    encrypt(plaintext, key);

    return 0;
}

void encrypt(char *plaintext, int key) {
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++) {
        char c = plaintext[i];

        if (isupper(c)) {
            printf("%c", 'A' + (c - 'A' + key) % 26);
        }
        else if (islower(c)) {
            printf("%c", 'a' + (c - 'a' + key) % 26);
        }
        else {
            printf("%c", c);
        }
    }

    printf("\n");
}
