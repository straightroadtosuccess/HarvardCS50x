#include <cs50.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // If input isn't correct amount of args
    if (argc != 2)
    {
        // Error message and exit
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open the file
    FILE * infile = fopen(argv[1], "r")

    // Unable to open
    if (infile == NULL)
    {
        printf("File not found\n")
        return 1;
    }

    // Buffer
    BYTE buffer[BLOCK_SIZE];

    bool have_found_first_jpg = false;
    while (fread(buffer, BLOCK_SIZE, 1, infile))
    {
        if (is_start_new_jpeg_buffer)
        if (!have_found_first_jpg)
    }
}
bool is_start_new_jpeg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}
