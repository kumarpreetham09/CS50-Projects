#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n;
    do{
    n = get_int("Number: ");
    }
    while (n <= 0);
}

void checksum(int number)
{
    while (number > 0) {
        int digit = number % 10;
        printf("%i\n", digit);
    }
}
