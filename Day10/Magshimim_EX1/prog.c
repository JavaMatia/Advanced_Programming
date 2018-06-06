/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <string.h>

#define SIZE 20

personNode* createPersonNode(char name[SIZE], int age);

typedef struct personNode {
	char name[SIZE];
	int age; 
	personNode* next;
}personNode;

int main(void)
{

	
	getchar();
	return 0;
}
/*
The function creates new person node.
Input: name of the person and his age
Output: the new person struct
*/
personNode* createPersonNode(char name[SIZE], int age)
{
	personNode* newPerson = (personNode*)malloc(sizeof(personNode));
	newPerson->age = age;
	strncpy(newPerson->name, name, SIZE);
	newPerson->next = NULL;
	return newPerson;
}


void insertNode(personNode** head, personNode* node)
{
	personNode* curr = *head; //create a temporary node that old the head of the list. we dont want it to change in reality
	if (!(*head))
	{
		*head = node;
	}
}