#include <stdio.h>
#include <math.h>

#define MAX_ITER 1000  // Maximum number of iterations
#define N 181  // Number of samples for x in [-0.9, 0.9]

// Function declarations
double arctanh1(double x, double delta);
double arctanh2(double x);
double difference[N] ;


// Function to calculate atanh(x) using the Maclaurin series
double arctanh1(double x, double delta) {
    double term = x;  // First term in the series
    double sum = term;  // Initialize sum with the first term
    int n = 1;

    while (fabs(term) > delta && n < MAX_ITER) {
        term = pow(x, 2*n + 1) / (2*n + 1);  // Calculate the next term
        sum += term;
        n++;
    }
    
    return sum;
}

// Function to calculate atanh(x) using natural logarithms
double arctanh2(double x) {
    return 0.5 * (log(1 + x) - log(1 - x));
}

int main() {
    double x, delta;
    double x_values[N];       // Array to store x values
    double maclaurin_results[N];  // Array to store Maclaurin results
    double log_results[N]; 
    double difference[N];
    // Array to store logarithm results
    // Get user input
    printf("Enter a value for x (|x| < 1): ");
    scanf("%lf", &x);
    
    if (fabs(x) >= 1.0) {
        printf("Error: |x| must be less than 1.\n");
        return 1;
    }

    printf("Enter the precision delta: ");
    scanf("%lf", &delta);

    // Calculate atanh(x) using the Maclaurin series
    double result1 = arctanh1(x, delta);
    printf("atanh(%f) using Maclaurin series: %lf\n", x, result1);

    // Calculate atanh(x) using natural logarithms
    double result2 = arctanh2(x);
    printf("atanh(%f) using natural logarithms: %lf\n", x, result2);
    

    // Array with values from -0.9 to 0.9 with step 0.01
    for (int i = 0; i < N; i++) {
        x_values[i] = -0.9 + i * 0.01;
    }

    // Calculate atanh(x) using both methods
    for (int i = 0; i < N; i++) {
        maclaurin_results[i] = arctanh1(x_values[i], delta);
        log_results[i] = arctanh2(x_values[i]);
    }

    // Print comparison of both methods
    printf("x\t\tMaclaurin\tLogarithm\tDifference\n");
    for (int i = 0; i < N; i++) {
        difference[i] = maclaurin_results[i], log_results[i];
        printf("%lf\t%lf\t%lf\t%.10lf\n", x_values[i], maclaurin_results[i], log_results[i],difference[i]);
    }
    return 0;

}








