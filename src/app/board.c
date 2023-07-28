#include <stdio.h>

void init_board(char *board_ptr, int *num_elements) {
	for(int i = 0; i < *num_elements; i++) {
		*(board_ptr + i) = ' ';
	}
}

void print_board(char *board_ptr, int *num_elements) {
	for (int i = 0; i < *num_elements; i += 3) {
		printf("%c|%c|%c\n", *(board_ptr + i), *(board_ptr + i + 1), *(board_ptr + i + 2));
		
		if (i + 2 < (*num_elements - 1)) {
			printf("-----\n");
		} 
	}
}
