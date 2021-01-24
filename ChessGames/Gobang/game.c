#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"



void InitBoard(char *arr, int order)
{
	int i, j;

	for (i = 0; i < order; i++)
	{
		for (j = 0; j < order; j++)
		{
			arr[i * order + j] = ' ';
		}
	}
		
}

void DispalyBoard(char *arr, int order)
{
	int i, j;

	for (i = 0; i < order; i++)
	{
		for (j = 0; j < order; j++)
		{
			if (j != order - 1)
			{
				printf(" %c |",arr[i * order + j]);
			}
			else
			{
				printf(" %c \n",arr[i * order + j]);
			}

		}
		for (j = 0; j <= order; j++)
		{
			if (j != order && i != order - 1)
			{
				printf("--- ");
			}

		}
		printf("\n");
	}
}

void PlayerMove(char *arr, int order)
{
	int x, y;
	int flag;

	while (1)
	{
		printf("please input coordinate(x,y)\n");
		printf(">>> ");
		scanf("%d%d", &x, &y);

		if ((x >= 1 && x <= order) && (y >= 1 && y <= order))
		{
			arr[(x - 1) * order + y - 1] = '*';
			break;
		}
		else
		{
			printf("error!!\n");
		}
	}
	

}

void ComputerMove(char *arr, int order)
{
	int x = rand() % order;
	int y = rand() % order;

	while (1)
	{
		if (arr[(x - 1) * order + y - 1] == ' ')
		{
			arr[(x - 1) * order + y - 1] = '#';
			break;
		}
		else
		{
			x = rand() % order;
		    y = rand() % order;
		}
	}
}

int IsFull(char *arr, int order)
{
	int i;
	for (i = 0; i < order * order; i++)
	{
		if (arr[i] == ' ')
		{
			return 0;
		}
	}
	return 1;
}

int CheckWin(char *arr, int order)
{
	int i;

	if (   arr[0] == '*' && arr[0] == arr[1] && arr[1] == arr[2] 
		|| arr[3] == '*' && arr[3] == arr[4] && arr[4] == arr[5]
		|| arr[6] == '*' && arr[6] == arr[7] && arr[7] == arr[8]
		|| arr[0] == '*' && arr[0] == arr[3] && arr[3] == arr[6]
		|| arr[1] == '*' && arr[1] == arr[4] && arr[4] == arr[7]
		|| arr[2] == '*' && arr[2] == arr[5] && arr[5] == arr[8])
	{
		return 1;
	}
	if (   arr[0] == '*' && arr[0] == arr[4] && arr[4] == arr[8] 
		|| arr[2] == '*' && arr[2] == arr[4] && arr[4] == arr[6])
	{
		return 1;
	}

	if (   arr[0] == '#' && arr[0] == arr[1] && arr[1] == arr[2]
		|| arr[3] == '#' && arr[3] == arr[4] && arr[4] == arr[5]
		|| arr[6] == '#' && arr[6] == arr[7] && arr[7] == arr[8]
		|| arr[0] == '#' && arr[0] == arr[3] && arr[3] == arr[6]
		|| arr[1] == '#' && arr[1] == arr[4] && arr[4] == arr[7]
		|| arr[2] == '#' && arr[2] == arr[5] && arr[5] == arr[8])
	{
		return -1;
	}
	if (   arr[0] == '#' && arr[0] == arr[4] && arr[4] == arr[8] 
		|| arr[2] == '#' && arr[2] == arr[4] && arr[4] == arr[6])
	{
		return -1;
	}
	if (IsFull(arr, order))
	{
		return 0;
	}
	return ORDER;
}

int Win(char *arr, int order)
{
	int ret = CheckWin(arr, order);
	if (-1 == ret)
	{
		printf("You lose!!!\n");
		return -1;
	}
	if (0 == ret)
	{
		printf("Draw!!!\n");
		return 0;
	}
	if (1 == ret)
	{
		printf("You win!!!\n");
		return 1;
	}
	return ORDER;
}
void game(char *arr, int order)
{
	InitBoard(arr, order);
	DispalyBoard(arr, order);
	while (1)
	{
		PlayerMove(arr, order);
		DispalyBoard(arr, order);
		if (ORDER != Win(arr, order))
		{
			break;
		}
		
		ComputerMove(arr, order);
		DispalyBoard(arr, order);
		if (ORDER != Win(arr, order))
		{
			break;
		}
	}
	
}
