#include <stdio.h>

char player_marker() {
	static int num_turns = 0;
	
	num_turns++;

	return (num_turns % 2 == 0) ? 'x' : 'o';
}

void player_input(int *row, int *col) {
	printf("Please enter a row number between 1-3: ");
	scanf("%d", row);
	printf("Please enter a column between 1-3: ");
	scanf("%d", col);
}
