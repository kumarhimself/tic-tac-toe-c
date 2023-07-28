char player_marker() {
	static int num_turns = 0;
	
	num_turns++;

	return (num_turns % 2 == 0) 'x' : 'o';
}
