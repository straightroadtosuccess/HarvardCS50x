// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header_buffer[HEADER_SIZE];

    // Read header data from file
    fread(header_buffer, sizeof(uint8_t), HEADER_SIZE, input);

    // Write header data to a file
    fwrite(header_buffer, sizeof(uint8_t), HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    // Declare variable and initialize
    int16_t buffer;

    // Read audio data from file
    while (fread(&buffer, sizeof(int16_t), 1, input) == 1)
    {
        buffer *= factor;
        // Write new audio data to file
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
