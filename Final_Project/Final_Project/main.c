#include <stdio.h>
#include <opencv2\highgui\highgui_c.h>
#include "linkedList.h"
#include "view.h"


FrameNode* firstFrame = NULL; //make the head of the gif global because we gonna use it in almost every function

void menu(void);
int main(void)
{
	menu();
	getchar();
	return 0;
}

void menu(void)
{
	int choice = -1;
	printf("Welcome to my GIF maker! What would you like to do?\n");
	while (choice > 1 || choice < 0)
	{
		printf("  [0] Create new project \n");
		printf("  [1] Load existing project (coming soon) \n");
		scanf("%d", &choice);
		getchar();
	}

	if (choice)
	{
		//loadProject();
		//in both situations we get to the same menu + add a printf telling the user that the project was successfully loaded
	}
	else
	{
		printf("Working on a new project. \n\n");
	}
	choice = -1; //reset choice
	while (choice)
	{
		printf("What would you like to do?\n");
		printf("  [0] Exit \n");
		printf("  [1] Add new frame \n");
		printf("  [2] Remove frame \n");
		printf("  [6] List frames \n");
		printf("  [7] Play GIF! \n");
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			printf("***Creating new frame***\n");
			createFrameNode(&firstFrame);
			printf("Frame added successfully!\n\n");
			break;
		case 2:
			printf("***Removing frame***\n");
			removeFrame(&firstFrame);
			break;
		case 3:
			changeFramePosition(&firstFrame);
			break;
		case 6:
   			printList(&firstFrame);
			break;
		case 7:
			play(firstFrame);
			break;

		default:
			break;
		}
	}
	//TODO: free all the allocated memory
}