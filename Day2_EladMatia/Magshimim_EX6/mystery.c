/*********************************
* Class: MAGSHIMIM C2			 *
* Week 2           				 *
* HW solution   			 	 *
**********************************/
#include <stdio.h>
#include <time.h>

#define RANGE 10

void mystery(int*,int*);

int main(void)
{
	int a = 0, b = 0;
	srand(time(NULL)); // seed for rand
	a = (rand() % RANGE) + 1;
	b = (rand() % RANGE) + 1;
	
	mystery(&a, &b);
	printf("a: %d b: %d \n", a, b);	

	return 0;
}

/*
The function recives two int pointers as input and if the value of one pointer is less than
the value of the other pointer, it will change the first pointer value to the first pointer value + the second pointer value
else, it will change the first pointer value and the first pointer value - the second pointer value.
input: two pointers of int
output: none


//------ a and b are changing because we pass two pointers (memory addresses) so when the function change stuff, it saves globaly in the memory, so the main can access it ---- 
*/
void mystery(int* x, int* y)
{
	if(*x < *y)
	{
		*x = *x + *y;
	}
	else{
		*x = *x - *y;
	}
}
