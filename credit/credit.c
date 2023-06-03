#include <cs50.h>
#include <stdio.h>


bool validity();
int find_length();
bool checksum();

int main(void)
{
    long long n;
    do{
    n = get_long("Number: ");
    }
    while (n <= 0);

    if (validity(n))
    {
        printf("Brand\n");
    }
    else
    (
        printf("INVALID\n")
    );
}

bool validity(long long number)
{
    int len = find_length(number);

    return (len == 13 || len == 15 || len == 16) && checksum(number, len);
}



int find_length(long long n)
{
    int len = 0;
    while(n != 0)
    {
        n /= 10;
        len++;
    }
    return len;
}

bool checksum(number, len)
{
    int sum_even = 0;
    int sum_odd = 0;
    int num1;
    int i = 0;
    while (i < len)
    {
        int digit = number % 10;

        if (i % 2 == 0)
        {
            sum_even += digit;
        }

        else
        {
            num1 = (digit * 2) % 10;
            int num2 = (digit * 2) / 10;
            sum_odd += num1 + num2;
        }
        i++;
    }
    printf("%i",num1);
    return true;
}