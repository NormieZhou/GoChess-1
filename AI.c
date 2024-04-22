#include "AI.h"

struct AlphaBetaResult alpha_beta_search(struct Game *game, int depth, int alpha, int beta, struct Player *player) {
    struct AlphaBetaResult ai;
    struct Move move;
    struct Position po1, po2;
    po1.x = 1;
    po1.y = 1;
    po2.x = 1;
    po2.y = 1;
    move.end = po1;
    move.start = po2;
    ai.best_move = move;
    ai.score = 1;
    return ai;
}

int evaluate_position(struct Game *game, struct Player *player) {
    return 0;
}

struct Move *generate_legal_moves(struct Game *game, struct Player *player, int *num_moves) {
    struct Move move;
    return &move;
}
