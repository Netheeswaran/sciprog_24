#include <stdio.h>
#include <math.h>

int main(void){
    float a = 0;
    float b = (3.1428 / 3.0);
    double sum1 = 0.0;
    int N = 12;
    double d;
    d = (b-a)/ (N-1);
    sum1 += tan(a);
    sum1 += tan(b);
    for(int i=1; i<N-1; i++){
        double xi = a + i * d;
        sum1 = sum1 + 2*tan(xi);
    }
    double result = sum1 * (d/2);
    double res = log(2.0);
    double diff = result - res;
    printf("Result of integral function is %lf\n ", result);
    printf("Result of log(2) is : %lf\n", res);
    printf("Difference in both results : %lf\n", diff);
    return 0;
}
