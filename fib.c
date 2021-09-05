#include <stdio.h>

int fibonacci(int n) {

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);

}

void test_fibonacci() {
    printf("The 6th Fibonnaci number is: %d\n", fibonacci(6));
    printf("The 42nd Fibonnaci number is: %d\n", fibonacci(42));
    printf("The first 10 Fibonacci numbers are:\n");
    for (int f = 0; f < 10; f++) {
        printf("  %d", fibonacci(f));
    }
    printf("\n");
}