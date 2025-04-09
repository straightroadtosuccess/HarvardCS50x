#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Cents Owed: ");
    }
        while (cents < 0);
        return cents;
    {
        int quarters = 0;
        while (cents >= 25)
    {
        cents = cents -25;
        quarters++;
    }
        return quarters;
    }
    {
        int dimes = 0;
        while (cents >= 10)
    {
        cents = cents -10;
        dimes++;
    }
        return dimes;
    }
    int nickels = 0;
        while (cents >= 5)
    {
        cents = cents -5;
        nickels++;
    }
        return nickels;
    }
    int pennies = 0;
        while (cents >= 25)
    {
        cents = cents -25;
        pennies++;
    }
        return pennies;
    {
        int coins = quarters + dimes + nickels + pennies;
        printf("%i\n", coins)
}
