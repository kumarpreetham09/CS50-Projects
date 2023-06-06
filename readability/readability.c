#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    float index;
    float L = 0;
    float S = 0;
    int i;
    int sentences = 0;
    float words = 1.0;
    int letters = 0;
    string text = get_string("Text: ");
    int length = strlen(text);

    for (i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }

        else if (text[i] == ' ')
        {
            words++;
        }

        else if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
    }

    L = (letters / words) * 100;
    S = (sentences / words) * 100;

    index = 0.0588 * L - 0.296 * S - 15.8;
    int j = round(index);
    if (j < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (j > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", j);
    }


}