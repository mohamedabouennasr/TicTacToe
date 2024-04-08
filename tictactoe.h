#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

typedef struct {
    int x;
    int y;
} point;

void displayTable(char** table);
void inputPlayerAction(int playerNumber, char** table);
int winner(char** table);

#endif // TICTACTOE_H_INCLUDED
