#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calculate_score(string word);

int main(void)
{
    // Prompt the user for two words
    string w1 = get_string("Player 1: ");
    string w2 = get_string("Player 2: ");

    // Compute the score of each word
    int w1_score = calculate_score(w1);
    int w2_score = calculate_score(w2);

    // Print the winner
    if (w1_score > w2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (w2_score > w1_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int calculate_score(string word)
{
    int scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // If letter is not alphabet
        if (!isalpha(word[i])) continue;

        char c = toupper(word[i]);
        int score_index = c - 'A';
        score += scores[score_index];
    }

    return score;
}
