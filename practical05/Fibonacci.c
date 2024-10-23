#include <stdio.h>

// Function to calculate the Fibonacci series
void fibonacci(int n, int *a, int *b) {
    int temp;
    for (int i = 2; i <= n; i++) {
        temp = *a + *b;
        *a = *b;
        *b = temp;
        printf("%d ", *b);
    }
}

int main() {
    int n;
    
    printf("Enter the number of length for the Fibonacci series: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("The value of n should be >1 .\n");
        return 1;
    }

    // First two Fibonacci numbers
    int a = 0, b = 1;

    // Print the first two numbers
    if (n == 1) {
        printf("Fibonacci series: %d\n", a);
    } else if (n >= 2) {
        printf("Fibonacci series: %d %d ", a, b);
        fibonacci(n, &a, &b);
        printf("\n");
    }

    return 0;
}

