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

    return (len == 13 || len == 15 || len == 16) && checksum(number);
}



int find_length(long long n)
{
    int len = 0;
    while(n != 0){
        n /= 10;
        len++;
    }
    return len;
}

bool checksum(number)
{

}