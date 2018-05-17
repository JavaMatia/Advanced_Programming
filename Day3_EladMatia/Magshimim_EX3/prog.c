/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#define SIZE 11
void printAfterX(int* arr, int n, int* x);
int main(void)
{

	//Write your code here...
	//Variables
	int arr[SIZE] = {4, 8, 6, 2, 1, 3, 5, 7, 8, 9, 5};
	int offset = 0;

	printf("Please enter an offset to search in the array's address domain: \n");
	scanf("%d", &offset); // the offset from the beginning of the array
	getchar(); // clean the buffer
	printAfterX(arr, SIZE, arr+offset); //calls the function
	getchar();
	return 0;
}
/*
The function prints the elements of an array after x, print an apropriate message if cannot do so
Input: Array, its size, and the pointer in the the array
Output: prints all numbers in the array after the given pointer
*/
void printAfterX(int* arr, int n, int* x)
{
	if (!(x >= arr + n)) // if we are NOT exiting the array size, 
	{
		for (x; x < (arr + n)-1; x++) // run on the array plus size minus 1 (we want to get the numbers AFTER x), but we don't want buffer overfow
		{
			printf("%d ", *(x+1)); //print it
		}
		
	}
	else
	{
		printf("Not in the array"); //in case x is not in the array, print it.
	}
	
}