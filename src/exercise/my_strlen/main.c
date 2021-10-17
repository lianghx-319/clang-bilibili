#include <stdio.h>

int my_strlen(char *str) {
    if (*str != '\0') {
        return 1 + my_strlen(++str);
    } else {
        return 0;
    }
}

int main(int argc, char const *argv[]) {
    char str[] = "";
    scanf("%s", str);
    printf("%d", my_strlen(str));
    return 0;
}
