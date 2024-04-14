#include <stdio.h>
#include <stdlib.h>
#include "AI.h"
#include "Board.h"
#include "CheckMove.h"
#include "EndGame.h"
#include "Log.h"

int main(void) {
    //initializations
    struct Board board;
    init_board(&board);
    
    struct Player white_player = {'W', false};
    struct Player black_player = {'B', false};
    
    struct Game game = {board, &white_player, NULL};

    //game loop
    while (!is_game_over(&game)) {
        // game logic
    }
    
    return 0;
}
