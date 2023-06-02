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

    if (validity(n))
    {
        print_brand(n);
    }
    else
    (
        printf("INVALID\n")
    )

bool validity(long number)
{
    int len = find_length(number)

    return (len == 13 || len == 15 || len == 16) && checksum(number);
}

int find_length(long n)
{
    int len;
    for (len = 0; n>0; n /= 10; len++);
    return len;
}


bool checksum(long number)
{
    int sum;
    int i;
    for (i = 0; number > 0; i++ & number /= 10)
    {
        if ( i % 2 == 0)
        {
            sum += number
        }
    }
}