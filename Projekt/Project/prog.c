/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/



#define FALSE 0
#define TRUE !FALSE
#define LENGTH 50

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

char* readBinaryData(FILE* signature, char* signatureArr, int length);
int isFileInfected(char* virusSignature, char* file, int sigLength, int fileLength);
int getFileLength(FILE* file);
char* createLog(char* folderPath, FILE* log, char* virusPath, int choice);

int main(int argc, char** argv)
{
	struct dirent *pDirent;
	FILE* log = 0;
	char* virusSignature = 0;
	char* fileCheck = 0;
	int sigLength = 0;
	int fileLength = 0;
	int skip = FALSE;
	char* exPath = 0;
	int counter = 0;
	int choice = 0;
	char* logPath = 0;
	//check if we have enough arguments:
	if (argc != 3)
	{
		printf("Invalid execution!\nUsage: antivirus.exe <directory_to_search> <VirusSignature>");
		return 1;
	}
	//check if the folder or file can be opened:
	//make it easier to read:
	char* folderPath = argv[1];
	char* signaturePath = argv[2];

	FILE* signature = fopen(argv[2], "rb");
	DIR* pDir = opendir(argv[1]);
	if (pDir == NULL || signature == NULL)
	{
		printf("Couldn't open file or directory. Exiting now.");
		return 1;

	}

	//some ux...
	printf("Welcome to my Anti Virus!\n\nFolder to scan: %s\nVirus signature: %s\n\n", folderPath, signaturePath);
	printf("Press 0 for a normal scan or any other key for a quick scan: ");
	scanf("%d", &choice);
	getchar();
	printf("\nScanning began...\nThis process may take several minutes...\n\nScanning:\n");

	//prepare log:
	logPath = createLog(folderPath, log, signaturePath, choice);

	sigLength = getFileLength(signature); // file length
	virusSignature = readBinaryData(signature, virusSignature, sigLength); // the virus signature is now inside array

	if (!choice)
	{
		while ((pDirent = readdir(pDir)) != NULL) //read from the directory until we don't get a null
		{
			if (counter >= 2)
			{
				skip = FALSE;
				exPath = (char*)malloc(strlen(folderPath) + strlen(pDirent->d_name) + 2); // +2 for the 0 and for the //
				strcpy(exPath, folderPath);
				strcat(exPath, "\\");
				strcat(exPath, pDirent->d_name);
				//exPath - now has the path to the first file 



				//>>>>>FROM HERE SECTION B HAS TO CHANGE SOME STUFF
				//read the contend of the file:
				FILE* fileToCheck = fopen(exPath, "rb");
				FILE* logFile = fopen(logPath, "a+");
				if (fileToCheck == NULL)
				{
					printf("Couldn't open %s. Skipping (Could be a directory or something)\n", exPath);
					skip = TRUE;
				}
				if (!skip)
				{
					fileLength = getFileLength(fileToCheck);
					fileCheck = readBinaryData(fileToCheck, fileCheck, fileLength);
					if (isFileInfected(virusSignature, fileCheck, sigLength, fileLength))
					{
						printf("%s - Infected!\n", exPath);
						fprintf(logFile, "%s   Infected!\n", exPath);
					}
					else
					{
						printf("%s - Clean\n", exPath);
						fprintf(logFile, "%s   Clean\n", exPath);
					}
					fclose(fileToCheck);
				}
				fclose(logFile);
			}

			counter++; //the first two "files" are just .. so we are skipping
		}
	}
	else
	{
		printf("Coming soon.");
	}
	printf("Scan complete");


	getchar();
	free(exPath);
	free(virusSignature);
	free(fileCheck);
	return 0;
}
/*
The function returns an array with all the binary data in it
*/
char* readBinaryData(FILE* sourceFile, char* destinationArray, int length)
{
	//allocate the space:
	destinationArray = (char*)malloc(sizeof(char) * length);
	fread(destinationArray, 1, length, sourceFile);
	return destinationArray;
}

//https://stackoverflow.com/questions/7483634/determining-if-one-array-is-contained-in-another
/*
The function checks if specific file is infected 
Input: the virus signatue, the file to check and both of their lengths
Output: 0 if file is clean, anything otherwise
*/
int isFileInfected(char* virusSignature, char* file, int sigLength, int fileLength)
{
	int i = 0, j = 0;;
	int matches = 0;
	int exit = FALSE;
	for (i = 0; i < fileLength - (sigLength - 1); ++i)
		if (file[i] == virusSignature[0]) // if the element matches the first element in the signature
		{
			matches = TRUE;
			exit = FALSE;
			for (j = 1; j < sigLength && !exit; ++j)
			{
				if (file[i + j] != virusSignature[j])
				{
					matches = FALSE;
					exit = TRUE;
				}
			}
			if (matches)
			{
				return TRUE; // if we got a match, return true!
			}
		}
	return 0; // zero of the file is clean
}
/*
The function returns the size of file.
*/
int getFileLength(FILE* file)
{
	int length = 0;
	fseek(file, 0, SEEK_END);
	length = ftell(file);
	fseek(file, 0, SEEK_SET);
	return length;
}
/*
The function creates a basic log with the neccessery infromation
Input: The folder, path. the virus path the the choice chosen
Retrun: the log path
*/
char* createLog(char* folderPath, FILE* log, char* virusPath, int choice)
{
	char* exPath;
	exPath = (char*)malloc(strlen(folderPath) + 2 + strlen("AntiVirusLog.txt")); // +2 for the 0 and for the //
	strcpy(exPath, folderPath);
	strcat(exPath, "\\");
	strcat(exPath, "AntiVirusLog.txt");

	char mode[LENGTH] = {0};
	if (!choice)
	{
		strcat(mode, "Normal Scan");
	}
	else
	{
		strcat(mode, "Quick Scan");
	}


	log = fopen(exPath, "w");
	fprintf(log, "Anti-Virus began! Welcome!\nFolder to scan:\n%s\nVirus Signature:\n%s\nScanning option:\n%s\nResults:\n",folderPath, virusPath, mode);



	free(exPath);
	fclose(log);
	return exPath;
}