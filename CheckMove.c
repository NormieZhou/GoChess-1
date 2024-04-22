#include "CheckMove.h"
#include <stdlib.h> 

bool check_move_pawn(struct Board* board, struct Piece* piece, struct Move* move) {
    int start_x = move->start.x;
    int start_y = move->start.y;
    int end_x = move->end.x;
    int end_y = move->end.y;

    // Check if the move is within the board bounds
    if (start_x < 0 || start_x >= 8 || start_y < 0 || start_y >= 8 || end_x < 0 || end_x >= 8 || end_y < 0 || end_y >= 8) {
        return false;
    }

    // Check if the pawn is moving forward
    if (piece->color == BLACK) {
        if (end_y <= start_y) {
            return false; // Black pawns can only move forward
        }
    }
    else {
        if (end_y >= start_y) {
            return false; // White pawns can only move forward
        }
    }

    // Check if the pawn is moving two squares from its initial position
    if (piece->color == BLACK) {
        if (start_y == 1 && end_y != start_y + 2) {
            return false; // Black pawns can move two squares only from the starting position
        }
    }
    else {
        if (start_y == 6 && end_y != start_y - 2) {
            return false; // White pawns can move two squares only from the starting position
        }
    }

    // Check if the pawn is moving one square forward
    if (piece->color == BLACK) {
        if (end_y != start_y + 1) {
            return false;
        }
    }
    else {
        if (end_y != start_y - 1) {
            return false;
        }
    }

    // Check if the destination square is empty
    if (board->squares[end_x][end_y] != NULL) {
        return false; // Destination square is not empty
    }

    // Check if the pawn is capturing diagonally
    if (abs(end_x - start_x) == 1 && abs(end_y - start_y) == 1) {
        // Check if there is a piece of the opposite color to capture
        if (board->squares[end_x][end_y] == NULL || board->squares[end_x][end_y]->color == piece->color) {
            return false; // No piece to capture or same color piece
        }
    }

    return true;
}

bool check_move_knight(struct Board* board, struct Piece* piece, struct Move* move) {
    int start_x = move->start.x;
    int start_y = move->start.y;
    int end_x = move->end.x;
    int end_y = move->end.y;

    // Check if the move is within the board bounds
    if (start_x < 0 || start_x >= 8 || start_y < 0 || start_y >= 8 || end_x < 0 || end_x >= 8 || end_y < 0 || end_y >= 8) {
        return false;
    }

    // Check if the move is a valid knight move (L-shaped)
    int dx = abs(end_x - start_x);
    int dy = abs(end_y - start_y);
    if (!((dx == 1 && dy == 2) || (dx == 2 && dy == 1))) {
        return false;
    }

    // Check if the destination square is empty or contains an opponent's piece
    if (board->squares[end_x][end_y] != NULL && board->squares[end_x][end_y]->color == piece->color) {
        return false; // Destination square contains a piece of the same color
    }

    return true;
}

bool check_move_bishop(struct Board* board, struct Piece* piece, struct Move* move) {
    int start_x = move->start.x;
    int start_y = move->start.y;
    int end_x = move->end.x;
    int end_y = move->end.y;

    // Check if the move is within the board bounds
    if (start_x < 0 || start_x >= 8 || start_y < 0 || start_y >= 8 || end_x < 0 || end_x >= 8 || end_y < 0 || end_y >= 8) {
        return false;
    }

    // Check if the move is diagonal
    int dx = abs(end_x - start_x);
    int dy = abs(end_y - start_y);
    if (dx != dy) {
        return false; // Bishop moves diagonally
    }

    // Check if there are any pieces blocking the path
    int dir_x = (end_x > start_x) ? 1 : -1;
    int dir_y = (end_y > start_y) ? 1 : -1;
    int x = start_x + dir_x;
    int y = start_y + dir_y;
    while (x != end_x && y != end_y) {
        if (board->squares[x][y] != NULL) {
            return false; // Path is blocked
        }
        x += dir_x;
        y += dir_y;
    }

    // Check if the destination square is empty or contains an opponent's piece
    if (board->squares[end_x][end_y] != NULL && board->squares[end_x][end_y]->color == piece->color) {
        return false; // Destination square contains a piece of the same color
    }

    return true;
}

