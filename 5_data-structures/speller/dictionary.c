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
}
node;

// Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    unsigned int index = hash(word);

    // Access linked list at that index in the hash table
    node *cursor = NULL;
    cursor = table[index]->next;

    // Traverse linked list, looking for the word
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            // Move cursor to the next node
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
unsigned int count = 0;
bool load(const char *dictionary)
{
    // Initialize table
    for (int i = 0; i < N ; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        n->next = NULL;
        table[i] = n;
    }

    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    // Read strings from file one at a time
    char word[LENGTH + 1];
    unsigned int index = 0;
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word
        // Allocate memory for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        // Put data into the node
        strcpy(n->word, word);

        // Hash word to obtain a hash value
        index = hash(n->word);

        // Insert node into hash table at that location
        // Set next pointer of the node to be the first element in the linked list
        n->next = table[index]->next;
        // Reset the first element in the linked list to be the new node
        table[index]->next = n;
        count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *cursor = NULL;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
