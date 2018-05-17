/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	//Write your code here...
	char help[] = {"help"};
	char breathe[] = {"Breathe :) everything is OK"};
	char normal[] = {":)"};
	int flag = 1;
	int i = 0;
	for (i = 1; i < argc && flag; i++) // run through the number of parameters to main
	{
		if (!strcmp(help, *(argv+i))) // check if he entered help
		{
			printf("%s", breathe);
			flag = 0; //we found help exit the loop
		}
	}
	if (flag)
	{
		printf("%s", normal); // print normal message if help wasn't entered
	}
	getchar();
	return 0;
}