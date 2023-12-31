#include <cs50.h>
#include <stdio.h>


bool validity();
int find_length();
bool checksum();
void print_brand();

int main(void)
{
    long long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n <= 0);

    if (validity(n))
    {
        print_brand(n);
    }
    else
    {
        printf("INVALID\n");
    }
}





bool validity(long long number)
{
    int len = find_length(number);

    return (len == 13 || len == 15 || len == 16) && checksum(number, len);
}



int find_length(long long n)
{

    int len = 0;
    while (n != 0)
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
        }

        else
        {
            number /= 10;
            digit_2 = digit * 2;
            if (digit_2 > 9)
            {
                num1 = digit_2 / 10;
                num2 = digit_2 % 10;
                digit = num1 + num2;
                sum_odd += digit;
            }
            else
            {
                sum_odd += digit_2;
            }
        }

        i++;
    }
    return ((sum_odd + sum_even) % 10 == 0);
}


void print_brand(long long number)
{
    if (find_length(number) == 15)
    {
        int i = 0;
        while (i < 13)
        {
            number /= 10;
            i++;
        }
        if (number == 34 || number == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (find_length(number) == 13)
    {
        printf("VISA\n");
    }
    else if (find_length(number) == 16)
    {
        int i = 0;
        int j = 0;
        while (i < 14)
        {
            number /= 10;
            i++;
        }
        if (number >= 40 && number <= 49)
        {
            printf("VISA\n");
        }
        else if (number >= 51 && number <= 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}