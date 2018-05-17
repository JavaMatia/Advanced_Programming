/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#define SIZE 9

//initialize the function
int findFirstNonZero(int a[], int n);
int main(void)
{

	//Write your code here...
	int arrayNumers[SIZE] = { 0, 0, 0, 2, 1, 4, 6, 1, 0 }; // we should expect 3 to return from the function
	printf("firstNonZero: %d", findFirstNonZero(arrayNumers, SIZE));
	getchar();
	return 0;
}
/*
The function returns the index of the first elemnt in the array which is not 0
Input: array, size
Output: the index of the first element which is not 0
*/
int findFirstNonZero(int a[], int n)
{
	int i = 0, flag = 1, index = 0;
	for (i = 0; i < n && flag; i++)
	{
		if (a[i] != 0) // if tt's not 0 we found our number and we can exit the loop
		{
			index = i;
			flag = 0;
		}
	}
	if (a[index] == 0) // in case index hasn't changed and it's still a zero, print to the user
	{
		printf("No such thing");
	}
	else
	{
		return index;
	}
	return -1; //to avoid a warning can never get here 
}