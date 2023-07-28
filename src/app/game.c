#include <stdio.h>
#include <stdbool.h>

#include "game.h"
#include "board.h"
#include "player.h"

void game() {
	// Board variables
	char board[3][3];
	char *board_ptr = &board[0][0];
	int num_elements = 9;

	while (true) {
		game_loop(board_ptr, &num_elements);
		
		if (restart_game()) break;
	}

	// Loop to keep application running until player wants to quit
	game_loop(*board_ptr, num_elements);
}

void game_loop(char *board_ptr, int *num_elements) {
	printf("Hello players, welcome to the bare bones Tic Tac Toe game!");
	printf("The first player will use the \'x\' marker and the second player will use the \'o\' marker");

	// Loop to keep current game running until someone wins
	while (true) {
		char current_player = player_marker();
			
		printf("Player %c\'s turn:", current_player);
		init_board(board_ptr, &num_elements);
		printf("Player %c, please enter a column number between 1-3: ", current_player);
		scanf();
		printf("Player %c please enter a column: ", current_player);
	}	
}

bool restart_game() {
	char answer;
	printf("Would you like to restart the game (y/n)?");
	scanf("%c", &answer);

	return (answer == 'y') ? true : false;
}
