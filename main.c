#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "AI.h"
#include "Board.h"
#include "Game.h"
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
    // 提示用户选择游戏模式
    printf("Welcome to Chess Game!\n");
    printf("Please choose the game mode:\n");
    printf("1. Human vs Human\n");
    printf("2. Human vs AI\n");
    printf("3. AI vs AI\n");

    int choice;
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    struct Game game;
    struct Player player1, player2;
    struct Move move;
    struct Piece piece;

    // 初始化玩家信息
    // 玩家1为白色，玩家2为黑色
    player1.color = WHITE;
    player2.color = BLACK;

    // 根据用户选择初始化游戏
    switch (choice) {
    case 1:
        // 人人模式
        printf("Human vs Human mode selected.\n");
        player1.isComputer = false;
        player2.isComputer = false;
        break;
    case 2:
        // 人机模式
        printf("Human vs AI mode selected.\n");
        player1.isComputer = false;
        player2.isComputer = true;
        break;
    case 3:
        // 机机模式
        printf("AI vs AI mode selected.\n");
        player1.isComputer = true;
        player2.isComputer = true;
        break;
    default:
        printf("Invalid choice. Exiting...\n");
        return 1;
    }
    init_game(&game, player1, player2);
    while (true) {
        printf("It is player1's turn:\n");
        print_board(&game.board);
        if (player1.isComputer) {

        }
        else {
            do {
                move = get_user_move();
                piece = *game.board.squares[move.start.y][move.start.x];
            } while (!is_legal_move(&game.board, &piece, &move) || piece.color!=player1.color);
            move_piece(&game.board, &move);
            insert_board(&game.log, &game.board);
        }
        /*
        if (is_checkmate(&game,&player2)) {
            printf("Player1 Win!\n");
            break;
        }
        else if (is_stalemate(&game, &player2)) {
            printf("Stalemate!\n");
            break;
        }
        */
        switch_players(&game);
        printf("It is player2's turn:\n");
        print_board(&game.board);
        if (player2.isComputer) {

        }
        else {
            do {
                move = get_user_move();
                piece = *game.board.squares[move.start.y][move.start.x];
            } while (!is_legal_move(&game.board, &piece, &move) || piece.color != player2.color);
            move_piece(&game.board, &move);
            insert_board(&game.log, &game.board);
        }
        /*
        if (is_checkmate(&game, &player1)) {
            printf("Player1 Win!");
            break;
        }
        else if (is_stalemate(&game, &player1)) {
            printf("Stalemate!");
            break;
        }
        */
        switch_players(&game);

    }
}
