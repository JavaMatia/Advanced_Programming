/*********************************
* Class: MAGSHIMIM C2			 *
* Week 1           				 *
**********************************/

#include<stdio.h>
#include<string.h>

#define X_CHAR 'x'
#define O_CHAR 'o'
#define BLANK ' '
#define FALSE 0
#define TRUE !FALSE
#define BOARD_SIZE 3
#define DONE 9


void printBoard(char board[][BOARD_SIZE]);
int playerWon(char board[][BOARD_SIZE]);
void updateBoard(char board[][BOARD_SIZE]);
int playerWon(char board[][BOARD_SIZE]);
int winRow(char board[][BOARD_SIZE], int row);
int winCol(char board[][BOARD_SIZE], int col);
int mainSlant(char board[][BOARD_SIZE]);
int secondSlant(char board[][BOARD_SIZE]);

char currentTurn = X_CHAR;
char temp = X_CHAR;
char otherTurn = O_CHAR;
int turns = 0;

int main(void)
{

	char xoBoard[BOARD_SIZE][BOARD_SIZE] = {{BLANK ,BLANK ,BLANK },
											{BLANK ,BLANK,BLANK },
											{ BLANK ,BLANK ,BLANK }};
	int inGame = TRUE;
	while (inGame)
	{
		updateBoard(xoBoard);
		printBoard(xoBoard);
		if (playerWon(xoBoard) || turns == DONE)
		{
			inGame = FALSE;
		}
	}

	if (playerWon(xoBoard))
	{
		printf("%c is the winner!\n", otherTurn);
	}
	else if (turns == DONE)
	{
		printf("Tie!");
	}
	
	getchar();
	getchar();
	return 0;
}

/**
Function will print the board.
input: the board to print
*/
void printBoard(char board[][BOARD_SIZE])
{
	int i = 0, j = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			printf("%3c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
/*
The function update the board with the currnet_player global variable
Input: Board to update
*/
void updateBoard(char board[][BOARD_SIZE])
{
	int row = 0; 
	int col = 0;
	printf("It is %c's turn.\n" , currentTurn);
	printf("Enter location on board: \n");
	scanf("%d %d", &row, &col);
	while (board[row][col] != BLANK)
	{
		printf("Location taken! Try again\n");
		printf("Enter location on board: \n");
		scanf("%d %d", &row, &col);
	}
	board[row][col] = currentTurn;
	// switch player
	temp = otherTurn;
	otherTurn = currentTurn;
	currentTurn = temp;
	turns++;

}
/*
The function checks if there is a win 
Input: Board 
Output: true if there is a win, false otherwisew

*/
int playerWon(char board[][BOARD_SIZE])
{
	if ((winRow(board, 0) || winRow(board, 1) || winRow(board, 2)) || ((winCol(board, 0) || winCol(board, 1) || winCol(board, 2))) || mainSlant(board) || secondSlant(board))
	{

		return TRUE;
	}
	return FALSE;
}
/*
The function checks if there is a win in the specified row
Input: Board and a certain row the check
Output: true if there is a match, false otherwise

*/
int winRow(char board[][BOARD_SIZE], int row)
{
	int i = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		if (board[row][i] != otherTurn)
		{
			return FALSE;
		}
	}
	return TRUE;
}
/*
The function checks if there is a win in the specified collumn
Input: Board and a certain collumn the check
Output: true if there is a match, false otherwise

*/
int winCol(char board[][BOARD_SIZE], int col)
{
	int i = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		if (board[i][col] != otherTurn)
		{
			return FALSE;
		}
	}
	return TRUE;
}
/*
The function checks if there is a win in the main slant
Input: Board
Output: true if there is a match, false otherwise

*/
int mainSlant(char board[][BOARD_SIZE])
{
	int i = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		if (board[i][i] != otherTurn)
		{
			return FALSE;
		}
	}
	return TRUE;
}
/*
The function checks if there is a win in the second slant
Input: Board
Output: true if there is a match, false otherwise

*/
int secondSlant(char board[][BOARD_SIZE])
{
	int i = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		if (board[i][BOARD_SIZE - i - 1] != otherTurn)
		{
			return FALSE;
		}
	}
	return TRUE;
}
