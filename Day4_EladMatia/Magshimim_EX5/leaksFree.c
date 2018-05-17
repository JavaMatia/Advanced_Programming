/*********************************
* Class: MAGSHIMIM C2			 *
* Week 4           				 *
* HW solution   			 	 *
**********************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int* createArr(int len);
//  HE HADN'T HAD A MEMORY LEAK
int main(void)
{
	int size = 0;
	int* pArr = 0;

	printf("Enter a number of cells: ");
	scanf("%d", &size); // size should be a pointer or use &
    pArr = createArr(size);
    printf("The array is at address %p: ", pArr);
    free(pArr);
    
	getchar();
	return 0;
}

/*
Function creates an array
input: number of cells in the array
output: pointer to the new array
*/
int* createArr(int size)
{
	int* pArr = (int*)malloc(size*sizeof(int)); //forgot to specify it is an int array
	int i = 0;
	for(i = 0; i < size; i++)
	{
		printf("Please enter a number for index %d: ",i);
		scanf("%d", &pArr[i]); //he for some reason entered the number into the size variable
		getchar(); //to remove all enteres
	}
    //free(i); // he freed i, but you can't free a stack variable. also, if he had removed it here, the pointer wouldn't ever returned
	return pArr;
}
