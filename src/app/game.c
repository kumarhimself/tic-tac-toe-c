#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "game.h"
#include "board.h"
#include "player.h"

// Function prototypes
void game_loop(char *board_ptr, int *num_elements);
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

		if (!restart_game()) break;
	}
}

void game_loop(char *board_ptr, int *num_elements) {
	// Loop to keep current game running until someone wins
	while (true) {
		int row;
		int col;	
	
		char current_player = player_marker();
	
		printf("Player %c\'s turn:\n", current_player);
		print_board(board_ptr, num_elements);
		
		player_input(board_ptr, &row, &col);

		// TODO: Execute player move
		// TODO: Check if current player won, and if so, end current game
		printf("**ENDGAME**");
		break;
	}	
}

bool restart_game() {
	char answer;
	printf("Would you like to restart the game (y/n)?");
	scanf("%c", &answer);

	return (answer == 'y') ? true : false;
}
