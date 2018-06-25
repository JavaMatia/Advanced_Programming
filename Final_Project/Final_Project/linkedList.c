#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedList.h"

void myFgets(char str[], int n);
Frame* createFrame(char fName[STR_SIZE], char path[PATH_SIZE], int duration);
void insertNode(FrameNode** head, FrameNode* node);
int listLength(FrameNode** head);
int getFileSize(FILE* file);


/*
The function create and returns a Frame struct. It also checks if the path entered is invalid.
Input: list head to run duplicate name check
Output: the new Frame struct (not FrameNode)
*/
Frame* createFrame(char fName[STR_SIZE], char path[PATH_SIZE], int duration)
{
	Frame* newFrame = (Frame*)malloc(sizeof(Frame));

	newFrame->name = (char*)malloc(sizeof(char)*STR_SIZE);
	newFrame->path = (char*)malloc(sizeof(char)*PATH_SIZE);
	strncpy(newFrame->name, fName, STR_SIZE);
	strncpy(newFrame->path, path, PATH_SIZE);
	newFrame->duration = duration;
	return newFrame;
}

/*
The function creates a new FrameNode node.
Input: the head of the list
Output: None
*/
void createFrameNode(FrameNode** head)
{
	char fName[STR_SIZE] = { 0 };
	char path[PATH_SIZE] = { 0 };
	FILE* check = NULL;
	FrameNode* curr = *head;
	int duration = 0;

	//get path 
	printf("Enter frame path: ");
	myFgets(path, PATH_SIZE);
	//file check 
	check = fopen(path, "r");
	while (!check)
	{
		printf("Invalid path. Try again: ");
		myFgets(path, PATH_SIZE);
		check = fopen(path, "r");

	}
	if (check != NULL)
	{
		fclose(check);
	}

	//get duration
	printf("Enter frame duration in milliseconds: ");
	scanf("%d", &duration);
	getchar();
	//get name
	printf("Enter frame name (25 characters MAX): ");
	myFgets(fName, STR_SIZE);
	//duplicate name check:

	while (curr != NULL) //duplicate name check
	{
		while (!strcmp(curr->frame->name, fName))
		{
			printf("Frame name is already taken. please choose a different name: ");
			myFgets(fName, STR_SIZE);
		}
		curr = curr->next;
	}
	Frame* newFrame = createFrame(fName, path, duration); //craete new -FRAME-
	FrameNode* newFrameNode = (FrameNode*)malloc(sizeof(FrameNode));
	newFrameNode->frame = newFrame;
	newFrameNode->next = NULL;
	insertNode(head, newFrameNode);

}
/*
The function inserts a node to the end of the list
Input: a pointer to a pointer to the head of the list and a new node to insert
Output: None
*/
void insertNode(FrameNode** head, FrameNode* node)
{
	FrameNode* curr = *head;
	if ((*head) == NULL) // in case the head of the list is null 
	{
		*head = node;
	}
	else
	{
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = node;
	}
}

/*
The function prints the list
Input: The list head
Output: None
*/
void printList(FrameNode** head)
{
	FrameNode* curr = *head;
	while (curr != NULL)
	{
		printf("[name: %s, path: %s, duration: %d]\n", curr->frame->name, curr->frame->path, curr->frame->duration);
		curr = curr->next;
	}
	printf("\n");
}

//Gets a string
void myFgets(char str[], int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}
/*
The function removes a frame by its name
Input: the function head
Output: None
*/
void removeFrame(FrameNode** head)
{
	char name[STR_SIZE] = { 0 };
	FrameNode* temp = NULL;
	FrameNode* curr = *head;
	int done = 0;
	printf("Enter frame name to remove: ");
	myFgets(name, STR_SIZE);
	if (curr) // if the list is not empty
	{
		if (!strcmp((*head)->frame->name, name)) //check if we are deleting the first person in line
		{
			temp = *head;
			free(temp->frame->name);
			free(temp->frame->path);
			free(temp);
			*head = (*head)->next;
			done = 1;
			*head = NULL;
		}
		else
		{
			while (curr->next && !done)
			{
				if (!strcmp(curr->next->frame->name, name)) // we want to catch the node before the one we want to delete
				{
					temp = curr->next; // put aside the node to delete
					free(temp->frame->name); // delete the node
					free(temp->frame->path);
					free(temp);
					curr->next = temp->next; // link the node before it, to the node after it

					done = 1;

				}
				else
				{
					curr = curr->next;
				}
			}
		}

	}
	if (done)
	{
		printf("%s removed from frame list\n", name);
	}
	else
	{
		printf("%s doesn't exist\n", name);
	}

}
/*
The function returns the length of the list
Input: the list head
Output: the length of the list
*/
int listLength(FrameNode** head)
{
	FrameNode* curr = *head;
	int counter = 0;
	while (curr)
	{
		counter++;
		curr = curr->next;
	}
	return counter;
}

