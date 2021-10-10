#include <stdio.h>

int main(int argc, char const *argv[]) {
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 0;
    while (i < 10) {
        printf("%d\n", nums[i]);
        i++;
    }
    return 0;
}
