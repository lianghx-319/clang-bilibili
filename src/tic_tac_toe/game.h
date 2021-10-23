#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TIC_TAC_TOE_ROW 3
#define TIC_TAC_TOE_COL 3
// win if combo count is n
#define TIC_TAC_TOE_COMBO 3

enum TIC_TAC_TOE_MARK {
    TIC_TAC_TOE_MARK_X = '*',
    TIC_TAC_TOE_MARK_O = '#',
    TIC_TAC_TOE_MARK_EMPTY = ' ',
    TIC_TAC_TOE_MARK_FULL = 'e',
};

enum TIC_TIC_TOE_STATUS {
    TIC_TAC_TOE_ROBOT_WIN,
    TIC_TAC_TOE_PLAYER_WIN,
    TIC_TAC_TOE_DRAW,
};

// Run game process
void RunGame();

// Show game menus
int ShowMenu();

// start name
void Start();

// exit game
void Exit();

void InitBoard(char[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int row, int col);

void DisplayBoard(char[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int row, int col);

void PlayerTurn(char[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int row, int col);

void RobotTurn(char[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int row, int col);

int IsLegalPosition(int x, int y, int row, int col);

int IsEmptyPosition(char[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int x, int y);

char IsWin(char[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int row, int col);

int IsGameDrawn(char[TIC_TAC_TOE_ROW][TIC_TAC_TOE_COL], int row, int col);

void ShowEndMessage(char ret);
