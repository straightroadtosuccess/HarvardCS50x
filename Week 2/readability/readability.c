#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int amountLetters = count_letters(text);
    int amountWords = count_words(text);
    int amountSentences = count_sentences(text);

    // initialize variables for the index and divide into letters and sentences
    float L = (float) amountLetters / (float) amountWords * 100;
    float S = (float) amountSentences / (float) amountWords * 100;

    // Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // print the result of the information gathered
    printf("Number of letters %d\n", amountLetters);
    printf("Number of words %d\n", amountWords);
    printf("Number of sentences %d\n", amountSentences);
    printf("\n");

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

int count_letters(string text)
{
    // Return the number of letters in text
    int amountLetters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            amountLetters++;
        }
    }
    return amountLetters;
}

int count_words(string text)
{
    // Return the number of words in text, count the last word no space after
    int amountWords = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            amountWords++;
        }
    }
    return amountWords;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    int amountSentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            amountSentences++;
        }
    }
    return amountSentences;
}
