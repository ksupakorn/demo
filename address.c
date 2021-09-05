#include <stdio.h>

int test_address() {
    int answer = 42;
    double pi = 3.1415926;
    printf("answer's value: %d\n", answer);
    printf("answer's address: %p\n", &answer);
    printf("pi's value: %0.4f\n", pi);
    printf("pi's address: %p\n", &pi);
}

double messyAreaCalculator(double radius, double* pi_ptr) {
    if (pi_ptr == NULL) {
        printf("Could not calculate area with a reference to pi!\n");
        return 0.0;
    }
    return radius * radius * (*pi_ptr);
}

void nullValue() {

    double pi = 0.0;
    double* pi_ptr = NULL;

    pi = 3.14156;
    pi_ptr = &pi;


}