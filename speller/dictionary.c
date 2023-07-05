// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    for (int i = 0; i<index; i++)
    {

    }


    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    size();
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    char c;
    node *temp = NULL;
    char n[LENGTH + 1];
    do
    {
        node *str = malloc(sizeof(node));

        if (str == NULL)
        {
            printf("Could not allocate memory for each word");
            return false;
        }
        fscanf(file, "%s", n);
        printf("%s\n",n);
        strcpy(str->word, n);
        str->next = NULL;
        int index = hash(str->word);
        temp->next = str->word;
        str->next = table[index]->next;
        table[index]->next = str->word;
        temp->next = NULL;
        printf("%i", index);

    }
    while (fscanf(file, "%s", n) != EOF);

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
    return false;
}
