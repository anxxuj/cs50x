#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string enciper(string plaintext, string key);

int main(int argc, string argv[])
{
    // Validate key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int key_length = strlen(key);

    if (key_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    for (int i = 0; i < key_length; i++)
    {
        char c = tolower(key[i]);
        for (int j = 0; j < key_length; j++)
        {
            if (tolower(key[j]) == c && i != j)
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // Enciper plaintext
    string ciphertext = enciper(plaintext, key);

    // Display ciphertext
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

string enciper(string plaintext, string key)
{
    string ciphertext = plaintext;
    for (int i = 0, n = strlen(ciphertext); i < n; i++)
    {
        char c = ciphertext[i];
        if (isalpha(c))
        {
            if (islower(c))
            {
                ciphertext[i] = tolower(key[c - 'a']);
            }
            else
            {
                ciphertext[i] = toupper(key[c - 'A']);
            }
        }
    }
    return ciphertext;
}
