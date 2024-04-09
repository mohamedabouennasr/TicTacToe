#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"

int main() {
    // Create Table Matrix
    char** table = (char**) malloc(3 * sizeof(char*));
    if (table == NULL) {
        printf("Allocation Failed..!\n");
        exit(1);
    }
    else {
        for (int i = 0; i < 3; i++) {
            *(table + i) = (char*) malloc(3 * sizeof(char));
            if (*(table + i) == NULL) {
                printf("Allocation Failed..!\n");
                exit(1);
            }
            else for (int j = 0; j < 3; j++) *(*(table + i) + j) = ' ';
        }
        // TicTacToe Game
        printf("C TicTacToe Game!\n");
        while (winner(table) != 0) {
            inputPlayerAction(1, table);
            system("cls");
            displayTable(table);
            if (winner(table) == 1) break;
            inputPlayerAction(2, table);
            system("cls");
            displayTable(table);
            if (winner(table) == 1) break;
        }
        if (winner(table) == 1) printf("Player 1 Wins!\n");
        else if (winner(table) == 2) printf("Player 2 Wins!\n");
        else printf("Tie!\n");
        // Free Table Matrix
        for (int i = 0; i < 3; i++) {
            free(*(table + i));
            *(table + i) = NULL;
        }
        free(table);
        table = NULL;
    }
    // Reset
    int reset;
    do {
        printf("Reset: ");
        scanf("%d", &reset);
    } while (reset != 0 && reset != 1);
    if (reset == 1) {
        system("cls");
        main();
    }
    return 0;
}
