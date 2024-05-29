#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters(string text);
int words(string text);
int sentences(string text);

int main(void)
{
    string text = get_string("write your text here: ");

    int letter_count = letters(text);
    int word_count = words(text);
    int sentence_count = sentences(text);

    float L = ((float) letter_count / (float) word_count) * 100;
    float S = ((float) sentence_count / (float) word_count) * 100;

    float decimal_grade = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(decimal_grade);

    if (decimal_grade < 1)
    {
        printf("\nBefore Grade 1\n");
    }
    else if (decimal_grade > 16)
    {
        printf("\nGrade 16+\n");
    }
    else
        printf("\nGrade %i\n", grade);
}

int letters(string text)
{
    int len = strlen(text);
    int letters = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}
int words(string text)
{
    int len = strlen(text);
    int words = 1;
    for (int i = 0; i < len; i++)
    {
        if (isblank(text[i]))
        {
            words += 1;
        }
    }
    return words;
}
int sentences(string text)
{
    int len = strlen(text);
    int sentences = 0;
    for (int i = 0; i < len; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences += 1;
        }
    }
    return sentences;
}
