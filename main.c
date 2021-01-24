#define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("********** 0.play **********\n");
	printf("********** 1.quit **********\n");
	printf("****************************\n");
}

int main()
{
	int input;
	char board[ORDER][ORDER] = { 0 };

	srand((unsigned int)time(NULL));

	
	while (1)
	{
		menu();
		printf(">>>");
		scanf("%d", &input);
		printf("\n");

		switch (input)
		{
		case 0:
			game(board, ORDER);
			break;
		case 1:
			return; 
		default:
			printf("select error!!!\n please input again...\n");
			break;
		}

	}


	return 0;
}