char player_marker() {
	static int num_turns = 0;
	
	num_turns++;

	return (num_turns % 2 == 0) ? 'x' : 'o';
}

void player_input(int *row, int *col) {
	printf("Player %c, please enter a row number between 1-3: ", current_player);
	scanf("%d", row);
	printf("Player %c please enter a column between 1-3: ", current_player);
	scanf("%d", col);
}
