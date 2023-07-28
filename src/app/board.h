#ifndef BOARD_H
#define BOARD_H

void init_board(char *board_ptr, int *num_elements);
void print_board(char *board_ptr, int *num_elements);
void perform_move(char *board_ptr, char *player, int *position);

#endif
