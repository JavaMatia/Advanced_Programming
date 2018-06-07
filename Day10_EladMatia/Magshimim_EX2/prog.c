/*********************************
* Class: MAGSHIMIM C2			 *
* Week 10              			 *
* Class Example - Linked List	 *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 20

typedef struct SongNode
{
	char name[STR_LEN];
	char artist[STR_LEN];
	int duration;
	struct SongNode* next;
}SongNode;

SongNode* createSong(char name[], char artist[], int duration);
void printList(SongNode* head);
void insertAtEnd(SongNode** head, SongNode* newNode);
void deleteNode(SongNode** head, char* name);
void freeList(SongNode** head);
void freeListRecursive(SongNode** head);

int main(void)
{
	SongNode* newHead = NULL;
	SongNode* first = NULL;
	SongNode* second = NULL;
	SongNode* third = NULL;


	first = createSong("Etze li hashuka", "Shefita", 123);
	second = createSong("Sara", "Bob Dylan", 327);
	third = createSong("Tziona", "Nisim Gareme", 283);

	// testing that we can send an empty list
	insertAtEnd(&newHead, first);
	insertAtEnd(&newHead, second);
	insertAtEnd(&newHead, third);

	printList(newHead);

	// deleting first node
	deleteNode(&newHead, "Etze li hashuka");

	printList(newHead);

	freeList(&newHead);

	//freeListRecursive(&newHead);

	getchar();
	return 0;
}


/**
Function will create a song
input:
song name, artist name, and its duration
output:
the song updated with correct information
*/
SongNode* createSong(char name[], char artist[], int duration)
{
	SongNode* newSong = (SongNode*)malloc(sizeof(SongNode));

	strncpy(newSong->name, name, STR_LEN);
	strncpy(newSong->artist, artist, STR_LEN);
	newSong->duration = duration;
	newSong->next = NULL;

	return newSong;
}


/**
Function will print a list of songs
input: the list (the first song)
output:
none
*/
void printList(SongNode* head)
{
	SongNode* curr = head;
	printf("Playlist\n");
	printf("--------\n");
	while (curr) // when curr == NULL, that is the end of the list, and loop will end (NULL is false)
	{
		printf("%s - %s (%d sec)\n", curr->artist, curr->name, curr->duration);
		curr = curr->next;
	}
	printf("\n");
}


/**
Function will add a song to the playlist
input:
firstNode - the first node of the playlist
newNode - the new song to add to the playlist
output:
none
*/
void insertAtEnd(SongNode** head, SongNode* newNode)
{
	SongNode* curr = *head;
	if (!*head) // empty list!
	{
		*head = newNode;
	}
	else
	{
		while (curr->next) // while the next is NOT NULL (when next is NULL - that is the last node)
		{
			curr = curr->next;
		}

		curr->next = newNode;
		newNode->next = NULL;
	}
}

/**
Function will delete a specific song from a list of songs
input:
the list (the first song), the song to delete
output:
none
*/
void deleteNode(SongNode** head, char* name)
{
	SongNode* curr = *head;
	SongNode* temp = NULL;

	// if the list is not empty (if list is empty - nothing to delete!)
	if (*head)
	{
		// the first node should be deleted?
		if (0 == strcmp((*head)->name, name))
		{
			*head = (*head)->next;
			free(curr);
		}
		else
		{
			while (curr->next)
			{
				if ((0 == strcmp(curr->next->name, name))) // waiting to be on the node BEFORE the one we want to delete
				{
					temp = curr->next; // put aside the node to delete
					curr->next = temp->next; // link the node before it, to the node after it
					free(temp); // delete the node
				}
				else
				{
					curr = curr->next;
				}
			}
		}
	}
}

/**
Function will free all memory of a list of songs
input:
a list of songs
output:
none
*/
void freeList(SongNode** head)
{
	SongNode* temp = NULL;
	SongNode* curr = *head;
	while (curr)
	{
		temp = curr;
		curr = (curr)->next;
		free(temp);
	}

	*head = NULL;
}

/**
Function will free all memory of a list of songs - RECURSIVELY!
input:
a list of songs
output:
none
*/
void freeListRecursive(SongNode** head)
{
	if (*head != NULL) // if list not empty
	{
		if ((*head)->next != NULL) // end condition
		{
			freeListRecursive(&((*head)->next));
		}

		free(*head);
	}
}