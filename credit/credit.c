#include <cs50.h>
#include <stdio.h>

void checksum();
void print_brand();
bool validity();

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
    );

validity(long number)
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
    long numb = number;
    long sum_even;
    long sum_odd;
    int i;
    long digit;
    int num1;
    int num2;
    long total;

    for (i = 0; numb > 0; i++ && numb /= 10)
    {
        if ( i % 2 == 0)
        {
            numb % 10 = digit;
            long digit_2 = digit * 2;
            if (digit_2 > 9){

                digit_2 % 10 = num1
                digit_2 /=  num2
            }
            sum_even += num1 + num2;

        }

        else
        {
            sum_odd += digit
        }

        total = sum_even + sum_odd
    }

    if (total % 10 == 0){
        return true
    }

    else {
        return false
    }

}

print_brand(n)
{
    if (n > 0){
        printf("Hello")
    }
    else {
        print("Bye")
    }
}