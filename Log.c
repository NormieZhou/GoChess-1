#include "Log.h"

void init_board_list(struct BoardList* list) {
    list->head = NULL;
    list->tail = NULL;
}

void insert_board(struct BoardList* list, struct Board* board) {
    // Create a new BoardNode
    struct BoardNode* newNode = (struct BoardNode*)malloc(sizeof(struct BoardNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Assign the board to the new node
    newNode->board = *board;
    newNode->next = NULL;

    // If the list is empty, set the new node as both head and tail
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    }
    else {
        // Otherwise, append the new node to the end of the list
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void undo_move(struct BoardList* list) {
    if (list->head == NULL) {
        fprintf(stderr, "Error: Attempting to delete from an empty list\n");
        return;
    }

    // Delete the last node
    struct BoardNode* current = list->head;
    struct BoardNode* prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        // Only one node in the list
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        // More than one node in the list
        prev->next = NULL;
        free(current);
        list->tail = prev;
    }
}


