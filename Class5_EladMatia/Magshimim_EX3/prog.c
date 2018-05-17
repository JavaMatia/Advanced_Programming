/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE !FALSE
#define OK 4
#define SUB "SUB"
#define ADD "ADD"

int checkParameters(int argc, char** argv);
void add(int argc, char** argv);
void sub(int argc, char** argv);

int main(int argc, char** argv)
{

	//Write your code here...
	if (checkParameters(argc, argv))
	{
		//execute program!
		if (!(strcmp(*(argv + 1), ADD)))
		{
			add(argc, argv);
		}
		else
		{
			sub(argc, argv);
		}
	}
	getchar();
	return 0;
}
/*
The function checks for valid parameter input
Input: the number of arguments from main and the parameters
Output: a message and a false if the input isn't correct, true if everything is ok
*/
int checkParameters(int argc, char** argv)
{
	if (argc < OK) 
	{
		printf("ERROR! INVALID NUMBER OF ARGUMENTS!\nHow to use the program: <ADD / SUB> <number> ... <number>");
		return FALSE;
		
	}
	if ((strcmp(*(argv + 1), ADD)) && (strcmp(*(argv + 1), SUB)))
	{
		printf("ERROR! INVALID COMMAND!\nHow to use the program: <ADD / SUB> <number> ... <number>");
		return FALSE;
	}
	return TRUE;
}
/*
The function adds all the numbers the user entered after the word add
Input: the number of main parameters and the main parameters
Output: None
*/
void add(int argc, char** argv)
{
	int i = 0, sum = 0;
	for (i = 2; i < argc; i++) // start from 2. 0 and 1 are the name of the program and the word ADD
	{
		sum += atoi(*(argv + i)); // convert to int
	}
	printf("Result: %d", sum);
}
/*
The function decrements all the numbers the user entered after the word sub
Input: the number of main parameters and the main parameters
Output: None
*/
void sub(int argc, char** argv)
{
	int i = 0, sum = atoi(*(argv + 2));
	for (i = 3; i < argc; i++) // start from 2. 0 and 1 are the name of the program and the word sub. sum should start from the first number the user entered
	{
		sum -= atoi(*(argv + i)); // convert to int
	}
	printf("Result: %d", sum);
}