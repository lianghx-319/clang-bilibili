#include <stdio.h>

void print(unsigned int num) {
    if (num > 9) {
        print(num / 10);
    }
    printf("%d ", num % 10);
}

// given a unsigned int 1234 output "1 2 3 4"
int main(int argc, char const *argv[]) {
    unsigned int num = 0;
    scanf("%u", &num);
    print(num);
    return 0;
}
