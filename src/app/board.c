#include <stdio.h>

void init_board(char *board_ptr, int *num_elements) {
	for(int i = 0; i < *num_elements; i++) {
		*(board_ptr + i) = (i + 1) + '0';
	}
}

void print_board(char *board_ptr, int *num_elements) {
	printf("\n");
	for (int i = 0; i < *num_elements; i += 3) {
		printf("%c | %c | %c\n", *(board_ptr + i), *(board_ptr + i + 1), *(board_ptr + i + 2));
		
		if (i + 2 < (*num_elements - 1)) {
			printf("---------\n");
		} 
	}
	printf("\n");
}

void perform_move(char *board_ptr, char *player, int *position) {
	*(board_ptr + *position - 1) = *player; 
}
