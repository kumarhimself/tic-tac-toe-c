#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "game.h"
#include "board.h"
#include "player.h"

// Function prototypes
void game_loop(char *board_ptr, int *num_elements);
bool check_winner(char *board_ptr);
bool restart_game();

void game() {
	// Board variables
	char board[3][3];
	char *board_ptr = &board[0][0];
	int num_elements = 9;

	while (true) {
		printf("Hello players, welcome to the bare bones Tic Tac Toe game!\n");
		printf("The first player will use the \'x\' marker and the second player will use the \'o\' marker\n");
	
		init_board(board_ptr, &num_elements);
		
		game_loop(board_ptr, &num_elements);	
		
		if (!restart_game()) {
			printf("Goodbye!");
			break;
		} else {
			printf("\n\n\n\n");
		}
	}
}

void game_loop(char *board_ptr, int *num_elements) {
	// Loop to keep current game running until someone wins
	while (true) {
		int position;

		char current_player = player_marker();
	
		printf("Player %c\'s turn:\n", current_player);
		print_board(board_ptr, num_elements);
		
		player_input(board_ptr, &position);

		perform_move(board_ptr, &current_player, &position);	
		
		if (check_winner(board_ptr)) {
			printf("Congrats player %c, you won!\n", current_player);
			break;
		}
	}	
}

bool check_winner(char *board_ptr) {
	// Check rows
	for (int i = 0; i < 7; i += 3) {
		char *board_value = board_ptr + i;
		if (*board_value == *(board_value + 1) && *board_value == *(board_value + 2)) return true;
	}

	// Check columns
	for (int i  = 0; i < 3; i++) {
		char *board_value = board_ptr + i;
		if (*board_value == *(board_value + 3) && *board_value == *(board_value + 6)) return true;
	}
	
	// Check diagonals
	if (*board_ptr == *(board_ptr + 4) && *board_ptr == *(board_ptr + 8)) return true;
	if (*(board_ptr + 2) == *(board_ptr + 4) &&  *(board_ptr + 2) == *(board_ptr + 6)) return true;	

	return false;
}

bool restart_game() {
	char answer;
	
	printf("Would you like to restart the game (y/n)? ");
	fflush(stdin);	
	scanf("%c", &answer);

	return (answer == 'y') ? true : false;
}
