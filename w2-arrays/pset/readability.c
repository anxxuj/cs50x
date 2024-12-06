#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt user for some text
    string text = get_string("Text: ");

    // Count number of letters, words, and sentences in the text
    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (
            text[i] == '.' ||
            text[i] == '?' ||
            text[i] == '!'
        )
        {
            sentences++;
        }
    }

    // Compute Coleman-Liau index
    double L = ((double) letters / (double) (words + 1)) * 100.0;
    double S = ((double) sentences / (double) (words + 1)) * 100.0;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
