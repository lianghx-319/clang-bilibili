#include <stdio.h>

int factorial(int n) {
    // negative value dosen't have factorial
    if (n < 0) return 0;
    // factorial of zero is one
    if (n == 0) return 1;

    return n * factorial(n - 1);
}

int sum_factorial(int n) {
    if (n <= 1) return 1;
    int sum = 0;
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        sum += factorial;
    }

    return sum;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int ret = factorial(n);
    int sum = sum_factorial(n);
    printf("factorial of %d is %d\n", n, ret);
    printf("sum factorial from %d to 1 is %d", n, sum);
    return 0;
}
