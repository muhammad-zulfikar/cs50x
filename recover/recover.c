#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Check for correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open the forensic image file
    FILE *forensic_image = fopen(argv[1], "r");
    if (forensic_image == NULL)
    {
        printf("Could not open forensic image.\n");
        return 1;
    }

    // Create a buffer to store a block of data
    uint8_t buffer[512];

    // Counter to keep track of the number of JPEG files found
    int jpeg_count = 0;

    // Output file pointer for writing JPEG files
    FILE *output_file = NULL;

    // Loop through the forensic image file
    while (fread(buffer, sizeof(uint8_t), 512, forensic_image) == 512)
    {
        // Check for the JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous JPEG file, if any
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            // Create a new JPEG file
            char filename[8]; // 8 characters: 3 for digits, 4 for ".jpg", 1 for null terminator
            sprintf(filename, "%03i.jpg", jpeg_count);
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                fclose(forensic_image);
                fprintf(stderr, "Could not create JPEG file.\n");
                return 2;
            }

            // Increment JPEG file counter
            jpeg_count++;
        }

        // Write data to JPEG file, if found
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, output_file);
        }
    }

    // Close files
    fclose(forensic_image);
    if (output_file != NULL)
    {
        fclose(output_file);
    }

    return 0;
}
