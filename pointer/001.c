#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 10;
    int *pa = &a;
    *pa = 20;
    printf("%d", a);
    return 0;
}
