/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 9999
int main(void)
{
	int i = 0;
	int* intArr;
	char* string = (char*)malloc(sizeof(char)*LEN); // i dont know the size of the string, allocate a lot of space
	printf("Please enter a string: ");
	fgets(string, LEN, stdin);
	for (i = 0; string[i]; i++) // removes enters
	{
		if (string[i] == '\n')
		{
			string[i] = 0;
		}
	}
	printf("The length of the string is: %d\n", strlen(string));
	if (strlen(string) != 0)
	{
		intArr = (int*)malloc((strlen(string)) * sizeof(int));
	}
	else
	{
		intArr = (int*)malloc(0);
	}
	printf("%d bytes were allocated!", (strlen(string))*sizeof(int));
	free(string); // free all memory
	free(intArr);
	getchar();
	return 0;
}