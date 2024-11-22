// File: main.c
// Author: JBA
// Date: November 21, 2024

#include <stdio.h>  // Standard Input/Output library for reading and writing files
#include <stdlib.h> // Standard library for system-level functions like error handling

int main() {
    // Declare pointer for files (used to open, read, and write files)
    FILE *input_file, *outputFile;

    // Debug: Print message before attempting to open input.txt
    printf("Attempting to open input.txt...\n");

    // Open the input file in "read" mode
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) { // Check if the file was successfully opened
        perror("Error opening input file"); // Print error if file not found
        return EXIT_FAILURE;  //Exit the program with a failure code
    } else {
        // Debug: Print success message
        printf("Successfully opened input.txt\n");
    }

    // Open the output file in "write" mode
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) { // Check if the file was successfully opened
        perror("Error opening output file"); // Print error if file cannot be created
        fclose(input_file); // Close the input file before exiting
        return EXIT_FAILURE; // Exit the program with a failure code
    }

    // Declare a buffer (temporary storage) to hold each line of text
    char buffer[256]; // Can hold up to 255 characters plus a null terminator

    printf("Reading from input.txt and writing to output.txt\n");

    // Read the input file by line
    while (fgets(buffer, sizeof(buffer), input_file) != NULL) {
        // Process each line: Convert all lowercase letters to uppercase
        for (int i = 0; buffer[i] != '\0'; i++) { // Loop through each character in the line
            if (buffer[i] >= 'a' && buffer[i] <= 'z') { // Check if character is lowercase
                buffer[i] -= 32; // Convert to uppercase by subtracting ASCII value
            }
        }

        // Write the processed line to the output file
        fprintf(outputFile, "%s", buffer);
    }

    // Close the files to release resources
    fclose(input_file);
    fclose(outputFile);

    printf("Processing complete. Check output.txt for results.\n");

    return EXIT_SUCCESS; // Return 0 to indicate the program ran successfully
}
