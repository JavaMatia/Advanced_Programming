/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/
#include <stdio.h>

void swap(int* x, int* y);
int main(void)
{

	//Write your code here...
	float x = 0, y = 0;
	printf("Enter two numbers: \n");
	scanf("%f %f" , &x, &y);
	getchar();
	swap(&x, &y);
	printf("Swapped: %.2f %.2f", x, y);
	getchar();
	return 0;
}
/*
The function takes two pointers and replace their values.
Input: two float pointers
Output: None
*/
void swap(float* x, float* y)
{
	float temp = *x;
	*x = *y;
	*y = temp;
}