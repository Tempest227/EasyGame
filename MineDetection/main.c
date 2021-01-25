#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

int main()
{
	int input;
	char mine[ROW_EXT][ROW_EXT] = { 0 };
	char show[ROW_EXT][ROW_EXT] = { 0 };

	srand((unsigned char)time(NULL));
	do 
	{
		menu();
		printf(">>> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(mine, show, ROW_EXT, COL_EXT); break;
		case 0: break;
		default:printf("input error!\n"); break;
		}
	} while (input);


	return 0;
}