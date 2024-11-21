#include <stdio.h>
// Checks if a matrix is a magic square.
// A magic square is an n-sided matrix whose sum of values for each
// row, column, main and secondary diagonals equals to n(n^2 + 1)/2.
// The function takes as input a matrix 'square' and its side length 'n'
// and outputs 0 if 'n' is negative or 'square' is NOT a magic square;
// otherwise, outputs a non-zero value
//


int isMagicSquare(int **square, const int n) {

    // when 'n' is negative
    if (n < 0) {
        return 0;
    }

    int a = (n * (n * n + 1)) / 2;

    int i, j;

    // Check rows
    for (i = 0; i < n; i++) {
        int rowsum = 0;
        for (j = 0; j < n; j++) {
            rowsum += square[i][j];
        }
        if (rowsum != a) {
            return 0; 
        }
    }

    // Check columns
    for (j = 0; j < n; j++) {
        int colsum = 0;
        for (i = 0; i < n; i++) {
            colsum += square[i][j];
        }
        if (colsum != a) {
            return 0; 
        }
    }

    // Check main diagonal
    int mainDiagSum = 0;
    for (i = 0; i < n; i++) {
        mainDiagSum += square[i][i];
    }
    if (mainDiagSum != a) {
        return 0; 
    }

    // Check secondary diagonal
    int secondDiagSum = 0;
    for (i = 0; i < n; i++) {
        secondDiagSum += square[i][n - i - 1];
    }
    if (secondDiagSum != a) {
        return 0; 
    }

    return 1;
}

