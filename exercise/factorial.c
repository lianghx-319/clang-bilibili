long long Factorial(int n) {
    if (n == 1) {
        return 1;
    }

    if (n > 1) {
        return Factorial(n - 1) * n;
    }

    return 0;
}