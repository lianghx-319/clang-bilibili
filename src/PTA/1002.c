#include <stdio.h>

char *get_pinyin(int num) {
    char chinese_number[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    if (num >= 10 || num < 0) {
        return "";
    }
    return chinese_number[num];
}

int main() {
    int a = -1;
    scanf("%d", &a);
    printf("%s", get_pinyin(a));
    return 0;
}

// https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384
// int main() {
//     int a, b;

//     while (scanf("%d %d", &a, &b) != EOF)
//         printf("%d\n", a + b);

//     return 0;
// }