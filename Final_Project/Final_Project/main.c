#include <stdio.h>
#include <opencv2\highgui\highgui_c.h>
#include "linkedList.h"
#include "view.h"


FrameNode* firstFrame = NULL; //make the head of the gif global because we gonna use it in almost every function

void menu(void);
int main(void)
{
	menu();
	cleanMemory(&firstFrame);
	printf("Bye!");
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
		printf("  [3] Move frame \n");
		printf("  [4] Change duration \n");
		printf("  [5] Change duration in all frames \n");
		printf("  [6] List frames \n");
		printf("  [7] Play GIF! \n");
		printf("  [8] Save project \n");
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
			printf("***Frame removed successfully!***\n");
			break;
		case 3:
			printf("***Moving frame***\n");
			changeFramePosition(&firstFrame);
			printf("***Frame moved successfully!***\n");
			break;
		case 4:
			printf("***Changing duration***\n");
			changeDuration(&firstFrame);
			printf("***Frame duration changed successfully!***\n");
			break;
		case 5:
			printf("***Changing duration for all frames\n***");
			changeAllDurations(&firstFrame);
			printf("***All frame duration have been changed successfully ***");
			break;
		case 6:
   			printList(&firstFrame);
			break;
		case 7:
			printf("***Playing video***\n");
			play(firstFrame);
			break;
		case 8:
			saveProject(&firstFrame);
			break;
		default:
			break;
		}
	}
}