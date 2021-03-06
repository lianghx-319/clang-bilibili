#include <stdio.h>

int is_prime(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int main(int argc, char const *argv[]) {
    int year = 0;
    scanf("%d", &year);
    if (is_prime(year)) {
        printf("Year %d is leap year", year);
    } else {
        printf("Year %d is not leap year", year);
    }
    return 0;
}
