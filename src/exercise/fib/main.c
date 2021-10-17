#include <stdio.h>

// 斐波拉契数
// x: 1 2 3 4 5 6
// y: 1 1 2 3 5 8

// 递归
int fib1(int n) {
    if (n > 2) {
        return fib1(n - 1) + fib1(n - 2);
    } else {
        return 1;
    }
}

// 迭代
int fib(int n) {
    int a = 1;
    int b = 1;
    int temp = 0;

    for (int i = 3; i < n + 1; i++) {
        temp = b;
        b = a;
        a = temp + b;
    }

    return a;
}

int main() {
    int n = 1;
    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}
