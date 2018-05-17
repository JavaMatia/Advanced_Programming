/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
void change(float* num1, float* num2, float* num3);
void swap(float* x, float* y);
int main(void)
{
	float num1 = 0, num2 = 0, num3 = 0;
	float* pNum1 = &num1;
	float* pNum2 = &num2;
	float* pNum3 = &num3;

	printf("Please enter num1, num2, num3: \n");
	scanf("%f %f %f", pNum1, pNum2, pNum3);
	getchar();
	change(pNum1, pNum2, pNum3);
	printf("After sorting: num1 = %.2f num2 = %.2f num3 = %.2f", num1, num2, num3);
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
/*
The function puts the lowest value in num1 the highest in num3 and the middle number in num2
INput: Three pointers
Output: None
*/
void change(float* num1, float* num2, float* num3)
{
	if (*num1 > *num2)
	{
		swap(num1, num2);
	}
	if (*num2 > *num3)
	{
		swap(num2, num3);
	}
	if (*num1 > *num3)
	{
		swap(num1, num3);
	}

}