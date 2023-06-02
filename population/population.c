#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int n;
    int x;
    int i = 0;

    do
    {
        n = get_int("Start Size: ");
    }
    while (n < 9);

    do
    {
        x = get_int("End Size: ");
    }
    while (x < n);

    while (n < x)
    {
        n = n + (n / 3) - (n / 4);
        i++;
    }
    printf("Years: %i\n", i);


}
