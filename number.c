#include <stdio.h>


void print_average(float a, float b) {
    float average = (a + b) / 2;
    printf("The average of %.2f and %.2f is %.2f\n", a, b, average);
}



int test() {
    double ledger[100];
    printf("Size of a double: %li\n", sizeof(double));
    printf("Size of ledger: %li\n", sizeof ledger);
    printf("Calculated ledger capacity: %li\n", sizeof ledger / (sizeof(double)));


    float num1, num2;
    printf("Please enter two numbers separated by a space: ");
    scanf_s("%f %f", &num1, &num2);
    print_average(num1, num2);

}


