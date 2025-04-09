#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    // Prompt the user for the pyramid's height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    // accept only numbers 1 through 8
    while (n <= 0 || n >= 9);

    // Print a pyramid of this height
    for (int i = 0; i < n; i++)
    {
        // Print row of bricks in the correct amounts compared to eachother
        print_row(n - i - 1, i + 1);
    }
}

void print_row(int spaces, int bricks)
{
    // Print some spaces
    for (int i = 0; i < spaces; i++)
        printf(" ");
    {
        for (int i = 0; i < bricks; i++)
            // Print some bricks
            printf("#");
    }
    // print next line
    printf("\n");
}
