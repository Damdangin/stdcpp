#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 20

int x = 20, y = 10;
int tailX[100], tailY[100];
int nTail = 5;

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {(short)x, (short)y};
	SetConsoleCursorPosition(consoleHandle, pos);
}

void draw_map()
{
	gotoxy(0, 0);

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
			{
				printf("#");
			}
			else if (i == y && j == x)
			{
				printf("O");
			}
			else
			{
				int isTail = 0;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						printf("o");
						isTail = 1;
						break;
					}
				}
				if (!isTail)
					printf(" ");
			}
		}
		printf("\n");
	}
}

int main()
{
	char input;
	system("cls");

	while (1)
	{
		draw_map();

		if (_kbhit())
		{
			input = _getch();
			int prevX = tailX[0];
			int prevY = tailY[0];
			int prev2X, prev2Y;
			tailX[0] = x;
			tailY[0] = y;

			for (int i = 1; i < nTail; i++)
			{
				prev2X = tailX[i];
				prev2Y = tailY[i];
				tailX[i] = prevX;
				tailY[i] = prevY;
				prevX = prev2X;
				prevY = prev2Y;
			}

			if (input == 'w')
				y--;
			if (input == 's')
				y++;
			if (input == 'a')
				x--;
			if (input == 'd')
				x++;
			if (input == 'q')
				break;
		}

		Sleep(50);
	}

	return 0; // 프레임 제한(쓰레드 대기상태)
}