#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    while (true)
    {
        n = get_int("Height: ");
        if (n > 0)
        {
            break;
        }
    }

    // For each row
    //for (int i = 0; i < 8; i++)
    // for (int j = 0; j < i; j++)
    for (int i = 0; i < 8; i++)
    {
        // For each column
        for (int j = 0; j < i; j++)
        // for (int i = 0; i < 8; i++)
        {
            // Print a brick
            printf("#");
        }
        printf("\n");
    }
}
