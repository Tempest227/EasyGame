#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
int g_total_cnt = ROW*COL;
void menu()
{
	printf("---------------------\n");
	printf("\n");
	printf("        1.play       \n");
	printf("        0.quit       \n");
	printf("\n");
	printf("---------------------\n");
	
}

void InitBoard(char board[ROW_EXT][COL_EXT], int rows, int cols, char symbol)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = symbol;
		}
	}
}

void DisplayBoard(char board[ROW_EXT][COL_EXT], int rows, int cols)
{
	int i, j;

	for (i = 0; i <= rows; i++)
	{
		for (j = 0; j <= cols; j++)
		{
			if (0 == i)
			{
				printf("%d ", j);
			}
			else if (0 == j)
			{
				printf("%d ", i);
			}
			else
			{
				printf("%c ", board[i][j]);
			}
		
		}
		printf("\n");
	}
	printf("---------------------\n");
}

void SetMine(char mine[ROW_EXT][COL_EXT], int rows, int cols, int cnt)
{
	while (cnt > 0)
	{
		int x = rand() % rows + 1;
		int y = rand() % cols + 1;
		
		if ('1' == mine[x][y])
		{
			break;
		}
		else
		{
			mine[x][y] = '1';
			cnt--;
		}		
	}
}
char CalcNumberOfMine(char mine[ROW_EXT][COL_EXT], int x, int y)
{
	return  mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1]
		+ mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1]
		- 8*'0';
}

int FindMine(char mine[ROW_EXT][COL_EXT], char show[ROW_EXT][COL_EXT], int rows, int cols)
{
	int x, y;

	printf("please input coordinate(x,y):\n>>> ");
	scanf("%d%d", &x, &y);
	if (x >= 1 && x <= rows && y >= 1 && y <= cols && show[x][y] == '*')
	{
		if (mine[x][y] != '0')
		{
			printf("Game Over!\n");
			return 0;
		}	
		if (g_total_cnt == ROW*COL - MINE_CNT)
		{
			printf("You win!\n");
			return 0;
		}
		if ('0' == mine[x][y])
		{
			g_total_cnt--;
			char ch = CalcNumberOfMine(mine, x, y);
			show[x][y] = ch + '0';
			return 1;
		}		
	}
	else
	{
		printf("input error!\n");
		return 1;
	}
	
}

void game(char mine[ROW_EXT][COL_EXT], char show[ROW_EXT][COL_EXT], int rows, int cols)
{
	InitBoard(mine, rows, cols, '0');
	InitBoard(show, rows, cols, '*');

	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	SetMine(mine, ROW,COL, MINE_CNT);
	printf("testing...\n");
	DisplayBoard(mine, ROW, COL);

	while (FindMine(mine, show, ROW, COL))
	{
		DisplayBoard(show, ROW, COL);
	}
	
}