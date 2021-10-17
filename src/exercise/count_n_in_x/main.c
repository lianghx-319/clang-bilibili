#include <stdio.h>

int count_n(int n, int x) {
    if (x > 9) {
        return count_n(n, x / 10) || x % 10 == n;
    } else {
        return x % 10 == n;
    }
}

int main() {
    int n = 0;
    int x = 0;
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= x; i++) {
        if (count_n(n, i)) {
            printf("%d\n", i);
        };
    }
    return 0;
}
