// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26;

// Hash table
node *table[N];

// Hash table size
unsigned int size_dic = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash word to ontain a hash value
    unsigned int index = hash(word);
    // access linked list at that index in the hash table
    node *cursor = table[index];
    // traverse linked list, looking for the word(strcasecmp)
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int index = (toupper(word[0]) - 'A') + (toupper(word[0]) - 'A');
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // read dictionary, if fail, return false
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char *word = NULL;
    // read strings from file
    while (fscanf(file, "%s", word) != EOF)
    {
        // create a new node
        // malloc memory, check if return null, if null, return false
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        // copy word into node using strcopy
        strcpy(n->word, word);
        // hash word
        unsigned int index = hash(word);
        // insert node into hash table
        n->next = table[index];
        table[index] = n;
        // increase size of the dictionary
        size_dic++;
    }

    // close file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
        return size_dic;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
