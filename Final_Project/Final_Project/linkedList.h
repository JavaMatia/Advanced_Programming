#ifndef LINKEDLISTH
#define LINKEDLISTH

#define FALSE 0
#define TRUE !FALSE
#define STR_SIZE 25
#define PATH_SIZE 256
#define TEMP_NUMBER_LENGTH 100

// Frame struct
typedef struct Frame
{
	char*		name;
	unsigned int	duration;
	char*		path;  
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;

//includes:
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//function declerations:

void createFrameNode(FrameNode** head);
void printList(FrameNode** head);
void removeFrame(FrameNode** head);
void changeFramePosition(FrameNode** head);
void changeDuration(FrameNode** head);
void changeAllDurations(FrameNode** head);
void cleanMemory(FrameNode** head);
void myFgets(char str[], int n);
Frame* createFrame(char fName[STR_SIZE], char path[PATH_SIZE], int duration);
void insertNode(FrameNode** head, FrameNode* node);
int listLength(FrameNode** head);
#endif
