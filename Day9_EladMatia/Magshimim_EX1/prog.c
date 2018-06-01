/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
void recursivePrintA(int n);

int main(void)
{
	int num = 0;
	printf("Enter number: ");
	scanf("%d", &num);
	getchar();
	recursivePrintA(num);
	getchar();
	return 0;
}
/*
The function prints A n times
Input: n (int), the number of times to print A
Output: None
*/
void recursivePrintA(int n)
{
	if (n != 0)
	{
		recursivePrintA(n - 1);
		printf("A ");
	}
}