#ifndef ENDGAME_H
#define ENDGAME_H

#include "Board.h"

// Function declarations for checking game end conditions
int is_in_check(struct Game *game, struct Player *player);
int is_checkmate(struct Game *game, struct Player *player);
int is_stalemate(struct Game *game, struct Player *player);

#endif /* ENDGAME_H */
