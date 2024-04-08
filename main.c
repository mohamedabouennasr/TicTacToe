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
        displayTable(table);
        while (winner(table) != 0 && winner(table) != 1 && winner(table) != 2) {
            inputPlayerAction(1, table);
            system("cls");
            displayTable(table);
            inputPlayerAction(2, table);
            system("cls");
            displayTable(table);
        }
        printf("Winner = %d\n", winner(table));
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
    if (reset == 1) main();
    return 0;
}
