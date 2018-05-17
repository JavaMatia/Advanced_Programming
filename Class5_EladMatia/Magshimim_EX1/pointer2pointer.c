/*********************************
* Class: MAGSHIMIM C2			 *
* Week 5           				 *
* HW solution   			 	 *
**********************************/
#include <stdio.h>

int main(void)
{
	int y = 3;
	int x = 7;
	int *px = 0;
	int *py = 0;
	int **ppx = 0;
	int **ppy = 0;
    
    /*
        YOUR CODE HERE

    */
	px = &x;
	printf("%d\n", x);
	ppx = &px;
	printf("%d\n", x);
	(**ppx) = 10;
	printf("%d\n", x);
	y = **ppx - y;
	printf("%d\n", y);
	getchar();	
	return 0;
}