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
    FILE *file = fopen(argv[1], "r");

}