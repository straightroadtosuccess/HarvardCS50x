// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int countWord = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashNum = hash(word);
    // Create cursor variable
    node *cursor = table[hashNum];
    // Loop until the end of the linked list
    while(cursor != NULL){
    // Check if the words are the same
    if(strcasecmp(cursor->word, word) == 0)
    {
        return true;
    }
    // Otherwise, move cursor to the next node
    cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE * DictFile = fopen(dictionary, "r");

    // Check if return value is NULL
    if(DictFile == NULL)
    {
        return false;
    }

    // Read strings from file on at a time
    // fscanf(file, '%s', word)
    char str[LENGTH + 1];
    while(fscanf(DictFile, "%s", str) != EOF)
    {
        // Creare a new node for each word
        // Use malloc
        node *temp = malloc(sizeof(node));
        // Check if return value is NULL
        if(temp == NULL)
        {
            return false;
        }
        // Copy word into node using strcpy
        strcpy(temp->word, str);

        // Use the hash function
        int hashNum = hash(str);

        // Check if the head is pointing to NULL
        if(table[hashNum] == NULL)
        {
            // Point temp to NULL
            temp->next = NULL;
        }
        else
        {
            // Otherwise, point temp to the first node of the linked list
            temp->next = table[hashNum];
        }
        // Point the header to temp
        table[hashNum] = temp;

        countWord += 1;
    }
    // Close the file
    fclose(DictFile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return countWord;
}

void freenode(node *n)
{
    if(n->next != NULL)
    {
        freenode(n->next);
    }
    free(n);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        if(table[i] != NULL)
        {
            freenode(table[i]);
        }
    }
    return true;
}
