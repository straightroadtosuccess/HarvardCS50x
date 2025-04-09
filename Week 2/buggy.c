#include <cs50.h>
#include <stdio.h>

int get_negative_int(void);

int main(void)
{
    // for (int i = 0; i <= 3; i++)
    int i = get_negative_int();
    printf("%i\n", i);
}

int get_negative_int(void)
{
    int n;
    do
    {
        n = get_int("Negative Integer: ");
        printf("n is %i\n", n);
    }
    while (n < 0);
    return n;
}
