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
char** sort(DIR* dir, char** filesArray, int* length);
int isFileInfected(char* virusSignature, char* file, int sigLength, int fileLength);
int getFileLength(FILE* file);
FILE* createLog(char* folderPath, FILE* log, char* virusPath, int choice);
char* getPercent(char* file, int length, int mode, char* tempArray, int* globalLength);


int main(int argc, char** argv)
{
	FILE* log = 0;
	char* virusSignature = 0;
	char* fileCheck = 0;
	int sigLength = 0;
	int fileLength = 0;
	int length = 0;
	int skip = FALSE;
	char* exPath = 0;
	int choice = 0;
	int i = 0;
	char** filesArray = 0;
	char* tempArray = 0;
	int state = 0;
	int tempArrayLength = 0;
	int ok = FALSE;
	//check if we have enough arguments:
	if (argc != 3)
	{
		printf("Invalid execution!\nUsage: antivirus.exe <directory_to_search> <VirusSignature>");
		getchar();
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
	log = createLog(folderPath, log, signaturePath, choice);

	sigLength = getFileLength(signature); // file length
	virusSignature = readBinaryData(signature, virusSignature, sigLength); // the virus signature is now inside array

	filesArray = sort(pDir, filesArray, &length);
	for (i = 0; i < length; i++) //read from the directory until we don't get a null
	{
		skip = FALSE;
		exPath = (char*)malloc(strlen(folderPath) + strlen(filesArray[i]) + 2); // +2 for the 0 and for the //
		strcpy(exPath, folderPath);
		strcat(exPath, "/");
		strcat(exPath, filesArray[i]);
		//exPath - now has the path to the first file 
		//read the contend of the file:
		FILE* fileToCheck = fopen(exPath, "rb");
		if (fileToCheck == NULL)
		{
			printf("Couldn't open %s. Skipping (Could be a directory or something)\n", exPath);
			skip = TRUE;
		}
		if (!skip && (strcmp(filesArray[i], "AntiVirusLog.txt"))) //if the file could be openned
		{
			fileLength = getFileLength(fileToCheck);
			fileCheck = readBinaryData(fileToCheck, fileCheck, fileLength); // read its contents
			if (!choice) //if the user chose normal scan
			{
				if (isFileInfected(virusSignature, fileCheck, sigLength, fileLength)) // check if the file is infected
				{
					printf("%s - Infected!\n", exPath);
					fprintf(log, "%s   Infected!\n", exPath); //write it to the log
				}
				else //if the file is clear
				{
					printf("%s - Clean\n", exPath);
					fprintf(log, "%s   Clean\n", exPath);
				}

			}
			else // if the user chose quick scan: 
			{
				state = 0;
				tempArray = getPercent(fileCheck, fileLength, state, tempArray, &tempArrayLength); // recieve the first 20 percent of the array
				if (isFileInfected(virusSignature, tempArray, sigLength, tempArrayLength)) // if the virus was found in the first 20 percent, infrom the user and write it to the log
				{
					printf("%s - Infected! <first 20%%>\n", exPath);
					fprintf(log, "%s   Infected! <first 20%%>\n", exPath);
					ok = TRUE;

				}
				if (!ok) // if the virus wasn't found, search in the last 20 percnet
				{
					state = 1;
					tempArray = getPercent(fileCheck, fileLength, state, tempArray, &tempArrayLength); // recieve the last 20 percent of the array
					if (isFileInfected(virusSignature, tempArray, sigLength, tempArrayLength))
					{
						printf("%s - Infected! <last 20%%>\n", exPath);
						fprintf(log, "%s   Infected! <last 20%%>\n", exPath);
						ok = TRUE;
					}

				}
				if (!ok) // if the virus still wasn't found, run a full scan.
				{
					//run a full scan
					if (isFileInfected(virusSignature, fileCheck, sigLength, fileLength))
					{
						printf("%s - Infected!\n", exPath);
						fprintf(log, "%s   Infected!\n", exPath);
					}
					else
					{
						printf("%s - Clean\n", exPath);
						fprintf(log, "%s   Clean\n", exPath);
					}


				}
				ok = FALSE;
			}
			fclose(fileToCheck); // close the file that was scanned
		}

	}

	printf("Scan complete\n");
	printf("See log path for results: %s\\AntiVirusLog.txt", folderPath);


	fclose(log); // close the log file
	free(filesArray);
	free(tempArray); // close the tempArray (where the last or first 20 percent of the file data was stored)
	free(exPath); // free the path for the files
	free(virusSignature); // free the virus signature data array
	free(fileCheck); // 
	getchar();

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
Retrun: the log file
*/
FILE* createLog(char* folderPath, FILE* log, char* virusPath, int choice)
{
	char* exPath;
	exPath = (char*)malloc(strlen(folderPath) + 2 + strlen("AntiVirusLog.txt")); // +2 for the 0 and for the //
	strcpy(exPath, folderPath);
	strcat(exPath, "/");
	strcat(exPath, "AntiVirusLog.txt");

	char mode[LENGTH] = { 0 };
	if (!choice)
	{
		strcat(mode, "Normal Scan");
	}
	else
	{
		strcat(mode, "Quick Scan");
	}


	log = fopen(exPath, "w");
	fprintf(log, "Anti-Virus began! Welcome!\nFolder to scan:\n%s\nVirus Signature:\n%s\nScanning option:\n%s\nResults:\n", folderPath, virusPath, mode);



	free(exPath);
	return log;
}
/*
This function returns the first\last percent of the file array data according to mode
Input: the file array data, its length, mode- 0 for first 20 percent other for the last 20 percent. the array to store stuff and its length
*/
char* getPercent(char* file, int length, int mode, char* tempArray, int* globalLength)
{
	int i = 0;
	int newLength = 0;
	int counter = 0;
	newLength = (int)(0.2 * length);
	tempArray = (char*)realloc(tempArray, sizeof(char)*newLength);
	// if mode is 0 - we need to return the first 20 percent of the array
	if (!mode)
	{
		for (i = 0; i < newLength; i++)
		{
			tempArray[i] = file[i];
		}
	}
	else
	{
		for (i = length - newLength; i < length; i++)
		{
			tempArray[counter] = file[i];
			counter++;
		}
	}
	*globalLength = newLength;
	return tempArray;
}
char** sort(DIR* dir, char** filesArray, int* length)
{
	int i = 0;
	struct dirent *pDirent;
	int numOfFiles = 0;

	// dont't show the dots

	while ((pDirent = readdir(dir)) != NULL)
	{
		numOfFiles++;

	}
	filesArray = (char**)malloc(sizeof(char*)*numOfFiles);
	rewinddir(dir);
	//readdir(dir);
	//readdir(dir);
	pDirent = readdir(dir);
	for(i=0; i<numOfFiles; i++)
	{
		filesArray[i] = (char*)malloc(strlen(pDirent->d_name)*sizeof(char)+1);
		filesArray[i][strlen(pDirent->d_name) * sizeof(char)] = 0;
		strncpy(filesArray[i], pDirent->d_name, strlen(pDirent->d_name));
		if (i != numOfFiles)
		{
			pDirent = readdir(dir);

		}
	}
	*length = i;
	return filesArray;
}