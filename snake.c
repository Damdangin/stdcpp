#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

void draw_map() {
	// system("cls");

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH -1) {
				printf("#");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main() {
	draw_map();
	getchar();

	return 0;
}