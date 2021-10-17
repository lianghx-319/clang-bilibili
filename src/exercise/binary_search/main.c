#include <stdio.h>

int binary_search(int arr[], int target, int len) {
    int left = 0;
    int right = len - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] < target) {
            left = mid;
        } else if (arr[mid] > target) {
            right = mid;
        } else {
            return mid;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    int len = sizeof(arr) / sizeof(arr[0]);
    int target_index = binary_search(arr, target, len);
    printf("target %d is at index %d", target, target_index);
    return 0;
}
