#ifndef LOG_H
#define LOG_H

#include "Board.h"

// BoardNode structure definition
struct BoardNode {
    // State of the board
    struct Board board;
    // Pointer to the next node
    struct BoardNode *next;
};

// BoardList structure definition
struct BoardList {
    // Pointer to the head node
    struct BoardNode *head;
    // Pointer to the tail node
    struct BoardNode *tail;
};

// Function declarations for logging moves
void init_board_list(struct BoardList *list);
void insert_board(struct BoardList *list, struct Board *board);
void clear_board_list(struct BoardList *list);
void undo_move(struct Game *game, struct BoardList *list);

#endif /* LOG_H */
