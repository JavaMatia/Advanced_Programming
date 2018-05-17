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
#define TEXT "textCopy"
#define BINARY "binaryCopy"
#define ERRMSG  "Invalid execution\nUsage: copyFile.exe (textCopy|binaryCopy) <sourceFilename_filename> <destinationFilename_filename>"

int canConitnue = TRUE;

int validOption(char** argv);

int main(int argc, char** argv)
{
	FILE* copyFrom = fopen(argv[2], "r");
	if (argc == 4) // check for arguments
	{
		if (!validOption(argv)) // check for valid mode
		{
			canConitnue = FALSE;
		}
		else if (canConitnue && copyFrom == NULL) // if the file is null it means it doesn't exist
		{
			printf("%s file does not exist", argv[2]);
			canConitnue = FALSE;
		}

	}
	else
	{
		printf("%s", ERRMSG);
		canConitnue = FALSE;
	}
	if (canConitnue) // if we received a valid arguments we can continue
	{
		if (argv[1] = TEXT)
		{
			textCopy(argv, copyFrom, argv[3]);
		}

	}
	getchar();
	return 0;
}
/*
The function checks if the user entered a valid operation
Input: Argc - number of arguments, argv - array of arguments
Output: True if the user entered a valid operation, false otherwise
*/
int validOption(char** argv)
{
	if (!strcmp(argv[1], TEXT) || !strcmp(argv[1], BINARY))
	{
		return TRUE;
	}
	else
	{
		printf("%s", ERRMSG);
		return FALSE;
	}
}
void textCopy(char** argv, FILE* inputFile, char* output)
{
	FILE* outputFile = fopen(output, "w");
	if (filDoesntExist(outputFile))
	{
		while (fgetc(inputFile) != -1)
		{

		}
	}
	
}
int fileDoesntExist(FILE* filename)
{
	int choice = -1;
	if (filename == NULL) // file doesn't exist. proceed normally
	{
		return -1;
	}
	else
	{
		printf("Do you want to overwrite? 0 (no) / 1 (yes)");
		scanf("%d", &choice);
		return choice;
	}
}