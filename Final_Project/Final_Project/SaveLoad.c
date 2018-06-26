#include "SaveLoad.h"

int getFileSize(FILE* file);

/*
The function saves the project to a file
Input: list head
Output: none
*/
void saveProject(FrameNode** head)
{
	FILE* saveFile = NULL;
	FrameNode* curr = *head;
	char path[PATH_SIZE] = { 0 };
	printf("Where do you want to save the project? Enter the path: ");
	myFgets(path, PATH_SIZE);
	saveFile = fopen(path, "w");
	if (!saveFile) //check if we are unable to create the file
	{
		printf("Error creating file.\n");
	}
	else
	{
		while (curr)
		{
			fprintf(saveFile, "%s %s %d |", curr->frame->path, curr->frame->name, curr->frame->duration);
			curr = curr->next;
		}
	}
	fclose(saveFile);
}
/*
The function loads saved project from a file
Input: the list of frames
Output: None
*/
void loadProject(FrameNode** head)
{
	char saveFile[PATH_SIZE] = { 0 };
	FILE* loadFrom = NULL;
	char* file = NULL;
	int i = 0;
	int j = 0;
	int k = 0;
	int tempNumber[TEMP_NUMBER_LENGTH] = { 0 }; //WE CAN FILL WITH NEGATIVE NUMBER BECAUSE WE KNOW DURATION WILL NEVER BE NEGATIVE

	for (i = 0; i < TEMP_NUMBER_LENGTH; i++)
	{
		tempNumber[i] = -1;
	}

	int temp = 1;
	int stage = 0;
	char c = 0;
	int fileLength = 0;

	int numOfFrames = 0;
	char** paths = NULL;
	char** names = NULL;
	int* durations = 0;

	printf("Enter the path to the save file: ");
	myFgets(saveFile, PATH_SIZE);
	loadFrom = fopen(saveFile, "r");
	while (!loadFrom)
	{
		printf("File couldn't be found. Enter a valid path to the file: ");
		myFgets(saveFile, PATH_SIZE);
		loadFrom = fopen(saveFile, "r");
	}

	fileLength = getFileSize(loadFrom);
	file = (char*)malloc(fileLength * sizeof(char));

	for (i = 0; i < fileLength; i++)
	{
		c = (char)getc(loadFrom);
		if (c == '|') //we need to know the number of frames in order to malloc 
		{
			numOfFrames++;
		}
		file[i] = c;
	}
	fclose(loadFrom);

	paths = (char**)malloc(sizeof(char*)*numOfFrames);
	names = (char**)malloc(sizeof(char*)*numOfFrames);
	durations = (int*)malloc(sizeof(int)*numOfFrames);

	for (i = 0; i < numOfFrames; i++)
	{
		paths[i] = (char*)malloc(sizeof(char)*PATH_SIZE); //TODO: free
		names[i] = (char*)malloc(sizeof(char)*STR_SIZE); //TODO: free

	}
	for (i = 0; i < fileLength; i++)
	{
		if (file[i] != '|') //split the frames into their arrays
		{
			if (stage == 0) //stage 0: find the path
			{
				if (file[i] != ' ')
				{
					paths[j][k] = file[i];
					k++;
				}
				else
				{
					paths[j][k] = 0; //make it a string
					k = 0;
					stage = 1;
				}
			}
			else if (stage == 1) //stage 1: find the frame name
			{
				if (file[i] != ' ')
				{
					names[j][k] = file[i];
					k++;
				}
				else
				{
					names[j][k] = 0; //make it a string
					k = 0;
					stage = 2;
				}
			}
			else
			{ // This "function" turns a string of numbers to actual number
				if (file[i] != ' ')
				{
					tempNumber[k] = file[i] - '0';
					k++;
				}
				else
				{
					temp = tempNumber[0];
					for (k = 1; tempNumber[k] != -1; k++)
					{
						temp *= 10;
						temp += tempNumber[k];
					}
				}
				durations[j] = temp;
			}
		}

		else
		{
			j++;
			stage = 0;
			temp = 0;

			for (k = 0; k < TEMP_NUMBER_LENGTH; k++)
			{
				tempNumber[k] = -1;
			}
			k = 0;
		}
	}
	for (i = 0; i < numOfFrames; i++) //create frame node and free the unneccessery stuff
	{
		Frame* newFrame = createFrame(names[i], paths[i], durations[i]);
		FrameNode* newFrameNode = (FrameNode*)malloc(sizeof(FrameNode));
		newFrameNode->frame = newFrame;
		newFrameNode->next = NULL;
		insertNode(head, newFrameNode);
		free(paths[i]);
		free(names[i]);
	}
	free(names);
	free(paths);
	free(durations);
	free(file);
}
/*
The function returns the size of a given file
Input: the file to check
Output: the file size
*/
int getFileSize(FILE* file)
{
	int size = 0;
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);
	return size;

}
