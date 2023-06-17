#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    uint8_t header[BLOCK_SIZE];
    int counter = 0;

    while (fread(header, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if ()
        counter++;
    }
printf("%i\n",counter);
}