#include <stdio.h>
#include "whitebox.h"
#include <stdint.h>

void print_box(uint8_t arr[][16]);
uint8_t find_idx(uint8_t num);

int main(void) {
	unsigned char arr[16];
	for (int i = 0; i < 16; i++) {
		arr[i] = find_idx(tbox[0][i][0]);
	}
	
	int i = 1;
	while (i < 4) {
		sr(arr);
		i++;
	}

	for (int i = 0; i < 16; i++) {
		printf("%c ", arr[i]);
	}

	return 0;
}

void print_box(uint8_t arr[][16])
{
	for (int c = 0; c < 16; c++)
	{
		for (int r = 0; r < 16; r++)
		{
			printf("%X ", arr[c][r]);
		}
		printf("\n");
	}
}

unsigned char find_idx(uint8_t num) {
	unsigned char x, y;

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (num == sbox[i][j]) {
				y = i * 0x10;
				x = j;
			}
		}
	}

	return x + y;
}