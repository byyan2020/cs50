#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    if (FILE *file = fopen(argv[1], "r") == NULL)
    {
        printf("image cannot be oppened for reading");
        return 1;
    }

    BYTE *buffer = malloc(sizeof(BYTE) * 512);
    int counter = 0;

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE);
    {
        // if start of new jpeg
        if (isJpeg)
        {
            // if first jpeg
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", 2);
                FILE *img = fopen(filename, "w");
            }

        }

    // if is jpeg
        // open a new JPEG file

    // write 512 byte
    fwrite(buffer, 1, BLOCK_SIZE, img);
    }





}

bool isJpeg(BYTE buffer[])
{
    if (buffer[0] == 0xff & buffer[1] == 0xd8 & buffer[2] == 0xff & (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    return false;
}