#include <cs50.h>
#include <math.h>
#include <stdio.h>

// ask user input for change amount

// subtract coins down to 0

// number of correct coins need to program output

int main(void)
{
    float amount, change;
    int quarters, dimes, nickels, pennies;
    amount = get_float("Change amount: ");
    amount = change;
    {
        quarters = (25);
        dimes = (10);
        nickels = (5);
        pennies = (1);
        int coins = 0;
        while (change >= 25)
        {
            change - 25;
            coins++;
        }
        while (change >= 10)
        {
            change - 10;
            coins++;
        }
        while (change >= 5)
        {
            change - 5;
            coins++;
        }
        while (change >= 1)
        {
            change - 1;
            coins++;
        }
        printf("Amount of coins%i ", coins);
    }
}

