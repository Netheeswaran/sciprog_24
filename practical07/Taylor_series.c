#include <stdio.h>
#include <stdlib.h>

// Function to compute factorial
double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to estimate e using a Taylor series up to a specified order
double e_estimate(int order) {
    double sum = 0.0;
    for (int i = 0; i <= order; i++) {
        sum += 1.0 / factorial(i);
    }
    return sum;
}

// Function to allocate an integer array of given size
int* allocatearray(int size) {
    return malloc(size * sizeof(int));
}

// Function to fill an array with ones
void fill_ones(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 1;
    }
}

// Function to print an array
void printarray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to free allocated memory
void freearray(int* array) {
    free(array);
}

int main() {
    // Part 1: Estimate the value of e
    int order;
    printf("Enter the order for e estimation: ");
    scanf("%d", &order);
    
    double estimated_e = e_estimate(order);
    printf("Estimated value of e using a %d-order polynomial: %.5f\n", order, estimated_e);

    // Part 2: Dynamic memory allocation functions
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* array = allocatearray(size);
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    fill_ones(array, size);
    printf("Array filled with ones:\n");
    printarray(array, size);
    
    freearray(array);
    return 0;
}

