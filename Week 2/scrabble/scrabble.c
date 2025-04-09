#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// score assigned to each letter of the alphabet
int score[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_value(string word);

int main(void)
{
    // Prompt the user for two words
    string w1 = get_string("Player 1: ");
    string w2 = get_string("Player 2: ");

    // Compute the value of each word
    int s1 = compute_value(w1);
    int s2 = compute_value(w2);

    // Print the winner
    if (s1 > s2)
    {
        // print player 1 wins
        printf("\nPlayer 1 wins! 🎉🎉🎉\n");
        printf("\n😲 Player 1 scored: %i\n", s1);
        printf("😲 Player 2 scored: %i\n\n", s2);
    }
    else if (s1 < s2)
    {
        // print player 2 wins
        printf("\nPlayer 2 wins! 🎉🎉🎉\n");
        printf("\n😲 Player 1 scored: %i\n", s1);
        printf("😲 Player 2 scored: %i\n\n", s2);
    }
    else
    {
        // print a tie between both players
        printf("\nTie! 😆\n");
        printf("\n😲 Player 1 scored: %i\n", s1);
        printf("😲 Player 2 scored: %i\n\n", s2);
    }
}

int compute_value(string word)
{
    // Keep track of the value
    int value = 0;

    // Compute the values for each of the characters in the word
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // ascii between 65 and 90 uppercase letters, exclude punctuation, make them equivalent
        if (isupper(word[i]))
        {
            value = value + score[word[i] - 65];
        }
        // ascii between 97 and 122 lowercase letters, exclude punctuation, make them equivalent
        if (islower(word[i]))
        {
            value = value + score[word[i] - 97];
        }
    }
    return value;
}