bool check_move_rook(struct Board* board, struct Piece* piece, struct Move* move) {
    int start_x = move->start.x;
    int start_y = move->start.y;
    int end_x = move->end.x;
    int end_y = move->end.y;

    // Check if the move is within the board bounds
    if (start_x < 0 || start_x >= 8 || start_y < 0 || start_y >= 8 || end_x < 0 || end_x >= 8 || end_y < 0 || end_y >= 8) {
        return false;
    }

    // Check if the move is either horizontal or vertical
    if (start_x != end_x && start_y != end_y) {
        return false; // Rook moves either horizontally or vertically
    }

    // Check if there are any pieces blocking the path
    if (start_x == end_x) { // Vertical move
        int dir_y = (end_y > start_y) ? 1 : -1;
        int y = start_y + dir_y;
        while (y != end_y) {
            if (board->squares[start_x][y] != NULL) {
                return false; // Path is blocked
            }
            y += dir_y;
        }
    }
    else { // Horizontal move
        int dir_x = (end_x > start_x) ? 1 : -1;
        int x = start_x + dir_x;
        while (x != end_x) {
            if (board->squares[x][start_y] != NULL) {
                return false; // Path is blocked
            }
            x += dir_x;
        }
    }

    // Check if the destination square is empty or contains an opponent's piece
    if (board->squares[end_x][end_y] != NULL && board->squares[end_x][end_y]->color == piece->color) {
        return false; // Destination square contains a piece of the same color
    }

    return true;
}

bool check_move_queen(struct Board* board, struct Piece* piece, struct Move* move) {
    int start_x = move->start.x;
    int start_y = move->start.y;
    int end_x = move->end.x;
    int end_y = move->end.y;

    // Check if the move is within the board bounds
    if (start_x < 0 || start_x >= 8 || start_y < 0 || start_y >= 8 || end_x < 0 || end_x >= 8 || end_y < 0 || end_y >= 8) {
        return false;
    }

    // Check if the move is either horizontal, vertical, or diagonal
    int dx = abs(end_x - start_x);
    int dy = abs(end_y - start_y);
    if (dx != 0 && dy != 0 && dx != dy) {
        return false; // Queen moves either horizontally, vertically, or diagonally
    }

    // Check if the path is clear
    if (dx == 0 || dy == 0) { // Horizontal or vertical move
        int dir_x = (end_x > start_x) ? 1 : (end_x < start_x) ? -1 : 0;
        int dir_y = (end_y > start_y) ? 1 : (end_y < start_y) ? -1 : 0;
        int x = start_x + dir_x;
        int y = start_y + dir_y;
        while (x != end_x || y != end_y) {
            if (board->squares[x][y] != NULL) {
                return false; // Path is blocked
            }
            x += dir_x;
            y += dir_y;
        }
    }
    else { // Diagonal move
        int dir_x = (end_x > start_x) ? 1 : -1;
        int dir_y = (end_y > start_y) ? 1 : -1;
        int x = start_x + dir_x;
        int y = start_y + dir_y;
        while (x != end_x) {
            if (board->squares[x][y] != NULL) {
                return false; // Path is blocked
            }
            x += dir_x;
            y += dir_y;
        }
    }

    // Check if the destination square is empty or contains an opponent's piece
    if (board->squares[end_x][end_y] != NULL && board->squares[end_x][end_y]->color == piece->color) {
        return false; // Destination square contains a piece of the same color
    }

    return true;
}

bool check_move_king(struct Board* board, struct Piece* piece, struct Move* move) {
    int start_x = move->start.x;
    int start_y = move->start.y;
    int end_x = move->end.x;
    int end_y = move->end.y;

    // Check if the move is within the board bounds
    if (start_x < 0 || start_x >= 8 || start_y < 0 || start_y >= 8 || end_x < 0 || end_x >= 8 || end_y < 0 || end_y >= 8) {
        return false;
    }

    // Check if the move is only one square away in any direction
    int dx = abs(end_x - start_x);
    int dy = abs(end_y - start_y);
    if (dx > 1 || dy > 1) {
        return false; // King moves only one square in any direction
    }

    // Check if the destination square is empty or contains an opponent's piece
    if (board->squares[end_x][end_y] != NULL && board->squares[end_x][end_y]->color == piece->color) {
        return false; // Destination square contains a piece of the same color
    }

    return true;
}

bool is_legal_move(struct Board* board, struct Piece* piece, struct Move* move) {
    //
    switch (piece->type) {
    case PAWN:
        return check_move_pawn(board, piece, move);
    case KNIGHT:
        return check_move_knight(board, piece, move);
    case BISHOP:
        return check_move_bishop(board, piece, move);
    case ROOK:
        return check_move_rook(board, piece, move);
    case QUEEN:
        return check_move_queen(board, piece, move);
    case KING:
        return check_move_king(board, piece, move);
    default:
        //
        return false;
    }
}

    return true;
}
