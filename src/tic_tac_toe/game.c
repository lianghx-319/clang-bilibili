#include "game.h"

static const int COMBO_SIZE = TIC_TAC_TOE_COMBO * 8 - 8 + 1;

void RunGame() {
    // set seed for rand
    srand((unsigned int)time(NULL));
    int selected_menu = 0;
    do {
        selected_menu = ShowMenu();
        switch (selected_menu) {
        case 1:
            Start();
            break;
        case 0:
            Exit();
            break;
        default:
            printf("Please enter 1 or 0\n");
        }
    } while (selected_menu);
}

void Start() {
    char board[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL];
    InitBoard(board, TIC_TAC_TOE_ROW, TIC_TAC_TOE_COL);
    DisplayBoard(board, TIC_TAC_TOE_ROW, TIC_TAC_TOE_COL);
    while (1) {
        PlayerTurn(board, TIC_TAC_TOE_ROW, TIC_TAC_TOE_COL);
        DisplayBoard(board, TIC_TAC_TOE_ROW, TIC_TAC_TOE_COL);

        RobotTurn(board, TIC_TAC_TOE_ROW, TIC_TAC_TOE_COL);
        DisplayBoard(board, TIC_TAC_TOE_ROW, TIC_TAC_TOE_COL);
    }
}

int IsWin(char board[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int row, int col) {
}

void GetComboPosition(int points[COMBO_SIZE][2], int x, int y, int row, int col) {
    for (int i = 0; i < COMBO_SIZE; i++) {
        points[i][0] = -1;
        points[i][1] = -1;
    }

    int count = 1;
    points[0][0] = x;
    points[0][1] = y;

    for (int i = 1; i < COMBO_SIZE; i++) {
        int points_i[8][2] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
        points_i[0][0] = x + i;
        points_i[0][1] = y;

        points_i[1][0] = x + i;
        points_i[1][1] = y + i;

        points_i[2][0] = x;
        points_i[2][1] = y + i;

        points_i[3][0] = x - i;
        points_i[3][1] = y - i;

        points_i[4][0] = x - i;
        points_i[4][1] = y;

        points_i[5][0] = x - i;
        points_i[5][1] = y + i;

        points_i[6][0] = x;
        points_i[6][1] = y - i;

        points_i[7][0] = x + i;
        points_i[7][1] = y - i;

        for (int j = 0; j < 8; j++) {
            if (points_i[j][0] >= 0 && points_i[j][0] < TIC_TAC_TOE_COMBO
                && points_i[j][1] >= 0 && points_i[j][1] < TIC_TAC_TOE_COMBO) {
                points[count][0] = points_i[j][0];
                points[count][1] = points_i[j][1];
                count++;
            }
        }
    }
}

void PlayerTurn(char board[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int row, int col) {
    int x = 0;
    int y = 0;
    while (1) {
        printf("Your turn, enter a position: x y >");
        scanf("%d %d", &x, &y);
        if (IsLegalPosition(x - 1, y - 1, row, col) && IsEmptyPosition(board, x - 1, y - 1)) {
            board[x - 1][y - 1] = TIC_TAC_TOE_MARK_X;
            break;
        } else {
            printf("Bad position, enter again!\n");
        }
    }
}

void RobotTurn(char board[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int row, int col) {
    printf("Robot turn:>\n");
    while (1) {
        int x = rand() % row;
        int y = rand() % col;
        if (IsEmptyPosition(board, x, y)) {
            board[x][y] = TIC_TAC_TOE_MARK_O;
            break;
        }
    }
}

int IsLegalPosition(int x, int y, int row, int col) {
    return x >= 0 && x < row && y >= 0 && y < col;
}

int IsEmptyPosition(char board[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int x, int y) {
    return board[x][y] == TIC_TAC_TOE_MARK_EMPTY;
}

void DisplayBoard(char board[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf(" %c ", board[i][j]);
            if (j < col - 1) {
                printf("|");
            } else {
                printf("\n");
            }
        }
        if (i < row - 1) {
            for (int j = 0; j < col; j++) {
                printf("---");
                if (j < col - 1) {
                    printf("|");
                } else {
                    printf("\n");
                }
            }
        }
    }
}

void InitBoard(char board[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = TIC_TAC_TOE_MARK_EMPTY;
        }
    }
}

int ShowMenu() {
    int selected = 0;
    printf("**********************\n");
    printf("****** 1. Play  ******\n");
    printf("****** 0. Exit  ******\n");
    printf("**********************\n");
    printf("Enter: 1/0 >");
    scanf("%d", &selected);
    return selected;
}

void Exit() {
    printf("Game exited!\n");
}