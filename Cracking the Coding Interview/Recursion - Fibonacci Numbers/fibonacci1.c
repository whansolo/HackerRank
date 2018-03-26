#include <stdio.h>

/*
 *  consider the fibonacci sequence:
    fibonacci(0) = 0
    fibonacci(1) = 1
    fibonacci(2) = (0 + 1) = 1
    fibonacci(3) = (1 + 1) = 2
    fibonacci(4) = (1 + 2) = 3
    fibonacci(5) = (2 + 3) = 5
    fibonacci(5) = (3 + 5) = 8
    ...
 */

int fibonacci(int n) {
    return (n > 2) ? fibonacci(n - 1) + fibonacci(n - 2) : 1;
};

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", fibonacci(n));
    return 0;
}
