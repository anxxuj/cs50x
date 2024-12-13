#include <stdio.h>
#include <stdlib.h>

const int BLOCK_SIZE = 512;
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int jpeg_found = 0;
    FILE *img = NULL;

    uint8_t buffer[BLOCK_SIZE];
    while (fread(buffer, sizeof(uint8_t), BLOCK_SIZE, card) != 0)
    {
        if (
            buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0
        )
        {
            char name[8];
            sprintf(name, "%03i.jpg", jpeg_found++);
            
            if (img != NULL)
            {
                fclose(img);
            }
            
            img = fopen(name, "w");
            if (img == NULL)
            {
                printf("Could not create a new jpeg file.\n");
                return 1;
            }
        }

        if (img != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), BLOCK_SIZE, img);
        }
    }

    fclose(card);
    fclose(img);

    return 0;
}
