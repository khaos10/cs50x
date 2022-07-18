#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for pyramid's height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    // Determine the number of lines
    int i;
    for (i = 0; i < height; i++)
    {
        // Print spaces
        int space;
        for (space = 0; space < (height - i - 1); space++)
        {
            printf(" ");
        }
        
        // Print left hashes
        int hashl;
        for (hashl = 0; hashl <= i; hashl++)
        {
            printf("#");
        }
        
        // Print gap
        printf("  ");
        
        // Print right hashes
        int hashr;
        for (hashr = 0; hashr <= i; hashr++)
        {
            printf("#");
        }
        printf("\n");
    }
}