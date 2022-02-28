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

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE);
    // look for beginning of a JPEG
        if (isJpeg)
        {
            
        }
    // open a new JPEG file

    // write 512 byte until a new JPEG is found



}

bool isJpeg(512 bytes)
{

}