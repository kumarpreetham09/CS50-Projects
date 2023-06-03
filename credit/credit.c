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

bool checksum(long number, int len)
{
    long sum_even = 0;
    long sum_odd = 0;
    int num1 = 0;
    int num2 = 0;
    int i = 0;
    int digit_2;
    while (i < len)
    {
        int digit = number % 10;
        if (i % 2 == 0)
        {
            number /= 10;
            sum_even += digit;
            printf("even %i %ld\n",digit,number);
        }

        else
        {
            number /= 10;
            sum_odd += digit;
            digit_2 = digit *2;
            if(digit_2>9)
            {
                num1 = digit_2 / 10;
                num2 = digit_2 % 10;
            }
            printf("odd  %i %ld %i %i\n",digit, number, num1, num2);
        }

        i++;
    }
    return true;
}