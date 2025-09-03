#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define STRING_LENGTH 50

int main(int argc, char **argv) {
    int i, N;
    char datafile[STRING_LENGTH];
    FILE *fp;
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        fprintf(stdout, "How to use this program:\n");
        fprintf(stdout, "%s N filename\n\n", argv[0]);
        fprintf(stdout, "N = integer, how many minutes the file has to run\n");
        fprintf(stdout, "filename = name of the file on which the result is written\n");
        fprintf(stdout, "Output: A count of minutes passing.\n");
        return EXIT_FAILURE; // Changed to EXIT_FAILURE for incorrect usage
    } else {
        // Read input values
        N = atoi(argv[1]); // Use atoi to convert to integer

        // Check if N is a positive integer
        if (N <= 0) {
            fprintf(stderr, "N must be a positive integer.\n");
            return EXIT_FAILURE;
        }

        // Check the length of the filename
        if (strlen(argv[2]) >= STRING_LENGTH) {
            fprintf(stderr, "File name too long. Increase STRING_LENGTH or shorten the name (%s, %d)\n", __FILE__, __LINE__);
            return EXIT_FAILURE;
        } else {
            strcpy(datafile, argv[2]);
        }
    }

    // Open data file for writing
    fp = fopen(datafile, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error in opening the file %s (%s, %d)\n", datafile, __FILE__, __LINE__);
        return EXIT_FAILURE;
    }
    fprintf(fp, "Inizio del conteggio\n"); // Changed to write to file
    // Main loop to count and write the minutes
    for (i = 0; i < N; i++) {
        fprintf(fp, "minute #%d\n", i + 1); // Fixed formatting to show correct minute number
        sleep(60); // Sleep for 1 second
    }

    // Close the file
    fclose(fp);
    return EXIT_SUCCESS; // Use EXIT_SUCCESS to indicate successful completion
}
