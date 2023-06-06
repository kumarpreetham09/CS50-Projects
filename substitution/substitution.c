#include <cs50.h>
#include <stdio.h>
#include <string.h>

int validity();
void encrypt();

int main(int argc, string argv[])
{
    string key = argv[1];
    int length = strlen(key);

    if (validity(key, length) == 0)
    {
        string plain_text = get_string("plaintext: ");
        encrypt(plain_text, key, length);
    }



}



void encrypt(string text, string key, int length)
{
    int i;
    char k;
    for (i = 0; i < length; i++)
    {
        int j = text[i];
        if (j >= 65 && j <= 90)
        {
            j -= 65;
            k = key[j];
        }

        else if (j >= 97 && j <= 122)
        {
            j -= 97;
            k = key[j];
        }
        printf("%c", k);
    }
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