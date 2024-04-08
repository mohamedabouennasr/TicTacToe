#include "tictactoe.h"
#include <stdio.h>

void displayTable(char** table) {
    printf("\t \t|\t \t|\t \t\n\t%c\t|\t%c\t|\t%c\t\n\t \t|\t \t|\t \t\n----------------+---------------+----------------\n\t \t|\t \t|\t \t\n\t%c\t|\t%c\t|\t%c\t\n\t \t|\t \t|\t \t\n----------------+---------------+----------------\n\t \t|\t \t|\t \t\n\t%c\t|\t%c\t|\t%c\t\n\t \t|\t \t|\t \t\n", **table, *(*table + 1), *(*table + 2), **(table + 1), *(*(table + 1) + 1), *(*(table + 1) + 2), **(table + 2), *(*(table + 2) + 1), *(*(table + 2) + 2));
}

void inputPlayerAction(int playerNumber, char** table) {
    point player;
    printf("Player %d:\n", playerNumber);
    do {
        do {
            printf("-----> x = ");
            scanf("%d", &(player.x));
        } while (player.x < 1 || player.x > 3);
        do {
            printf("-----> y = ");
            scanf("%d", &(player.y));
        } while (player.y < 1 || player.y > 3);
    } while (*(*(table + player.x - 1) + player.y - 1) != ' ');
    if (playerNumber == 1) *(*(table + player.x - 1) + player.y - 1) = 'X';
    else *(*(table + player.x - 1) + player.y - 1) = 'O';
}

int countBlank(char** table) {
    int count = 0;
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (*(*(table + i) + j) == ' ') count++;
    return count;
}

int winner(char** table) {
    // Blank Elements Check
    if (countBlank(table) == 0) return 0;
    // Diagonal Check
    else if (*(*(table + 0) + 0) == 'X' && *(*(table + 1) + 1) == 'X' && *(*(table + 2) + 2) == 'X') return 1;
    else if (*(*(table + 0) + 0) == 'O' && *(*(table + 1) + 1) == 'O' && *(*(table + 2) + 2) == 'O') return 2;
    else if (*(*(table + 0) + 2) == 'X' && *(*(table + 1) + 1) == 'X' && *(*(table + 2) + 0) == 'X') return 1;
    else if (*(*(table + 0) + 2) == 'O' && *(*(table + 1) + 1) == 'O' && *(*(table + 2) + 0) == 'O') return 2;
    // Line Check

    // Column Check


}
