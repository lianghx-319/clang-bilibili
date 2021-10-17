#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu() {
    printf("********************************\n");
    printf("** Guess number from 1 to 100 **\n");
    printf("*********** 1. Play ************\n");
    printf("*********** 0. Exit ************\n");
    printf("********************************\n");
}

void game() {
    int guess = -1;
    int target = rand() % 100;

    while (guess != target) {
        printf("Guess a number: ");
        scanf("%d", &guess);
        if (guess < target) {
            printf("Too small\n");
        } else if (guess > target) {
            printf("Too large\n");
        } else {
            printf("Bingo! Congratulation\n");
            break;
        }
    }
}

int main(int argc, char const *argv[]) {
    int menu_input = 0;
    srand(time(NULL));
    do {
        menu();
        printf("Please input number of selected menu\n");
        scanf("%d", &menu_input);
        switch (menu_input) {
        case 1:
            game();
            break;
        case 0:
            printf("Exited!\n");
            break;
        default:
            printf("Please input 1 or 0\n");
            break;
        }
    } while (menu_input);

    return 0;
}
