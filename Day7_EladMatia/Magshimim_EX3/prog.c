/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE !FALSE
#define TEXT "textCopy"
#define BINARY "binaryCopy"
#define ERRMSG  "Invalid execution\nUsage: copyFile.exe (textCopy|binaryCopy) <sourceFilename_filename> <destinationFilename_filename>"

int canConitnue = FALSE;

int validOption(char** argv, FILE** copyFrom);
void textCopy(FILE* inputFile, char* output);
int fileDoesntExist(FILE* filename);
void binaryCopy(FILE* inputFile, char* output);

int main(int argc, char** argv)
{

	FILE* copyFrom = 0;
	if (argc == 4) // check for arguments
	{

		if (validOption(argv, &copyFrom)) // check for valid mode
		{
			canConitnue = TRUE;
		}
		if (canConitnue && copyFrom == NULL) // if the file is null it means it doesn't exist
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


		if (!strcmp(argv[1], TEXT))
		{
			textCopy(copyFrom, argv[3]);
		}
		else
		{
			binaryCopy(copyFrom, argv[3]);
		}
		fclose(copyFrom);


	}
	getchar();
	return 0;
}
/*
The function checks if the user entered a valid operation and open it with the correct mode
Input: Argc - number of arguments, argv - array of arguments
Output: True if the user entered a valid operation, false otherwise
*/
int validOption(char** argv, FILE** copyFrom)
{
	if (!strcmp(argv[1], TEXT))
	{
		*copyFrom = fopen(argv[2], "r");
		return TRUE;
	}
	else if (!strcmp(argv[1], BINARY))
	{
		*copyFrom = fopen(argv[2], "rb");
		return TRUE;
	}

	else
	{
		printf("%s", ERRMSG);
		return FALSE;
	}
}
void textCopy(FILE* inputFile, char* output)
{
	int currentCharacter = 0;
	FILE* check = fopen(output, "r"); // this line tries to open the entered output file. I used "r" mode because if i use "w" it will create it
	if (fileDoesntExist(check)) // if the file doesn't exist, read from it
	{
		FILE* outputFile = fopen(output, "w");
		do
		{
			currentCharacter = fgetc(inputFile);
			if (currentCharacter != -1)
			{
				fputc(currentCharacter, outputFile);
			}

		} while (currentCharacter != -1);//read until you reach the end
		fclose(outputFile);
		printf("Copy completed.");
	}
	if (check != NULL)
	{
		fclose(check);
	}

}
void binaryCopy(FILE* inputFile, char* output)
{
	char* arr = 0;
	fseek(inputFile, 0, SEEK_END);
	arr = malloc(ftell(inputFile)+1);
	arr[ftell(inputFile)] = 0; // make it a string
	fseek(inputFile, 0, SEEK_SET); //GO BACK
	do
	{
		fread(arr, sizeof(char), 1, inputFile);
	} while (fread(arr, sizeof(char), 1, inputFile) == 1);	
	printf("%s", arr);
	free(arr);
}


int fileDoesntExist(FILE* filename)
{
	int choice = -1;
	if (!filename) // file doesn't exist. proceed normally
	{
		return TRUE;
	}
	else
	{
		printf("Do you want to overwrite? 0 (no) / 1 (yes)");
		scanf("%d", &choice);
		return choice; // if the user chooses one, the function returns true and we proceed - the file will be overwritten
	}
}