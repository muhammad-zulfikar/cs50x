#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
void enter(void);

int main(void)
{
    int cents;
    do
    {
        enter();
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int quarters = calculate_quarters(cents);

    cents -= (quarters * 25);

    int dimes = calculate_dimes(cents);

    cents -= (dimes * 10);

    int nickels = calculate_nickels(cents);

    cents -= (nickels * 5);

    int pennies = calculate_pennies(cents);

    enter();
    printf("Quarters: %i\n", quarters);
    printf("Dimes: %i\n", dimes);
    printf("Nickels: %i\n", nickels);
    printf("Pennies: %i\n", pennies);
    enter();

    printf("Total coins: %i\n", quarters + dimes + nickels + pennies);
    enter();
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents -= 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents -= 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents -= 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    return cents;
}

void enter(void)
{
    printf("\n");
}
