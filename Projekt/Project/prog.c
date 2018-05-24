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


char* readBinaryData(FILE* signature, char* signatureArr, int length);
int isFileInfected(char* virusSignature, char* file, int sigLength, int fileLength);
int getFileLength(FILE* file);

int main(int argc, char** argv)
{
	char path[] = "C:\\Users\\magshimim\\OneDrive\\Documents\\Magshimim\\C2\\C\\Project\\Files\\Project_Files\\KittenVirusSign";
	char picPath[] = "C:\\Users\\magshimim\\OneDrive\\Documents\\Magshimim\\C2\\C\\Project\\Files\\Project_Files\\kitten_run.jpg";
	char* virusSignature = 0;
	char* fileCheck = 0;
	int sigLength = 0;
	int fileLength = 0;
	
	FILE* sig = fopen(path, "rb");
	FILE* infFile = fopen(picPath, "rb");

	sigLength = getFileLength(sig);
	fileLength = getFileLength(infFile);


	virusSignature = readBinaryData(sig, virusSignature, sigLength);
	fileCheck = readBinaryData(infFile, fileCheck, fileLength);
	int a = isFileInfected(virusSignature, fileCheck, sigLength, fileLength);
	if (a)
	{
		printf("Yes!");
	}
	getchar();

	fclose(sig);
	fclose(infFile);
	free(virusSignature);
	free(fileCheck);
	return 0;
}
char* readBinaryData(FILE* sourceFile, char* destinationArray, int length)
{
	//allocate the space:
	destinationArray = (char*)malloc(sizeof(char) * length); 
	fread(destinationArray, 1, length, sourceFile);
	return destinationArray;
}
//https://stackoverflow.com/questions/7483634/determining-if-one-array-is-contained-in-another
int isFileInfected(char* virusSignature, char* file, int sigLength, int fileLength)
{
	int i = 0, j = 0;;
	for (i = 0; i < fileLength; i++)
	{
		printf("%X ", file[i] & 0xFF);
	}
	printf("\n\n\n\n");
	for (i = 0; i < sigLength; i++)
	{
		printf("%X ", virusSignature[i] & 0xFF);
	}
	
	printf("\n\n");

	int matches = 0;
	int exit = FALSE;
	for (i = 0; i < fileLength - (sigLength - 1) && !exit; ++i)
		if (file[i] == virusSignature[0]) // if the element matches the first element in the signature
		{
			matches = TRUE;
			for (j = 1; j < sigLength && matches; ++j)
			{
				if (file[i + j] != virusSignature[j])
				{
					matches = FALSE;
				}
			}
			
			if (matches)
			{
				printf("Infected");
				exit = TRUE;
			}
		}
	return matches;
}
int getFileLength(FILE* file)
{
	int length = 0;
	fseek(file, 0, SEEK_END);
	length = ftell(file);
	fseek(file, 0, SEEK_SET);
	return length;
}