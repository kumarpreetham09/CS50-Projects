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
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }


    uint8_t buffer[BLOCK_SIZE];
    int counter = 0;

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0) )
        {
            uint8_t x='\0';
            char output[8];
            sprintf(output, "%03i.jpg", counter);
            FILE *img = fopen(output, "w");
            fwrite(buffer, x, BLOCK_SIZE, img);
            counter++;
        }

    }
    
printf("%i\n",counter);
fclose(file);
}