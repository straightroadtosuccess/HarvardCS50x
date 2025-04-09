#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    while (true)
    {
        h = get_int("Height: ");
        if (h > 0 && h < 9)
        {
            break;
        }
    }
    // For each row i is row
    for (int i = -1; i < h; i++)
    {
        // For each space s is space
        for (int s = 0; s < h - i - 1; s++)
        printf(" ");
        // For each column j is column
        for (int j = -1; j < i; j++)
        {
            // Print a brick
            printf("#");
        }
        // Move to next
        printf("\n");
    }
}
