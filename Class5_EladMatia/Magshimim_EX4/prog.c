/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

void removeEnter(char* array, int size);
void sort(char** strings, int size);

int main(void) //numOfFriends * 50 - this is the amount of memory I allocated. I also used another 50 bytes for a temporary value. also reallocared less memory where i could
{

	//Write your code here...
	int numOfFriends = 0, i = 0, newSize = 0;
	printf("Enter number of friends: ");
	scanf("%d", &numOfFriends);
	getchar();
	char** friends = (char**)malloc(sizeof(char*)*numOfFriends);
	for (i = 0; i < numOfFriends; i++)
	{
		friends[i] = (char*)malloc(sizeof(char)*SIZE); // we have a row with one element. make the colums bigger (by 50), so we will be able to input something
		printf("Enter name of friends %d: ", i+1);
		fgets(friends[i], SIZE, stdin);
		removeEnter(friends[i], strlen(friends[i]));
		newSize = strlen(*(friends + i)); // temporary value
		friends[i] = (char*)realloc(friends[i], sizeof(char)*newSize+1); // reallocate space
		friends[i][newSize] = 0; // 0 to make it a string 
	}
	sort(friends, numOfFriends);
	if (friends != NULL)
	{
		free(friends);
	}// free array of pointers
	getchar();
	return 0;
}
/*
The function removes the enter from the string
Input: string and its size
Output: None
*/
void removeEnter(char* array, int size)
{
	int i = 0;
	for(i=0; i<size; i++)
	{
		if (*(array + i) == 10)
		{
			*(array + i) = 0;
		}
	}
}
/*
The function sorts the strings alphabaticly
input: array of strings and its size
output: none
*/
void sort(char** strings, int size)
{
	int i = 0, j = 0;
	char tempArray[SIZE] = { 0 };
	char* temp = &tempArray;
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (strcmp(strings[i], strings[j]) > 0)
			{
				temp = strings[i];
				strings[i] = strings[j];
				strings[j] = temp;

			}
		}
		
	}
	for (i = 0; i < size; i++)
	{
		printf("Friends %d: %s\n", i+1, strings[i]);
		free(strings[i]); //now you can free each strings in the memory, we still have to free the array of pointers in main
	}
}