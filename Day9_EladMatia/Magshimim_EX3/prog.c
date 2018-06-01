/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE !FALSE

int isPalindrome(char str[], int beg, int end);
int main(void)
{

	//Write your code here...
	isPalindrome("abba", 0, 3);
	getchar();
	return 0;
}
int isPalindrome(char str[], int beg, int end)
{
	if (str[beg] != str[end])
	{
		return FALSE;
	}
	if (beg < end + 1) //+1 if the length of the string is odd
	{
		return isPalindrome(str, beg++, end--);
	}
	return TRUE;
}