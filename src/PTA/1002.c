#include <stdio.h>

int sum(char *str) {
    if (*str == '\0') {
        return 0;
    };
    int num = *str - '0';
    return num + sum(str + 1);
}

void print_pinyin(int num, int source) {
    char chinese_number[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    if (num > 9) {
        print_pinyin(num / 10, source);
    }
    printf("%s", chinese_number[num % 10]);
    if (num != source) {
        printf(" ");
    }
}

// https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384
int main() {
    char a[101];

    while (scanf("%s", a) != EOF) {
        int num = sum(a);
        print_pinyin(num, num);
    }

    return 0;
}
