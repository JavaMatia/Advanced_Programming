/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#define SIZE 5
int* createArray();
void printArray(int* arr, int n);
int main(void)
{

	//Write your code here...
	int* firstArrayElement = createArray();
	printf("%p", firstArrayElement);
	printArray(firstArrayElement, SIZE);
	getchar();

	/*
	*We create an array in a FUNCTION, then return it. We know that function memory lasts only the time the function is active, once it is done, all the "memory cells" 
	*fill with junk, so when we try to run through the array in another function, we get junk values, because this place in the memory was already declared as "free"
	*because be exited the previous function
	*/
	return 0;
}
/*
The function adds five numbers to array and retruns the first element address
Input: None
Output: the first element address of the array
*/
int* createArray()
{
	int arr[SIZE] = {0};// create array (have to use [] to allocate space)
	int i = 0;
	for (i = 0; i < 5; i++)
	{//array input
		printf("Enter a number: \n");
		scanf("%d",(arr+i));
		getchar();
	}

	return arr; //return the first array element's location
}
/*
Print the array
Input: array, its size
Output: print the array
*/
void printArray(int* arr, int n)

{
	//print the array
	int* i = arr;
	for (i; i < arr + n; i++)
	{
		printf("%d, ", *i);
	}
}