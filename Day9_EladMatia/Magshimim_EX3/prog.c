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
#define LENGTH 256

int isPalindrome(char str[], int beg, int end);
void myFgets(char* p, int size);

int main(void)
{
	char string[LENGTH] = { 0 };
	printf("Enter string: ");
	myFgets(string, LENGTH);
	if (isPalindrome(string, 0, strlen(string) - 1))
	{
		printf("Yes, it's a palindrome!");
	}
	else
	{
		printf("Not a palindrome!");
	}
	getchar();
	return 0;
}
/*
the function checks for a palindrom
Input: a string to check, the first index of a string and the last one
Output: true if this is a palindrome, false otherwise
*/
int isPalindrome(char str[], int beg, int end)
{
	if (str[beg] != str[end])
	{
		return FALSE; // if this is not a palindrome
	}
	if (beg < end + 1) //+1 if the length of the string is odd
	{
		return isPalindrome(str, beg + 1, end - 1);// if we havn't reached the middle, run the function again but with defferent beginning and end
	}
	return TRUE; //this is a palindrome
}
/*
gets a string
*/
void myFgets(char* p, int size)
{
	fgets(p, size, stdin);
	p[strcspn(p, "\n")] = 0;
}