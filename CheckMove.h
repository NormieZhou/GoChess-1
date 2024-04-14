#ifndef CHECKMOVE_H
#define CHECKMOVE_H

#include "Board.h"

// Function declarations for checking moves
bool check_move_pawn(struct Piece *board[8][8], int x, int y);
bool check_move_knight(struct Piece *board[8][8], int x, int y);
bool check_move_bishop(struct Piece *board[8][8], int x, int y);
bool check_move_rook(struct Piece *board[8][8], int x, int y);
bool check_move_queen(struct Piece *board[8][8], int x, int y);
bool check_move_king(struct Piece *board[8][8], int x, int y);
bool special_moves(struct Piece *board[8][8], int x, int y);

#endif /* CHECKMOVE_H */
