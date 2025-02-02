#ifndef CHECKMOVE_H
#define CHECKMOVE_H

#include "Board.h"

// Function declarations for checking moves
bool check_move_pawn(struct Board* board, struct Piece* piece, struct Move* move);
bool check_move_knight(struct Board* board, struct Piece* piece, struct Move* move);
bool check_move_bishop(struct Board* board, struct Piece* piece, struct Move* move);
bool check_move_rook(struct Board* board, struct Piece* piece, struct Move* move);
bool check_move_queen(struct Board* board, struct Piece* piece, struct Move* move);
bool check_move_king(struct Board* board, struct Piece* piece, struct Move* move);
bool special_moves(struct Board* board, struct Piece* piece, struct Move* move);

#endif /* CHECKMOVE_H */
