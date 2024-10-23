#include <stdio.h>
#include <math.h>  // For tan and M_PI

// Global array to store tan(x) values
double tan_values[20];  

// Degrees to Radians
double to_radians(double degrees) {
    return degrees * (M_PI / 180.0);  // PI radians = 180 degrees
}

// Area under the curve using the Trapezoidal Rule
double trapezoidal_rule(double values[], int n, double h) {
    double area = 0.0;
    for (int i = 1; i < n; i++) {
        area += (values[i - 1] + values[i]) * h / 2.0;  
    }
    return area;
}

int main() {
    int i;
    double degrees, radians;

    // tan(x) for angles 0 to 60 degrees
    for (i = 0; i <= 12; i++) {
        degrees = i * 5;  
        radians = to_radians(degrees);  // Convert to radians
        tan_values[i] = tan(radians);  // Compute tan(x) and store in array
        printf("tan(%.0f degrees) = %f\n", degrees, tan_values[i]);
    }

    // Calculate the area under the curve using the Trapezoidal Rule
    double h = to_radians(5);  
    double area = trapezoidal_rule(tan_values, 13, h);  // 13 values in the array
    printf("Area under the curve of tan(x) : %f\n", area);

    return 0;
}

