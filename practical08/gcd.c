#include <stdio.h>

// Iterative GCD function
int gcd_iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Recursive GCD function
int gcd_recursive(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd_recursive(b, a % b);
}

int main() {
    int a, b;

    // Get input from the user
    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);

    // Calculate GCD using both methods
    printf("GCD of %d and %d (iterative) is: %d\n", a, b, gcd_iterative(a, b));
    printf("GCD of %d and %d (recursive) is: %d\n", a, b, gcd_recursive(a, b));

    return 0;
}

