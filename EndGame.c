#include "EndGame.h"

bool is_in_check(struct Game *game, struct Player *player) {
    struct Board* board = &(game->board);
    enum PlayerColor opponent_color = (player->color == WHITE) ? BLACK : WHITE;
    struct Position king_position;

    // Find the position of the king of the current player
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            struct Piece* piece = board->squares[i][j];
            if (piece != NULL && piece->type == KING && piece->color == player->color) {
                king_position.x = i;
                king_position.y = j;
                break;
            }
        }
    }

    // Check if the king is under attack by any opponent's piece
    // Iterate over opponent's pieces to see if any can attack the king
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            struct Piece* piece = board->squares[i][j];
            if (piece != NULL && piece->color == opponent_color) {
                struct Move move;
                move.start.x = i;
                move.start.y = j;
                move.end.x = king_position.x;
                move.end.y = king_position.y;
                // If opponent's piece can legally move to the king's position, then king is in check
                if (is_legal_move(board, piece, &move)) {
                    return true;
                }
            }
        }
    }

    // King is not in check
    return false;
}

bool is_checkmate(struct Game* game, struct Player* player) {
    // 
    if (!is_in_check(game, player)) {
        // 
        return false;
    }

    // 
    struct Board* board = &(game->board);

    // 
    enum PlayerColor player_color = player->color;

    // 
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            struct Piece* piece = board->squares[i][j];
            if (piece != NULL && piece->color == player_color) {
                // 
                for (int x = 0; x < 8; ++x) {
                    for (int y = 0; y < 8; ++y) {
                        struct Move move = { {i, j}, {x, y} };
                        // 
                        if (is_legal_move(board, piece, &move)) {
                            // 
                            struct Board temp_board = *board;
                            temp_board.squares[x][y] = temp_board.squares[i][j];
                            temp_board.squares[i][j] = NULL;
                            if (!is_in_check(game, player)) {
                                // 
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }

    // 
    return true;
}

bool is_stalemate(struct Game* game, struct Player* player) {
    // 
    struct Board* board = &(game->board);

    // 
    enum PlayerColor player_color = player->color;

    // 
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            struct Piece* piece = board->squares[i][j];
            if (piece != NULL && piece->color == player_color) {
                // 
                for (int x = 0; x < 8; ++x) {
                    for (int y = 0; y < 8; ++y) {
                        struct Move move = { {i, j}, {x, y} };
                        // 
                        if (is_legal_move(board, piece, &move)) {
                            // 
                            return false;
                        }
                    }
                }
            }
        }
    }

    // 
    return true;
}
