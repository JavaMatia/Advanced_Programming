/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
int recursiveFactorial(int n);
int main(void)
{

	//Write your code here...
	int num = 0;
	printf("Enter number: ");
	scanf("%d", &num);
	getchar();
	printf("num! == %d", recursiveFactorial(num));
	getchar();
	return 0;
}
/*
The function prints the factorial of n
Input: the number to calculate its factorial
Output: the factorial of n
*/
int recursiveFactorial(int n)
{
	if (n >= 1)
	{
		return n * recursiveFactorial(n - 1);
	}
	
	return 1;
}