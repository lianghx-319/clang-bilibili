#include <stdio.h>

struct Student {
    char name[20];
    int age;
    double score;
};

int main(int argc, char const *argv[]) {
    struct Student s = {"a", 20, 20.4};
    printf("%s %d %lf\n", s.name, s.age, s.score);

    struct Student *ps = &s;
    printf("%s %d %lf\n", ps->name, ps->age, ps->score);
    return 0;
}
