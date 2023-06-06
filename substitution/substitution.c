#include <cs50.h>
#include <stdio.h>
#include <string.h>

int validity();

int main(int argc, string argv[])
{
    string key = argv[1];

    if (validity(key) == 0)
    {
        printf("Success\n");
    }


}


int validity(string key)
{
    int j = 0;
    int n = 0;
    int length = strlen(key);
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

    if (length == 26 && j == length == n)
    {
        return 0;
    }

    else
    {
        printf("%i",n);
        printf("Key Error\n");
        return 1;
    }

}