#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float change = get_float("Change amount: ");

    for (change > 25 | change == 25;);
    {
        int quarters = (change * 4);
    }
    while (change < 0);
    {
        for (change > 10 | change == 10;);
        {
            int dimes = (change * 10);
        }
    }
    while (change < 0);
    {
        for (change > 5 | change == 5;);
        {
            int nickels = (change * 20);
        }
    }
    while (change < 0);
    {
        for (change > 4 | change == 4;);
        {
            int pennies = round(change * 100);
        }
    }
    printf("The change will be:\n");
    printf("Quarters: %i\n", quarters);
    printf("Dimes: %i\n", dimes);
    printf("Nickels: %i\n", nickels);
    printf("Pennies: %i\n", pennies);
}
