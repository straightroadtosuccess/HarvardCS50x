#include <cs50.h>
#include <stdio.h>

void meow(int n);

// int main(void)
// {
//     int i = 1;
//     while (i <= 3)
//     {
//     printf("meow\n");
//     i++;
//     }
// }


int main(void)
{
    meow(3);
}

void meow(int n)
{
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n");
    }
}
