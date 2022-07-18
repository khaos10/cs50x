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
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int i = 0, n = strlen(argv[1]);
        do
        {
            if (isdigit(argv[1][i]))
            {
                i++;
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        while (i < n);
        
        // Convert key to int
        int key = atoi(argv[1]);

        // Prompt user for plaintext
        string text = get_string("plaintext: ");

        // Print out ciphertext
        printf("ciphertext: ");
        for (int j = 0, len = strlen(text); j < len; j++)
        {
            if (isalpha(text[j]))
            {
                char index;
                // Convert ASCII to alphabetical index
                if (isupper(text[j]))
                {
                    index = text[j] - 'A';
                }
                else
                {
                    index = text[j] - 'a';
                }

                // Shift alphabetical index using formula
                char letter = (index + key) % 26;

                // Convert result back to ASCII
                char cipher;
                if (isupper(text[j]))
                {
                    cipher = letter + 'A';
                }
                else
                {
                    cipher = letter + 'a';
                }
                printf("%c", cipher);
            }
            else
            {
                printf("%c", text[j]);
            }
        }
        printf("\n");
    }
}