#ifndef PLAYER_H
#define PLAYER_H

// Enumeration for player color
typedef enum {
    WHITE,
    BLACK
} PlayerColor;

// Structure definition for Player
typedef struct {
    // Player color
    PlayerColor color;
    // Flag to indicate whether the player is a computer
    int isComputer;
} Player;

// Function to create a player
Player* create_player(PlayerColor color, int isComputer);

#endif /* PLAYER_H */
