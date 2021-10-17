#include <stdio.h>

int factorial(int n) {
    // negative value dosen't have factorial
    if (n < 0) return 0;
    // factorial of zero is one
    if (n == 0) return 1;

    return n * factorial(n - 1);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int ret = factorial(n);
    printf("factorial of %d is %d", n, ret);
    return 0;
}
