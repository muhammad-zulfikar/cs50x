#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if !only_digits(argv[1])
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

    int key = atoi(argv[1]);

    printf("plaintext: ");
    string plaintext = get_string();

    printf("ciphertext: ");

    for (i = 0, n < strlen(plaintext), i++)