void changeFramePosition(FrameNode** head)
{
	FrameNode* curr = *head;
	FrameNode* x = NULL; //the node we are moving
	char frameName[STR_SIZE] = { 0 };
	int pos = 0;
	int i = 0;
	int flag = FALSE;
	printf("Enter the name of the frame you wish to move: ");
	myFgets(frameName, STR_SIZE);
	printf("Enter new position: ");
	scanf("%d", &pos);
	getchar();


	if (!curr)
	{
		//head is null, nothing to move
		printf("List is empty, nothing to move.");
	}

	//check for invalid position
	while (pos > listLength(head) && pos < 1)
	{
		printf("Invalid position! Try again: ");
		scanf("%d", &pos);
		getchar();
	}


	if (!strcmp((*head)->frame->name, frameName)) //check if we are moving the first element in the list
	{
		flag = TRUE;
		x = *head;
		*head = (*head)->next;
	}
	else
	{
		while (curr->next && !flag) //grab the frame we want to move
		{
			if (!strcmp(curr->next->frame->name, frameName))
			{
				x = curr->next; //this is the frame the user asked to move
				flag = TRUE;
				curr->next = curr->next->next; //link the node before the one we wanted to move to the one after
			}
			else
			{
				curr = curr->next;
			}
		}
	}
	curr = *head;
	if (!flag)
	{
		printf("Frame doesn't exist.\n");
	}
	else //the function 
	{
		if (pos == 1) // if the user want to move a node to the head
		{
			x->next = *head; //point x (the node the user wants to move) to the head
			*head = x; //the new head is now x.
		}
		else
		{
			i = 1;
			while (curr && i != pos - 1)
			{
				curr = curr->next;
				i++;
			}
			x->next = curr->next;
			curr->next = x;
		}

	}

}

/*
The function changes the duration of a specified frame
Input: list head
Output: none
*/
void changeDuration(FrameNode** head)
{
	FrameNode* curr = *head;
	FrameNode* x = NULL;
	char fName[STR_SIZE] = { 0 };
	int found = FALSE;
	int newDuration = 1;

	printf("Which frame do you want to change? ");
	myFgets(fName, STR_SIZE);

	while (curr && !found)
	{
		if (!strcmp(curr->frame->name, fName))
		{
			found = TRUE;
			x = curr;
		}
		curr = curr->next;
	}
	while (!found) //check if existing frame
	{
		curr = *head;
		printf("Frame doesn't exist. Please try again: ");
		myFgets(fName, STR_SIZE);

		while (curr && !found)
		{
			if (!strcmp(curr->frame->name, fName))
			{
				found = TRUE;
				x = curr;
			}
			else
			{
				curr = curr->next;
			}

		}
	}
	printf("Please enter the new duration for the specified frame: ");
	scanf("%d", &newDuration);
	getchar();

	while (newDuration <= 0)
	{
		printf("Enter a positive duration: \n");
		scanf("%d", &newDuration);
		getchar();
	}
	x->frame->duration = newDuration;
}
/*
The function changes all the frames' duration to new specified duration
Input: the head of the list
Output: none
*/
void changeAllDurations(FrameNode** head)
{
	FrameNode* curr = *head;
	int newDuration = 0;
	printf("Enter new duration: ");
	scanf("%d", &newDuration);
	getchar();
	while (newDuration <= 0)
	{
		printf("Enter a positive duration: \n");
		scanf("%d", &newDuration);
		getchar();
	}
	while (curr)
	{
		curr->frame->duration = newDuration;
		curr = curr->next;
	}
}
/*
The function cleans everything (deletes the list)
Input: list head
Output: nono
*/
void cleanMemory(FrameNode** head)
{
	FrameNode* curr = *head;
	FrameNode* temp = NULL;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp->frame->name);
		free(temp->frame->path);
		free(temp->frame);
		free(temp);
	}
	*head = NULL;
}
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
			fprintf(saveFile, "%s %s %d| ", curr->frame->path, curr->frame->name, curr->frame->duration);
			curr = curr->next;
		}
	}
	fclose(saveFile);
}
void loadProject(FrameNode** head)
{
	char saveFile[PATH_SIZE] = { 0 };
	FILE* loadFrom = NULL;
	char* file = NULL;
	int i = 0;
	int j = 0;
	int k = 0;
	int tempNumber[TEMP_NUMBER_LENGTH] = {0 }; //WE CAN FILL WITH NEGATIVE NUMBER BECAUSE WE KNOW DURATION WILL NEVER BE NEGATIVE

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
			if (stage == 0)
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
			else if (stage == 1)
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
			{
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
			k = 0;
			stage = 0;
			temp = 0;

			for (i = 0; i < TEMP_NUMBER_LENGTH; i++)
			{
				tempNumber[i] = -1;
			}
		}
	}
	for (i = 0; i < numOfFrames; i++) //create frame node and free the unneeccessery stuff
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


