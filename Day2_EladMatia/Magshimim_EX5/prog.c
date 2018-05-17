/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
void inc(int* x);
int main(void)
{
	int number = 0;
	int* pNumber = &number;
	printf("Enter a number: \n");
	scanf("%d", pNumber);
	inc(pNumber);
	printf("Now it's %d", number);

	getchar();
	getchar();
	return 0;
}
/*
This function increment the value in the given pointer
Input: a pointer to a int value	
Output: None
*/
void inc(int* x)
{
	(*x)++;
}