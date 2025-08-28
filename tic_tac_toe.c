#include <stdio.h>

char board[3][3];

void initializeBoard();
void displayBoard();
int checkWin(char symbol);
int isBoardFull();

int main(void)
{
    char player = 'x';
    int choice;
    int row, column;
    initializeBoard();

    while(1 > 0)
    {
        displayBoard();
        printf("\n");
        printf("Player %c choose a number between 1 - 9: ", player);
        scanf("%d", &choice);

        row = (choice - 1) / 3;
        column = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][column] == 'x' ||  board [row][column] == 'o')
        {
            printf("\n");
            printf("Invalid choice. Try again\n");
            continue;
        }

        board[row][column] = player;

        if(checkWin(player))
        {
            displayBoard();
            printf("\n");
            printf("Player %c is the winner\n", player);
            break;
        }

        if (isBoardFull())
        {
            displayBoard();
            printf("Game is a draw\n");
            break;
        }
            player = (player == 'x') ? 'o' : 'x';
    }
    return 0;
}

void initializeBoard()
{
    char count = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = count++;
         }
    }
}

void displayBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2)
        {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

int checkWin(char symbol)
{
    //row
    if ((board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) || (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol) || (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol))
    {
        return 1;
    }

    //column
    if ((board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) || (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol) || (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol))
    {
        return 1;
    }

    //diagonal
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) || (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
    {   
        return 1;
    }
    return 0;
}

int isBoardFull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'x' && board[i][j] != 'o')
            {
                return 0;
            }
        }
    }
    return 1;
}

// initialize board
// display board
// check win
// is board full 
// main