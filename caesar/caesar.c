#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(char *s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    int n = strlen(plaintext);
    for (int i = 0; i < n; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

bool only_digits(char *s)
{
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
