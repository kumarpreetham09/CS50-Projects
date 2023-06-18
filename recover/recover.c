#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

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

    typedef uint8_t BYTE;
    size_t bytes_read;
    uint8_t buffer[BLOCK_SIZE];
    int counter = 0;
    bool first_img = false;
    FILE *img;
    char output[10];

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0) )
        {
            if (counter == 0)
            {
                first_img = true;
                sprintf(output, "%03i.jpg", counter);
                img = fopen(output, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                counter++;
            }

            else
            {
                fclose(img);
            }
            
            sprintf(output, "%03i.jpg", counter);
            img = fopen(output, "w");
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
            counter++;
        }
    }

printf("%i\n",counter);
fclose(file);
fclose(img);
}