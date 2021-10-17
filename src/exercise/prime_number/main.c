#include <stdio.h>
#include <math.h>

int is_prime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char const *argv[]) {
    int num = 0;
    scanf("%d", &num);
    if (is_prime(num)) {
        printf("%d is prime", num);
    } else {
        printf("%d is not prime", num);
    }
    return 0;
}
