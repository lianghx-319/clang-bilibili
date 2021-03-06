#include "game.h"

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
        char ret = TIC_TAC_TOE_MARK_EMPTY;
        PlayerTurn(board, TIC_TAC_TOE_ROW, TIC_TAC_TOE_COL);
        DisplayBoard(board, TIC_TAC_TOE_ROW, TIC_TAC_TOE_COL);
        ret = IsWin(board, TIC_TAC_TOE_ROW, TIC_TAC_TOE_COL);
        ShowEndMessage(ret);
        if (ret != TIC_TAC_TOE_MARK_EMPTY) {
            break;
        }

        RobotTurn(board, TIC_TAC_TOE_ROW, TIC_TAC_TOE_COL);
        DisplayBoard(board, TIC_TAC_TOE_ROW, TIC_TAC_TOE_COL);
        ret = IsWin(board, TIC_TAC_TOE_ROW, TIC_TAC_TOE_COL);
        ShowEndMessage(ret);
        if (ret != TIC_TAC_TOE_MARK_EMPTY) {
            break;
        }
    }
}

void ShowEndMessage(char ret) {
    switch (ret) {
    case TIC_TAC_TOE_MARK_FULL:
        printf("The game is drawn.\n");
        break;
    case TIC_TAC_TOE_MARK_O:
        printf("You lose!\n");
        break;
    case TIC_TAC_TOE_MARK_X:
        printf("You win!\n");
        break;
    default:
        break;
    }
}

char IsWin(char board[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != TIC_TAC_TOE_MARK_EMPTY) {
            return board[i][0];
        }
    }

    for (int j = 0; j < col; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != TIC_TAC_TOE_MARK_EMPTY) {
            return board[0][j];
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    if (IsGameDrawn(board, row, col)) {
        return TIC_TAC_TOE_MARK_FULL;
    } else {
        return TIC_TAC_TOE_MARK_EMPTY;
    }
}

int IsGameDrawn(char board[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == TIC_TAC_TOE_MARK_EMPTY) {
                return 0;
            }
        }
    }
    return 1;
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