#include <stdio.h>

// hanoi(1, A, B, C) = A -> C = 1
// hanoi(2, A, B, C) = A -> B, A -> C, B -> C = 2 = hanoi(1, A, C, B) + hanoi(1, A, B, C) + hanoi(1, B, A, C)
// hanoi(3, A, B, C) = A -> C, A -> B, C -> B, A -> C, B -> A, B -> C, A -> C = 7 = hanoi(2, A, C, B) + hanoi(1, A, B, C) + hanoi(2, B, A, C)
// hanoi(n, A, B, C) = hanoi(n - 1, A, C, B) + hanoi(1, A, B, C) + hanoi(n - 1, B, A, C)
void hanoi(int n, char *from, char *mid, char *to) {
    if (n == 1) {
        printf("%s -> %s\n", from, to);
        return;
    }
    hanoi(n - 1, from, to, mid);
    hanoi(1, from, mid, to);
    hanoi(n - 1, mid, from, to);
}

int main(int argc, char const *argv[]) {
    int n = 0;
    scanf("%d", &n);
    hanoi(n, "A", "B", "C");

    return 0;
}
