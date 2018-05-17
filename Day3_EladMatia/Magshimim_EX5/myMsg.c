/*********************************
* Class: MAGSHIMIM C2			 *
* Week 3           				 *
* HW solution   			 	 *
**********************************/
#include <stdio.h>
#include <string.h>

void printArray(char* p, int len) //the problem is the loop condition. p is always getting bigger, so it never will be the same as itself plus something
								// because the loop never stops, we reach places in the memory we shouldn't access and the program crashes
{
	for(p; *p!=0 ; p++ ) 
	{
		printf("%c", *p);
	}
	printf("\n");
}

int main(void)
{
	char* msg = "hi jyegq meet me at 2 :)"; //he wants to meet sigal (used the previous algorithem and the key was 2)
	printArray(msg, strlen(msg));
    getchar();
	return 0;
 }
