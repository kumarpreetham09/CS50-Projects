#include <cs50.h>
#include <stdio.h>

void checksum();
int main(void)
{
    long n;
    do{
    n = get_long("Number: ");
    }
    while (n <= 0);

    checksum(n);
}

void checksum(int number)
{
    while (number > 0) {
        int digit = number % 10;
        printf("%i\n", digit);
        
    }
}
