#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validity();
void encrypt();

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        int length = strlen(key);

        if (validity(key, length) == 0)
        {
            string plain_text = get_string("plaintext:  ");
            encrypt(plain_text, key);
        }
    }

    else
    {
        printf("Usage: ./substitution key\n");
    }
}



void encrypt(string text, string key)
{
    int i;
    char k;
    int text_length = strlen(text);
    printf("ciphertext: ");
    for (i = 0; i < text_length; i++)
    {
        int j = text[i];
        if (isupper(j))
        {
            j -= 65;
            k = toupper(key[j]);
        }

        else if (islower(j))
        {
            j -= 97;
            k = tolower(key[j]);
        }

        else
        {
            k = text[i];
        }
        printf("%c", k);
    }
    printf("\n");
}









int validity(string key, int length)
{
    int j = 0;
    int n = 0;
    for (int i = 0; i < length; i++)
    {
        if ((key[i] >= 65 && key[i] <= 90) || (key[i] >= 97 && key[i] <= 122))
        {
            j++;
        }

        for (int k = 0; k < length; k++)
        {
            if (key[i] == key[k])
            {
                n++;
            }
        }

    }

    if (length == 26 && j == length && n == length)
    {
        return 0;
    }

    else
    {
        printf("Key Error\n");
        return 1;
    }

}