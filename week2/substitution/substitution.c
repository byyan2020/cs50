#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // hold the command-line argument as the key
    string key = argv[1];

    // test if the key is valid
    int count = 0;
    int str_length = strlen(key);

    if (str_length != 26)
    {
        printf("Key must contain 26 charcters\n");
        return 1;
    }

    for (int i = 0; i < str_length; i++)
    {
        if (isalpha(key[i]) != 1)
        {
            printf("Key must contain 26 charcters\n");
            return 1;
        }
    }

    printf("%s", key);
}