#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover.c IMAGE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

}