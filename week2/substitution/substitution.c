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
    int str_length = strlen(key);

    // test if the key length is 26
    if (str_length != 26)
    {
        printf("Key must contain 26 charcters\n");
        return 1;
    }

    // test if there are char not alpha
    for (int i = 0; i < str_length; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            // printf("%c\n", key[i]);
            printf("Key must contain 26 charcters\n");
            return 1;
        }

        // unify key to uppercase
        if islower(key[i])
        {
            key[i] = toupper(key[i]);
        }
    }
    printf("%s\n", key);

    // test if there are duplicate alpha
    /*
    dic = [0,0...0]
    for key[i] from 0 to 25
        dic[key[i]-65]++;
        if dic[key[i]-65] >1;
            wrong
     */


    // take in the plaintext
    string plaintext = get_string("plaintext: ");

    // start the substitution
    int text_length = strlen(plaintext);

    for (int i = 0; i < text_length; i++)
    {
        char current_char = plaintext[i];
        if isalpha(current_char)
        {
            if islower(current_char)
            {
                current_char = toupper(current_char);
                plaintext[i] = sub(current_char, key);
                plaintext[i] = tolower(plaintext[i]);
            }
            else
            {
                plaintext[i] = sub(current_char, key);
            }
        }
    }

    printf("ciphertext: %s\n", plaintext);
}

char sub(char c, string key)
{
    // char: uppercase char
    // string: uppercase string
    int index = c - 'A';
    char sub_c = key[index];
    return sub_c;
}