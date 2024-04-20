#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "AI.h"
#include "Board.h"
#include "CheckMove.h"
#include "EndGame.h"
#include "Log.h"
#include "Player.h"

// Function to convert a letter to its corresponding index (0-7)
int letter_to_index(char letter) {
    return tolower(letter) - 'a';
}

struct Move get_user_move() {
    struct Move move;

    // Get starting and ending position from user
    printf("Enter the starting and ending  position (format: a2 a3): ");
    char start_letter, end_letter;
    int start_number, end_number;
    scanf(" %c%d %c%d", &start_letter, &start_number, &end_letter, &end_number);
    move.start.x = letter_to_index(start_letter);
    move.start.y = 8-start_number;

    move.end.x = letter_to_index(end_letter);
    move.end.y = 8-end_number;

    return move;
}

int main(void) {
    // board initialization
    struct Board board;
    init_board(&board);

    // player initialization
    struct Player* white_player = create_player('W', false);
    struct Player* black_player = create_player('B', false);

    print_board(&board);
    while (true) {
        struct Move m = get_user_move();
        move_piece(&board, &m);
        print_board(&board);
    }
    return 0;
}
