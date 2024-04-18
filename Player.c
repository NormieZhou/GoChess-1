#include "player.h"
#include <stdlib.h>

// Function to create a player
Player* create_player(PlayerColor color, int isComputer) {
    // Allocate memory for the player structure
    Player* player = (Player*)malloc(sizeof(Player));
    if (player == NULL) {
        // Memory allocation failed
        return NULL;
    }

    // Initialize player color and isComputer flag
    player->color = color;
    player->isComputer = isComputer;

    return player;
}
