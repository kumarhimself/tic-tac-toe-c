#include <stdio.h>
#include <stdbool.h>
#include "player.h"

// Function Prototype
bool valid_input(char *board, int *position);

char player_marker() {
	static int num_turns = -1;
	
	num_turns++;

	return (num_turns % 2 == 0) ? 'x' : 'o';
}

void player_input(char *board, int *position) {
	while (true) {
		printf("Please enter a position number: \n");
		scanf("%d", position);

		if (!valid_input(board, position)) {
			printf("Invalid input, please try again!\n");
		} else {
			break;
		}
	}
}

bool valid_input(char *board, int *position) {
	char value = *(board + *position - 1); 
	if (value == 'x' || value == 'o') {
		return false;
	} else {
		return true;
	}
}
