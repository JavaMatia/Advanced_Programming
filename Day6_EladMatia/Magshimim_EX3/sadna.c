#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_LEN 20
#define BOARD_LEN 5
#define HIT 'X'
#define MAX_RANDOM 75

typedef struct bingoPlayer {
	char name[NAME_LEN];
	char board[BOARD_LEN][BOARD_LEN];
} bingoPlayer;


typedef struct bingoGame {
	int numsDrawn[BOARD_LEN * BOARD_LEN];
	int numOfNumsDrawn;
	bingoPlayer* players;
	int numPlayers;

} bingoGame;

void initGame(bingoGame* game);
void initBingoPlayer(bingoPlayer* player);
void updateGame(bingoGame* bg);
void updatePlayer(bingoPlayer* player, int num);
void printBoard(bingoPlayer player);
void printBoards(bingoGame game);
int hasWon(bingoPlayer player);
void myFgets(char* p, int size);
int in(int number, char board[][BOARD_LEN], int size);


/* This function updates the player details
It
and checks if this number is in the player board, if it is, it switches the place in the board to 'X'
Input: bingoPlayer struct pointer and number randomized
Output: None
*/
void updatePlayer(bingoPlayer* player, int num)
{
	int i = 0, j = 0;

	for (i = 0; i < BOARD_LEN; i++)
	{
		for (j = 0; j < BOARD_LEN; j++)
		{
			if ((int)player->board[i][j] == num)
			{
				player->board[i][j] = HIT;
			}
		}
	}
}

/* This function prints a player board
Input: bingoPlayer
Output: None
*/
void printBoard(bingoPlayer player)
{
	int i = 0, j = 0;

	for (i = 0; i < BOARD_LEN; i++)
	{
		for (j = 0; j < BOARD_LEN; j++)
		{
			if (player.board[i][j] == HIT)
			{
				printf(" X  ");
			}
			else
			{
				printf(" %2d ", (int)player.board[i][j]);
			}
		}
		printf("\n\n");
	}
}

/*
This function prints all players' boards
Input: bingoPlayer
Output: None
*/
void printBoards(bingoGame game)
{
	int i = 0;
	for (i = 0; i < game.numPlayers; i++)
	{
		printf("%s's board:\n", game.players[i].name);
		printBoard(game.players[i]);
	}
}
/*
Creates and fill the board with players and numbers
Input: a bingo player
Output: None
*/
void initBingoPlayer(bingoPlayer* player)
{
	int i = 0, j = 0, num = 0;
	printf("What is your name?\n");
	myFgets(player->name, NAME_LEN);
	srand(time(NULL));


	for (i = 0; i < BOARD_LEN; i++)
	{
		for (j = 0; j < BOARD_LEN; j++)
		{
			player->board[i][j] = 0;
			while (in(num, player->board, BOARD_LEN))
			{
				num = (rand() % MAX_RANDOM) + 1;
			}
			player->board[i][j] = num;
		}
	}
}
/*
gets a string
*/
void myFgets(char* p, int size)
{
	fgets(p, size, stdin);
	p[strcspn(p, "\n")] = 0;
}
/*
This function checks to see if a specific number is in an array
Input: array, its size and a number to check
Output: 1 if the number was found, false otherwise
*/
int in(int number, char board[][BOARD_LEN], int size)
{
	int i = 0, j = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (board[i][j] == number)
			{
				return 1;
			}
		}
	}
	return 0;
}
/*
This function initiate the game struct.
Input: the game struct
Output: none
*/
void initGame(bingoGame* game)
{
	int i = 0;

	for (i = 0; i < BOARD_LEN*BOARD_LEN; i++)
	{
		game->numsDrawn[i] = 0;
	}
	game->numOfNumsDrawn = 0;

	printf("How many players are playing?\n");
	scanf("%d", &(game->numPlayers));
	getchar();

	game->players = (bingoPlayer*)malloc(sizeof(bingoPlayer) * game->numPlayers);
	for (i = 0; i < game->numPlayers; i++)
	{
		initBingoPlayer(&(game->players[i]));
	}
}
/*
The function checks to see if a player has won
Input: a bingo player struct
Output: 1 if the player won, 0 if he didnot
*/
int hasWon(bingoPlayer player)
{
	int i = 0;
	int j = 0;
	int won = 0;

	for (i = 0; i < BOARD_LEN; i++)
	{
		won = 1;
		for (j = 0; j < BOARD_LEN && won; j++)
		{
			if (player.board[i][j] != HIT)
			{
				won = 0;
			}
		}
		if (won)
		{
			return won;
		}
	}

	return won;
}
/*
The function randomize a number and updates the neccessery information
Input: a game structure
Output: None
*/
void updateGame(bingoGame* bg)
{
	int num = (rand() % MAX_RANDOM) + 1;
	while (in(num, bg->numsDrawn, bg->numOfNumsDrawn))
	{
		num = (rand() % MAX_RANDOM) + 1;
	}
	bg->numsDrawn[bg->numOfNumsDrawn] = num;
	bg->numOfNumsDrawn++;
}
int main(void)
{
	bingoGame game;
	initGame(&game);
	printBoards(game);
	printf("Press enter to continue...");
	getchar();
	int i = 0;
	int won = 0;
	int winIndex = -1;
	while (!won) //while no one won
	{
		updateGame(&game);
		printf("\n\n------------------------\n\n");
		for (i = 0; i < game.numPlayers && !won; i++)
		{
			updatePlayer(&game.players[i], game.numsDrawn[game.numOfNumsDrawn-1]);
			if (hasWon(game.players[i])) //check if someone won
			{
				won = 1;
				winIndex = i;
			}
		}
		printf("\nBoards: \n\n");
		printBoards(game);
		printf("Press enter to continue...");
		getchar();

	}
	printf("<<<<<<%s has won!>>>>>>>>", game.players[winIndex].name);

	free(game.players);

	getchar();
	return 0;
}