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

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
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
// Groups based on ASCII Values
    int value = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        value += tolower(word[i]);

    }
    return (value % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("Could not open %s\n", dictionary);
        return false;
    }
    char c;
    node *temp = NULL;
    char n[LENGTH + 1];

    while (fscanf(file, "%s", n) != EOF)
    {
        node *str = malloc(sizeof(node));

        if (str == NULL)
        {
            return false;
        }
        strcpy(str->word, n);
        str->next = NULL;
        int index = hash(str->word);
        if (table[index] == NULL)
        {
            table[index] = str;
        }
        else
        {
            str->next = table[index];
            table[index] = str;
        }
        size();

    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int i = 0;
    i++;
    return i;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;

    
        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
