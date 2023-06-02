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
    for(int i = 1; i%2==0; i++ ) {

    }
    while (number > 0) {
        int digit = number % 10;
        printf("%i\n", digit);
        number /= 10;
    }
}
