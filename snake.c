#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 20

int x = 10, y = 10;

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(consoleHandle, pos);
}

void draw_map() {
	gotoxy(0,0);

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH -1) {
				printf("#");
			} else if (i == y && j == x) {
				printf("O");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main() {
	char input;

	system("cls");

	while (1) {
		draw_map();
		
		if (_kbhit()) {
			input = _getch();

			if(input == 'w') y--;
			if(input == 's') y++;
			if(input == 'a') x--;
			if(input == 'd') x++;
			if(input == 'q') break;
		}

		Sleep(10);
	}

	return 0; //프레임 제한(쓰레드 대기상태)
}