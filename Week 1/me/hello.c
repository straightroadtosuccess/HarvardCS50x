#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask for the name of user
    string name = get_string("What's your name? ");
    // print the response with name included
    printf("hello, %s\n", name);
}
