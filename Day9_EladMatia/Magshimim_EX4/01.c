/*********************************
* Class: MAGSHIMIM C2			 *
* Week 9 - Recursion			 *
* Class Example	 			 	 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

int recursiveFibonacci(int n);
int counter = 0; //global counter for the number of times the function has to be called
int main(void)
{
	int a = 0;
	int res = 0;
	printf("Enter number: ");
	scanf("%d", &a);
	res = recursiveFibonacci(a);
	printf("%d in the Fibonacci series is %d\n", a, res);
	printf("number of called for %d is: %d", a, counter);
	getchar();
	return 0;
}

/*
Function calculates the nth fibonacci number (f(0) = 0, f(1) = 1, f(n) = f(n-1) + f(n-2))
input: n (number in fibonacci series to calculate
output: the nth fibonacci number
*/
int recursiveFibonacci(int n)
{
	int answer = 0;
	counter++;
	if (n == 0)
	{
		answer = 0;
	}
	else if (n == 1)
	{
		answer = 1;
	}
	else
	{
		answer = recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
	}

	return answer;
}