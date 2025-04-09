#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("Input:  ");
    printf("Output: ");
    // printf("%s\n", s);

    // int length = strlen(s);
    // for (int i = 0; i < strlen(s); i++)
    // for (int i = 0; i < length; i++)
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
