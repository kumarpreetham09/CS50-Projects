#include <stdio.h>

int main(void)
{
    int a = 28;
    int b = 50;
    int *c = &a;

    *c = 14;
    c = &b;
    *c = 25;

    printf("%p\n",&a);
    printf("%p\n",&b);
    printf("%p at %p\n",c, &c);
}