#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float amount = get_float("Dollar amount: ");
    float change;
    change = amount * 100;

    int quarters = (amount * 4);
    int dimes = (amount * 10);
    int nickels = (amount * 20);
    int pennies = round(amount * 100);

    printf("quarters: %i\n", quarters);
    printf("Dimes: %i\n", dimes);
    printf("Nickels: %i\n", nickels);
    printf("Pennies: %i\n", pennies);
}
