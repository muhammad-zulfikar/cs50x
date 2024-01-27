#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encrypt(char *plaintext, int key);

int main(int argc, char *argv[]) {
    // Check for the correct number of command-line arguments
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the key consists of only decimal digits
    for (int i = 0; i < strlen(argv[1]); i++) {
        if (!isdigit(argv[1][i])) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert the key to an integer
    int key = atoi(argv[1]);

    // Get plaintext from the user
    char plaintext[1000]; // Assuming the maximum input size is 1000 characters
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encrypt the plaintext using the Caesar cipher
    encrypt(plaintext, key);

    return 0;
}

void encrypt(char *plaintext, int key) {
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++) {
        char c = plaintext[i];

        // Check if the character is an uppercase letter
        if (isupper(c)) {
            printf("%c", 'A' + (c - 'A' + key) % 26);
        }
        // Check if the character is a lowercase letter
        else if (islower(c)) {
            printf("%c", 'a' + (c - 'a' + key) % 26);
        }
        // Non-alphabetical characters remain unchanged
        else {
            printf("%c", c);
        }
    }

    printf("\n");
}
