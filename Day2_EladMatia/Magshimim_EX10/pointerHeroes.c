/*********************************
* Class: MAGSHIMIM C2			 *
* Week 2           				 *
* HW solution 			 		 *
**********************************/

#include <stdio.h>

void add(int* x, int* y, int* sum);

int main(void)
{
	int a = 0, b = 0, sum = 0;
	int *c = &b; //To initialize a pointer you need to us &
	printf("Enter two numbers: ");
	scanf("%d %d", &a, c); //you already have a pointer for b: c
	getchar();
	add(&a, c, &sum); //c is a pointer, you don't need to add & before it
	printf("The sum of a and b is: %d", sum);
	getchar();
	return 0;
}


void add(int* x, int* y, int* sum) 
{ 
	*sum = *x + *y; // You can't add two memory addresses, you need to access the value with * 
}

//BONUS:
/*
A. You can use breakpoints and debug when needed
B. Remember: & means the address of, * meam the value of.
C. If you have a pointer, you don't need to use & on a pointer, because it would point to the pointer.
*/