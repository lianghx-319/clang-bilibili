#include <stdio.h>

int callatz(int n) {
    if (n % 2) {
        return (3 * n + 1) / 2;
    } else {
        return n / 2;
    }
}

void record(int hash[150], int n) {
    int a = n;
    while (a != 1) {
        a = callatz(a);
        hash[a] = 1;
    }
}
void initArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = 0;
    }
}

void sort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int len = 0;
    if (scanf("%d", &len)) {
        int arr[100] = {0};
        int ret[100] = {0};
        int hash[10000] = {0};
        initArr(arr, 100);
        initArr(ret, 100);
        initArr(hash, 10000);
        int index = 0;
        for (int i = 0; i < len; i++) {
            if (scanf("%d", &arr[i])) {
                record(hash, arr[i]);
            };
        }
        for (int i = 0; i < len; i++) {
            if (!hash[arr[i]]) {
                ret[index] = arr[i];
                index++;
            }
        }

        sort(ret, index);
        for (int i = 0; i < 100; i++) {
            if (ret[i]) {
                printf("%d", ret[i]);
                if (i < index - 1) {
                    printf(" ");
                }
            }
        }
    }

    return 0;
}
