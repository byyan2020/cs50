#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <getopt.h>


typedef uint8_t  BYTE;
bool isJpeg(BYTE *buffer);

int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // check for one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    // check for if the forensic image can be open for reading
    FILE *file = fopen(argv[1], "r");
    if (file  == NULL)
    {
        printf("image cannot be oppened for reading");
        return 1;
    }

    BYTE *buffer = malloc(sizeof(BYTE) * 512);
    int counter = 0;
    FILE *img = NULL;
    char filename[8];

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // if start of new jpeg
        if (isJpeg(buffer))
        {
            // if first jpeg
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, img);
                counter++;
            }
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, img);
                counter++;
            }
        }
        else
        {
            if (counter != 0)
            {
                fwrite(buffer, 1, BLOCK_SIZE, img);
            }
        }
    }
    free(buffer);
}

bool isJpeg(BYTE *buffer)
{
    if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
    {
        return true;
    }
    return false;
}