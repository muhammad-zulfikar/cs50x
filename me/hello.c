#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int name = get_int("What's your name? ");

    printf("Hello," "%i/s", name);
}
