#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char sub(char c, string key);

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
        if (isalpha(key[i]) == 0)
        {
            // printf("%c\n", key[i]);
            printf("Key must contain 26 charcters\n");
            return 1;
        }
    }

    // printf("%s\n", key);

    // take in the plaintext
    string plaintext = get_string("plaintext: ");

    // start the substitution
    string ciphertext;
    int text_length = strlen(plaintext);

    for (int i = 0; i < text_length; i++)
    {
        if isalpha(plaintext[i])
        {
            plaintext[i] = sub(plaintext[i]);
        }
    }

    printf("ciphertext: s%", plaintext);
}

char sub(char c, string key)
{
    // unify key to uppercase
    string key_length = strlen(key);
    for (int i = 0; i < key_length; i++)
    {
        if 
    }
}