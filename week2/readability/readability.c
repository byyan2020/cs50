#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // getting user input
    string text = get_string("Text:");

    // count letters
    int letters = count_letters(text);
    // printf("%i letters\n", letters);

    // count words
    int words = count_words(text);
    // printf("%i words\n", words);

    // count sentences
    int sentences = count_sentences(text);
    // printf("%i sentences\n", sentences);

    // caculate Coleman-Liau index
    float l = ((float)letters / words) * 100.00;
    // printf("l is %f\n", l);
    float s = ((float)sentences / words) * 100.00;
    // printf("s is %f\n", s);
    int index = round(0.0588 * l - 0.296 * s - 15.8);

    // print grade result
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }

}

int count_letters(string text)
{
    int text_length = strlen(text);
    int letters = 0;

    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    int text_length = strlen(text);
    int words = 1;

    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return words;

}

int count_sentences(string text)
{
    int text_length = strlen(text);
    int sentences = 0;

    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}