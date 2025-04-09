#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // string names[7];
    // names[0] = Bill;
    // names[1] = Charlie;
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};

    for (int i = 0; i < 7; i++)
    {
        // if (names[i] == "Ron")
        if (strcmp(names[i], "Ron") == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
