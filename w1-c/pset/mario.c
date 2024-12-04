#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for valid height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // For each row
    for (int i = 0; i < height; i++)
    {
        // Print left spaces
        for (int j = height - 1; j > i; j--)
        {
            printf(" ");
        }

        // Print left hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Print gap
        printf("  ");

        // Print right hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Print newline
        printf("\n");
    }
}
