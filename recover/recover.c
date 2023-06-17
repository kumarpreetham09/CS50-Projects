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

    typedef uint8_t BYTE;
    uint8_t buffer[BLOCK_SIZE];
    int counter = 0;

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0) )
        {
            counter++;
            sprintf(file, "%03i.jpg", counter);
            FILE *img = fopen(filename. "w")
            fwrite(buffer, BYTE, BLOCK_SIZE, file);
        }

    }
printf("%i\n",counter);
}