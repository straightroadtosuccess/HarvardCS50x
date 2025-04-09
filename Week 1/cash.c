#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // amount owed back
    float owed;
    // units of currecy
    int coins = 0;

    do
    {
        owed = get_float("Change owed: ");
    }
    while (owed < 0);

    // cents rounded to prevent math errors
    int cents = round(owed);

    // while loop for quarters, track number of coins
    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }
    // while loop for dimes, track number of coins
    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }
    // while loop for nickels, track number of coins
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }
    // while loop for pennies, track number of coins
    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }
    // print the total the amount of coins
    printf("%i\n", coins);
}
