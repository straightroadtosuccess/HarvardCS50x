#include <cs50.h>
#include <stdio.h>
#include <string.h>

// int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    // int length = string_length(name);
    int length = strlen(name);
    printf("%i\n", length);
}

// int string_length(string s)
//     {

//     int i = 0;
//     // while (name[length] != '\0')
//     while (s[i] != '\0')
//     {
//         i++;
//     }
//     return i;
// }
