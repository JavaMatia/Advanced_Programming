/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#define SIZE 14
#define A 'A'
#define Z 'Z'
#define a 'a'
#define z 'z'
int main(void)
{
	int i = 0;
	int lowerStringIndex = 0;
	int capitalStringIndex = 0;
	char string[SIZE] = { 0 };
	char capitalString[SIZE/2] = { 0 };
	char lowerString[SIZE / 2] = { 0 };
	printf("Enter a string with upper and lower case letter: \n");
	fgets(string, SIZE, stdin);
	for (i = 0; i < SIZE; i++) //removes enter
	{
		if (string[i] == '\n')
		{
			string[i] = 0;
		}
	}
	for (i = 0; string[i]; i++)
	{
		if (string[i] <= Z && string[i] >= A)
		{
			capitalString[capitalStringIndex] = string[i];
			capitalStringIndex++;
		}
		else if (string[i] <= z && string[i] >= a)
		{
			lowerString[lowerStringIndex] = string[i];
			lowerStringIndex++;
		}
	}
	printf("Ther lower and upper case words: \n%s\n%s", capitalString, lowerString);

	getchar();
	return 0;
}