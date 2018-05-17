/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>

int main(void)
{

	//Write your code here...
	int* p = NULL;
	printf("%p", p);
	printf("%d", *p);
	/*
	A. The first printf printed 0000000, and the second printf crashed the program. I think it is becasue 00000000 is not an actual addrress, it is null, so when it tried to read it it crashed because it practicly doesn't phisicly exist.
	B. Sort of. 0000000 doesn't exist, and the program crashed trying to access area it should not access.
	*/
	getchar();
	return 0;
}