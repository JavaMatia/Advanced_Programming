/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <string.h>

#define SIZE 50
#define LAST 'z'
#define START 'a'
void decrypt(char* cypher, int n);
int main(void)
{
	char arr[SIZE] = { 0 }; // have to use [] to allocate the space needed or the program crashes
	int n = 0;
	printf("Enter cypher to decrypt: \n");
	fgets(arr, SIZE, stdin); //get the string
	*(arr + (strlen(arr) - 1)) = 0; // remove the enter
	printf("Enter decryption key: \n");
	scanf("%d", &n); // get the encryption key
	getchar();
	decrypt(arr, n);
	getchar();
	return 0;
}
/*
The function revers a string, and then doing +n to each letter
Input: string and n as integer
Output: the decrypted cypher
*/
void decrypt(char* cypher, int n)
{
	int i = 0;
	int index = strlen(cypher) - 1;
	char temp = 0;
	char ch = 0;
	//reverse the string
	for (i = 0; i < strlen(cypher) / 2; i++) // we can do it twice as fast
	{ // ---- i have a warning about something that i has to be size_t and not size. Not sure how to fix it--- //TODO: Fix it
		temp = *(cypher + index); // this is the last element of the array in a temporery variable
		*(cypher + index) = *(cypher + i); // now the last element in array is in the first element of the array
		*(cypher + i) = temp; // now the first element in the array is the temp which was the last element of the array
		index--;
	}
	for (i = 0; i < strlen(cypher); i++)
	{
		ch = (char)(*(cypher + i) + n);
		while (ch > LAST) // if we are passing z, loop and
		{
			ch = ch - LAST + START - 1; //go back and count from a

		}

		*(cypher + i) = ch; //add

	}

	printf("Decrypted text: %s", cypher); // print
}