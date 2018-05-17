/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#define SIZE 10

//Initialize the functions
void arrayInput(int* arr, int size);
void arrayRevereOutput(int* arr, int size);
int main(void)
{

	//Write your code here...
	int array[SIZE] = { 0 }; //array
	// call the functions
	arrayInput(array, SIZE);
	arrayRevereOutput(array, SIZE);

	getchar();
	return 0;
}
/*
The function puts 10 int values into a given array
Input: array(pointer), and its size
Output: None
*/
void arrayInput(int* arr, int size)
{
	//variables:
	int i = 0;
	printf("Enter 10 numbers: ");
	for (i = 0; i < size; i++)
	{
		scanf("%d", (arr + i)); // gets the input. no need to return we change the memory
	}
	// cleans the buffer and print a new line
	printf("\n");
	getchar();
}
/*
The function prints array of number backwards
Input: Array of numbers as pointer and its size
Output: Print the reversed array
*/
void arrayRevereOutput(int* arr, int size)
{
	int i = 0;
	printf("The numbers in reverse order: ");
	for (i = size - 1; i >= 0; i--)
	{
		printf("%d ", *(arr + i)); // run the for loop backwards and print each value
	}
}