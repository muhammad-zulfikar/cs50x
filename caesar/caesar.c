#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool only_digits(char *s);
char rotate(char c, int n);

int main(int argc, char *argv[]) {
    // Make sure program was run with just one command-line argument
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    if (!only_digits(argv[1])) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a string to an int
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    printf("plaintext: ");
    string plaintext = get_string();  // Using get_string instead of GetString

    // Print ciphertext
    printf("ciphertext: ");

    // For each character in the plaintext:
    for (int i = 0, n = strlen(plaintext); i < n; i++) {
        // Rotate the character if it's a letter
        printf("%c", rotate(plaintext[i], key));
    }

    printf("\n");

    return 0;
}

// Function to check if a string consists of only digits
bool only_digits(char *s) {
    for (int i = 0, n = strlen(s); i < n; i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

// Function to rotate a character by a given number of positions
char rotate(char c, int n) {
    if (isupper(c)) {
        return (c - 'A' + n) % 26 + 'A';
    } else if (islower(c)) {
        return (c - 'a' + n) % 26 + 'a';
    } else {
        return c;
    }
}
