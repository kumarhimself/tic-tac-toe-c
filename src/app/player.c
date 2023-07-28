#include <stdio.h>

// Function Prototype
bool valid_input(char *board, int *row, int *col);

char player_marker() {
	static int num_turns = 0;
	
	num_turns++;

	return (num_turns % 2 == 0) ? 'x' : 'o';
}

void player_input(char *board, int *row, int *col) {
	printf("Please enter a row number between 1-3: \n");
	scanf("%d", row);
	printf("Please enter a column between 1-3: \n");
	scanf("%d", col);

	if (valid_input(board, row, col)) {
		printf("Invalid input, please try again!\n");
		player_input(board, row, col);
	}
}

bool valid_input(char *board, int *row, int *col) {
	if (*(board + ((*row) * (*col) - 1)) != ' ') {
		return false;
	} else {
		return true;
	}
}
