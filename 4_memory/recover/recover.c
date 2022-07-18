#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int BLOCK_SIZE = 512;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open memory card
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    FILE *img = NULL;
    int count = 0;
    char filename[8];

    // Repeat until end of card:
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", count);
            if (count == 0)
            {
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                count++;
            }
            else
            {
                // Close the file and open a new one
                fclose(img);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                count++;
            }
        }
        else
        {
            // If already found JPEG
            if (count != 0)
            {
                // Keep writing JPEG
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
            }
        }
    }
    // Close any remaining files
    fclose(file);
    fclose(img);
}