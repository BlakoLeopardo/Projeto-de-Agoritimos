#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYA = 'X';
const char CPU = 'O';

void resetBoard();
void printBoard();
void playerMove();
void computerMove();
void printWinner(char);

char checkWinner();

int checkFreSpaces();

int main()
{
while (winner == ' ' && checkFreSpaces() != 0)
{
    printBoard();
    playerMove();
    
    winner = checkWinner();
    
    if (winner != ' ' || checkFreSpaces() == 0)
    {
        break;
    }
    
    computerMove();
    winner = checkWinner();
    if (winner != ' ' || checkFreSpaces() == 0)
    {
        break;
    }
    
}
    resetBoard();

return 0;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);

    printf("\n");

}
void playerMove()
{
int x;
int y;

do
{
    printf("Entre um numero de linha de (1-3):");
    scanf("%d", &x);
    x--;
    printf("Entre um numero de coluna de (1-3):");
    scanf("%d", &y );
    y--;

    if (board[x][y] != ' ')
    {
        printf("Movimento invalido!\n");
    }
    else
    {
        board[x][y] = PLAYA;
        break;
    }

} while (board[x][y] != ' ');

    
}
void computerMove()
{

}
void printWinner(char winner)
{

}

char checkWinner()
{
    // checar linhas
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    // checar colunas
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // checar diagonais
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) // perguntar pro veio se pode else if
    {
        return board[0][2];
    }

    return ' ';
}

int checkFreSpaces()
{
int freeSpaces = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
            
        }
        
    }
return freeSpaces;
}