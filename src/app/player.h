#ifndef PLAYER_H
#define PLAYER_H

char player_marker();
void player_input(char *board, int *row, int *col);
bool valid_input(char *board, int *row, int *col);

#endif
