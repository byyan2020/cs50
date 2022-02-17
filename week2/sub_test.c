#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string key = get_string("input: ");
    // unify key to uppercase
    int key_length = strlen(key);
    for (int i = 0; i < key_length; i++)
    {
        if islower(key[i])
        {
            key[i] = toupper[i];
        }
    }

    printf("%s", key);
}