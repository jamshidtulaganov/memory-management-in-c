#include <stdio.h>
#include <stdlib.h>

// Function to convert an integer (byte) to its 8-bit binary string
void byte_to_binary(int byte, char *binary_str)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        // Use right shift and bitwise AND to check the value of each bit
        binary_str[i] = ((byte >> (7 - i)) & 1) ? '1' : '0';
    }
    binary_str[8] = '\0'; // Null-terminate the string
}

void readFileAsBinary(const char *filename)
{
    FILE *file_ptr;
    int byte;
    int offset = 0;

    // 1. Open the file in read-binary mode ("rb")
    // This is crucial, even for text files, to get the raw byte data.
    file_ptr = fopen(filename, "rb");

    if (file_ptr == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("--- Binary Data of %s ---\n", filename);
    printf("Offset   | HEX | BINARY (8-bit) | ASCII\n");
    printf("---------|-----|----------------|--------\n");

    // 2. Read byte by byte until EOF
    while ((byte = fgetc(file_ptr)) != EOF)
    {
        char binary_representation[9];

        // Convert the current byte to its binary string
        byte_to_binary(byte, binary_representation);

        // 3. Print the formatted output
        printf("%08X | ", offset);                    // Offset (Memory Address)
        printf("%02X  | ", byte);                     // Hex code
        printf("%s       | ", binary_representation); // Binary code

        // Print the character: use '.' for non-printable characters
        if (byte >= 32 && byte <= 126)
        {
            printf("%c\n", (char)byte);
        }
        else
        {
            printf(".\n");
        }

        offset++;
    }

    printf("----------------------------------------\n");

    // 4. Close the file
    fclose(file_ptr);
}

int main()
{
    // Replace "your_text_file.txt" with the name of your file
    readFileAsBinary("./data-16.txt");
    return 0;
}