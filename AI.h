#ifndef AI_H
#define AI_H

#include "Board.h"

// Alpha Beta search result structure definition
struct AlphaBetaResult {
    // Best move
    struct Move best_move;
    // Best score
    int score;
};

// Alpha Beta search function definition
struct AlphaBetaResult alpha_beta_search(struct Game *game, int depth, int alpha, int beta, struct Player *player);

// Function to evaluate the position score
int evaluate_position(struct Game *game, struct Player *player);

// Function to generate all legal moves
struct Move *generate_legal_moves(struct Game *game, struct Player *player, int *num_moves);

#endif /* AI_H */
