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
