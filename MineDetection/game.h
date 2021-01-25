# include <time.h>
# include <stdlib.h>
# include <stdio.h>

#define ROW 9
#define COL 9
#define ROW_EXT ROW + 2
#define COL_EXT COL + 2
#define MINE_CNT 10



void menu();
void game(char mine[ROW_EXT][COL_EXT], char show[ROW_EXT][COL_EXT], int rows, int cols);

