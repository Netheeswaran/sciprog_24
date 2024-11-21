#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square.h"

int getlines(char filename[MAX_FILE_NAME]);

int main() {
    // Define file 
    FILE *f;
    char filename[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", filename);

    // get size of the magic square 
    // (the first line of the file contains n)
    int n = 0;

    // Open the file
    f = fopen(filename, "r");
    if (f == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the size of the matrix 
    if (fscanf(f, "%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid matrix size.\n");
        fclose(f);
        return EXIT_FAILURE;
    }

    printf("Matrix size: %d\n", n);

    // storing the magic square as an array of pointers
    int **matrix = (int **)malloc(n * sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(f);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            // clear already allocated rows
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            fclose(f);
            return EXIT_FAILURE;
        }
    }

    // Input integer data into matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(f, "%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Invalid matrix data in file.\n");
                
                for (int k = 0; k < n; k++) {
                    free(matrix[k]);
                }
                free(matrix);
                fclose(f);
                return EXIT_FAILURE;
            }
        }
    }

    // Close the file after reading
    fclose(f);

    // Print the matrix 
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Check if matrix is a magic square
    if (isMagicSquare(matrix, n)) {
        printf("The matrix is a magic square.\n");
    } else {
        printf("The matrix is not a magic square.\n");
    }

    // Free each row separately
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}


int getlines(char filename[MAX_FILE_NAME]) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    int ch_read;
    int count = 0;

    while ((ch_read = fgetc(fp)) != EOF) {
        if (ch_read == '\n') {
            count++;
        }
    }

    printf("No. lines: %d\n", count);
    fclose(fp);
    return count;
}

