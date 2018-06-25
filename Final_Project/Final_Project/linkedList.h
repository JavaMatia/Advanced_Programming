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
//function declerations:

void createFrameNode(FrameNode** head);
void printList(FrameNode** head);
void removeFrame(FrameNode** head);
void changeFramePosition(FrameNode** head);
void changeDuration(FrameNode** head);
void changeAllDurations(FrameNode** head);
void cleanMemory(FrameNode** head);
void saveProject(FrameNode** head);
void loadProject(FrameNode** head);
#endif
