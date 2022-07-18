#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get user imput
    string text = get_string("Text: ");

    // Count the number of letters
    int letter = count_letters(text);

    // Count the number of words
    int word = count_words(text);

    // Count the number of sentences
    int sentence = count_sentences(text);

    // Compute Coleman-Liau index
    float l = (letter * 100.0) / word;
    float s = (sentence * 100.0) / word;
    int index = round(0.0588 * l - 0.296 * s - 15.8);

    // Print Coleman-Liau index
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    // Keep track of the number of letters
    int letter = 0;

    // Count the number of letters
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            letter++;
        }
    }
    return letter;
}

int count_words(string text)
{
    // Keep track of the number of words
    int word = 0;

    // Count the number of words
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            word++;
        }
    }
    word++;
    return word;
}

int count_sentences(string text)
{
    // Keep track of the number of sentences
    int sentence = 0;

    // Count the number of sentences
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }
    return sentence;
}