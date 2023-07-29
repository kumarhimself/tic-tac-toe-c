#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "player.h"

// Function Prototype
void is_valid_input(char *prompt, int *scan_var);
bool is_position_taken(char *board, int *position);

char player_marker() {
	static int num_turns = -1;
	
	num_turns++;

	return (num_turns % 2 == 0) ? 'x' : 'o';
}

void player_input(char *board, int *position) {
	while (true) {
		char *prompt = malloc(sizeof(char) * 20);
		strcpy(prompt, "Please enter a position number: ");	
		is_valid_input(prompt, position);

		if (!is_position_taken(board, position)) {
			printf("This position is already taken, please try again!\n");
		} else {
			break;
		}
	}
}

void is_valid_input(char *prompt, int *scan_var) {
	while (true) {
		printf("%s\n", prompt);
		int num_read = scanf("%d", scan_var);

		if (num_read != 1) {
			printf("Oops, you entered an incorrect input, please try again!\n");
			fflush(stdin);
		} else {
			break;
		}	
	}
}

bool is_position_taken(char *board, int *position) {
	char value = *(board + *position - 1); 
	if (value == 'x' || value == 'o') {
		return false;
	} else {
		return true;
	}
}
