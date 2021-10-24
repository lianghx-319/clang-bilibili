#include <stdio.h>

void output(int pass) {
    if (pass) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int is_pass(char str[100], int len) {
    int cur = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    char pta[3] = {'P', 'A', 'T'};
    for (int i = 0; i < len; i++) {
        if (str[i] == '\0') {
            break;
        }

        if (cur == 3 && str[i] != 'A') {
            return 0;
        }

        if (str[i] != 'A' && str[i] != pta[cur]) {
            break;
        }

        if (cur == 0 && str[i] == 'A') {
            a++;
        }
        if (cur == 1 && str[i] == 'A') {
            b++;
        }
        if (cur == 2 && str[i] == 'A') {
            b++;
        }
        if (cur == 3 && str[i] == 'A') {
            c++;
        }
        if (pta[cur] == str[i]) {
            cur++;
        }
    }

    return cur == 3 && a * b == c;
}

// https://pintia.cn/problem-sets/994805260223102976/problems/994805323154440192
int main() {
    int len = 0;
    if (scanf("%d", &len)) {
        for (int i = 0; i < len; i++) {
            char str[101] = {};
            if (scanf("%s", str)) {
                output(is_pass(str, 101));
            };
        }
    };

    return 0;
}