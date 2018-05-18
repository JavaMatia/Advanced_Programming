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

<<<<<<< Updated upstream
int validOption(char** argv, FILE** copyFrom);
void textCopy(FILE* inputFile, char* output);
int fileDoesntExist(FILE* filename);
void binaryCopy(FILE* inputFile, char* output);
=======
int validOption(char** argv);
int fileDoesntExist(FILE* filename);
void textCopy(char** argv, FILE* inputFile, char* output);
>>>>>>> Stashed changes

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
/*
This function copies text files
Input: the file pointer and the destination file name
Output: None
*/
void textCopy(FILE* inputFile, char* output)
{
<<<<<<< Updated upstream
	int currentCharacter = 0;
	FILE* check = fopen(output, "r"); // this line tries to open the entered output file. I used "r" mode because if i use "w" it will create it
	if (fileDoesntExist(check)) // if the file doesn't exist, read from it
=======
	FILE* outputFile = fopen(output, "w");
	if (fileDoesntExist(outputFile))
>>>>>>> Stashed changes
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
/*
This function copies binary files
Input: the file to copy from and the output file name
Output: None
*/
void binaryCopy(FILE* inputFile, char* output)
{
	char* arr = 0;
	int i = 0;
	FILE* outputFile = fopen(output, "wb");
	FILE* check = fopen(output, "r"); // this line tries to open the entered output file. I used "r" mode because if i use "w" it will create it
	if (fileDoesntExist(check)) // if the file doesn't exist, read from it
	{
		fseek(inputFile, 0, SEEK_END);
		int length = ftell(inputFile) * sizeof(char);
		arr = (char*)malloc(length);

		fseek(inputFile, 0, SEEK_SET); //GO BACK
		fread(arr, 1, length, inputFile);

		fseek(inputFile, 0, SEEK_SET); //GO BACK
		fwrite(arr, 1, length, outputFile);
	}
	free(arr);
	if (!check) { fclose(check); }
	fclose(outputFile);
	printf("Copy completed.");
}

/*
This function cheks if a file already exist
Input: The file pointer
Output: true if the file doesn't exist false otherwise
*/
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