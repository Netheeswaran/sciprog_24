#include <stdio.h>

#define N 5  
#define P 3  
#define Q 4  

int main() {
    double A[N][P], B[P][Q], C[N][Q];

    // Initialize matrix A with A[i][j] = i + j
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            A[i][j] = i + j;
        }
    }

    // Initialize matrix B with B[i][j] = i - j
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < Q; j++) {
            B[i][j] = i - j;
        }
    }

    // Initialize matrix C to zero
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            C[i][j] = 0.0;
        }
    }

    // Perform matrix multiplication C = A * B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            for (int k = 0; k < P; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print matrix A
    printf("Matrix A (%d x %d):\n", N, P);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            printf("%6.2f ", A[i][j]);
        }
        printf("\n");
    }

    // Print matrix B
    printf("\nMatrix B (%d x %d):\n", P, Q);
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < Q; j++) {
            printf("%6.2f ", B[i][j]);
        }
        printf("\n");
    }

    // Print matrix C
    printf("\nMatrix C (%d x %d):\n", N, Q);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            printf("%6.2f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

