#include <stdio.h>
#include <string.h>

int main() {
    int len;
    char name[11];
    char id[11];
    int score = 0;
    char max_name[11] = "";
    char max_id[11] = "";
    int max_score = -1;
    char min_name[11] = "";
    char min_id[11] = "";
    int min_score = 101;
    if (scanf("%d", &len)) {
        while (scanf("%s %s %d", name, id, &score) != EOF) {
            if (score > max_score) {
                max_score = score;
                strcpy(max_name, name);
                strcpy(max_id, id);
            }
            if (score < min_score) {
                min_score = score;
                strcpy(min_name, name);
                strcpy(min_id, id);
            }
        }
        printf("%s %s\n", max_name, max_id);
        printf("%s %s\n", min_name, min_id);
    };

    return 0;
}
