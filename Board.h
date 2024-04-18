#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include "Player.h"

// Piece type enumeration definition
enum PieceType {
    KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN
};

struct Position {
    // Horizontal coordinate
    int x;
    // Vertical coordinate
    int y;
};

struct Move {
    // Starting position
    struct Position start;
    // Ending position
    struct Position end;
};

struct Board {
    // Two-dimensional array representing pieces on each position of the board
    struct Piece *squares[8][8];
};

// Function to initialize the board
void init_board(struct Board *board);

// Function to copy the board
void copy_board(struct Board *src, struct Board *dest);

void print_board(struct Board* board);

struct Piece* create_piece(enum PieceType type, enum PlayerColor color);


#endif /* BOARD_H */
