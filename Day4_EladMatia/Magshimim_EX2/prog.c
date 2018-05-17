/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>

void sortArray(int* arr, int length);

int main(void)
{
	int length = 0, i = 0;
	//Write your code here...
	printf("Enter length of array: \n");
	scanf("%d", &length);
	getchar();
	int* numberArr = (int*)malloc(sizeof(int)*length); //allocate memory for the array!
	printf("Enter %d numbers: \n", length);
	//get input
	for (i = 0; i < length; i++)
	{
		scanf("%d", &numberArr[i]);
		getchar();
	}
	//sort:
	sortArray(numberArr, length);
	//print array:
	printf("Sorted: ");
	for (i = 0; i < length; i++)
	{
		printf("\n%d", numberArr[i]);
	}
	free(numberArr); // free the heap memory
	getchar();
	return 0;
}
/*
The function sorts a given array
Input: Array as a pointer to its first element and its length
Output: None
*/
void sortArray(int* arr, int length)
{
	
	int i = 0, j = 0, a = 0;
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (arr[i] > arr[j])		// we need to replace the values if this happens
			{													
				a = arr[i];
				arr[i] = arr[j];
				arr[j] = a;
			}
		}
	}
}