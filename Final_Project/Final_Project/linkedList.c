#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedList.h"

void myFgets(char str[], int n);
Frame* createFrame(FrameNode** head);
void insertNode(FrameNode** head, FrameNode* node);


/*
The function create and returns a Frame struct. It also checks if the path entered is invalid.
Input: list head to run duplicate name check
Output: the new Frame struct (not FrameNode)
*/
Frame* createFrame(FrameNode** head)
{
	//variables 
	Frame* newFrame = (Frame*)malloc(sizeof(Frame));
	FILE* check = NULL;
	FrameNode* curr = *head;
	char fName[STR_SIZE] = { 0 };
	char path[PATH_SIZE] = { 0 };
	int duration = 0;

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

	printf("Enter frame duration in milliseconds: ");
	scanf("%d", &duration);
	getchar();

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
	Frame* newFrame = createFrame(head);
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
					curr->next = temp->next; // link the node before it, to the node after it
					free(temp->frame->name); // delete the node
					free(temp->frame->path);
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
		printf("%s removed from line\n", name);
	}
	else
	{
		printf("%s not in line\n", name);
	}

}