#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check to see if there is only one command line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar  key\n");
        return 1;
    }

    // Check if the argument contains only digits
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar  key\n");
            return 1;
        }
    }

    // Convert the key to an integer
    int key = atoi(argv[1]);

    // Get the plaintext from user input
    string plaintext = get_string("Plaintext: ");

    // Print the cyphertext
    printf("Ciphertext: ");

    // Get the ciphertext by converting the plaintext with the key
    for (int t = 0; t < strlen(plaintext); t++)
    {
        // Convert uppercase letters using key to caesar encryption
        if (isupper(plaintext[t]))
        {
            printf("%c", (plaintext[t] - 65 + key) % 26 + 65);
        }
        // Convert lowercase letters using key to caesar encryption
        else if (islower(plaintext[t]))
        {
            printf("%c", (plaintext[t] - 97 + key) % 26 + 97);
        }
        // Don't convert other characters like punctuation
        else
        {
            printf("%c", plaintext[t]);
        }
    }
    printf("\n");
    return 0;
}
