#include <cs50.h>
#include <stdio.h>

bool checksum();
void print_brand();
bool validity();
int find_length();

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
}

bool validity(long long number)
{
    int len = find_length(number);

    return (len == 13 || len == 15 || len == 16) && checksum(number);
}

int find_length(long long n)
{
    int len;
    for (len = 0; n>0; n /= 10 && len++);
    return len;
}


bool checksum(long long number)
{
    long long numb = number;
    long long sum_even = 0;
    long long sum_odd = 0;
    int i;
    long long digit;
    int num1;
    int num2=0;
    long long total;

    for (i = 0; numb > 0; i++ && (numb /= 10))
    {
        if ( i % 2 == 0)
        {
            digit = numb % 10;
            long long digit_2 = digit * 2;
            if (digit_2 > 9){

                num1 = digit_2 % 10;
                num2 /= digit_2;
            }
            sum_even += num1 + num2;

        }

        else
        {
            sum_odd += digit;
        }

        total = sum_even + sum_odd;
    }

    if (total % 10 == 0){
        return true;
    }

    else {
        return false;
    }

}

void print_brand(n)
{
    if (n > 0){
        printf("Hello");
    }
    else {
        printf("Bye");
    }
}
