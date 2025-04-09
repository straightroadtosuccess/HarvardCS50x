#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float amount = get_float("Dollar amount: ");
    float change;
    change = amount * 100;
    int i;

    int quarters = (25);
    int dimes = (10);
    int nickels = (5);
    int pennies = (1);

    printf("Change returned: ");
    for (i = 0; i < 4; i++)
    {
        int num_coins
    }

    printf("quarters: %i\n", quarters);
    printf("Dimes: %i\n", dimes);
    printf("Nickels: %i\n", nickels);
    printf("Pennies: %i\n", pennies);
}
