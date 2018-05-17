/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>

#define SIZE 15
int main(void)
{
	int i = 0;
	char name[SIZE] = {0};
	int stop = 0;
	printf("What is your name? \n");
	fgets(name, SIZE, stdin);
	for (i = 0; i < SIZE && !stop; i++) //removes enter
	{
		if (name[i] == '\n')
		{
			name[i] = 0;
			stop = 1;
		}
	}
	printf("Hello %s, and welcome to Visual Studio!", name);
	getchar();
	return 0;
}