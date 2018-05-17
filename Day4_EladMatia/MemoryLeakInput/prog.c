/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>


int main(void)
{

	//Write your code here...
	int num = 0;
	printf("Enter a number: \n");
	scanf("%d", &num);
	int* px = (int*)malloc(sizeof(int)*num); // allocate memory
	getchar();
	return 0;
}