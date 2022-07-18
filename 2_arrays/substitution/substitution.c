#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check whether key contains 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // Check whether key only contains alphabetic characters
            if (isalpha(argv[1][i]))
            {
                // Check whether key does not contain repeated characters
                int repeat = 0;
                for (int m = 0; m < n; m++)
                {
                    if (argv[1][i] == argv [1][m])
                    {
                        repeat++;
                    }
                }
                if (repeat != 1)
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
            else
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
        }

        // Prompt user for plaintext
        string text = get_string("plaintext: ");

        // Print ciphertext
        printf("ciphertext: ");
        for (int j = 0, len = strlen(text); j < len; j++)
        {
            if (isalpha(text[j]))
            {
                // Convert ASCII to alphabetical index
                int index;
                if (isupper(text[j]))
                {
                    index = text[j] - 'A';
                }
                else
                {
                    index = text[j] - 'a';
                }

                // Convert index to key letter
                char letter = argv[1][index];

                // Convert ciphertext to upper or lower case
                char cipher;
                if ((isupper(text[j]) && isupper(letter)) || (islower(text[j]) && islower(letter)))
                {
                    cipher = letter;
                }
                if (isupper(text[j]) && islower(letter))
                {
                    cipher = toupper(letter);
                }
                if (islower(text[j]) && isupper(letter))
                {
                    cipher = tolower(letter);
                }
                printf("%c", cipher);
            }
            else
            {
                printf("%c", text[j]);
            }
        }
        printf("\n");
        return 0;
    }
}