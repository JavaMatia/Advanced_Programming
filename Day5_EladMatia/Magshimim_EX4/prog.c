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
int main(void)
{

	//Write your code here...
	int numOfFriends = 0, i = 0, newSize = 0;
	printf("Enter number of friends: ");
	scanf("%d", &numOfFriends);
	getchar();
	char** friends = (char**)malloc(sizeof(char)*numOfFriends);
	for (i = 0; i < numOfFriends; i++)
	{
		printf("Enter name of friends %d: ", i+1);
		fgets(*(friends+i), SIZE, stdin);
		*(friends + i) = *(friends + i)[strlen(*(friends + i)) - 1] = 0; // remove enter
		newSize = strlen(*(friends + i)); // temporary value
		*(friends + i) = realloc(*(friends + i), newSize); // reallocate space
		printf("%s", *(friends + i));
	}

	getchar();
	return 0;
}