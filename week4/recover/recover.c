#include <stdio.h>
#include <stdlib.h>

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

    
    // look for beginning of a JPEG

    // open a new JPEG file

    // write 512 byte until a new JPEG is found



}

bool isJpeg(512 bytes)
{

}