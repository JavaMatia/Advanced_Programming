/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20

typedef struct personNode {
	char name[SIZE];
	int age; 
	struct personNode* next;
}personNode;

personNode* createPersonNode(char name[SIZE], int age);
void printList(personNode** head);
void insertNode(personNode** head, personNode* node);
void deleteList(personNode** head);
void myFgets(char str[], int n);
int listLength(personNode** head);
personNode* copyList(personNode** head);

int main(void)
{
	int numOfPeople = 0;
	int i = 0;
	int age = 0;
	char name[SIZE] = { 0 };
	personNode* listHead = NULL; // always the head of the list. has to keep it updated

	printf("How many people are you? ");
	scanf("%d", &numOfPeople);
	getchar();

	for (i = 0; i < numOfPeople; i++)
	{
		personNode* newPerson = NULL;
		printf("Enter name: ");
		myFgets(name, SIZE);
		printf("Enter age: ");
		scanf("%d", &age);
		getchar();
		newPerson = createPersonNode(name, age);
		insertNode(&listHead, newPerson);
	}
	printList(&listHead);
	printf("List length: %d\n", listLength(&listHead));
	personNode* copy = copyList(&listHead);
	printList(&copy);
	deleteList(&listHead);
	deleteList(&copy);
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

/*
Insert a new node to the end of the list
Input: a pointer to a pointer of the head of the node, and a new node to add
Output: add a new node to the list
*/
void insertNode(personNode** head, personNode* node)
{
	personNode* curr = *head; //create a temporary node that old the head of the list. we dont want it to change in reality
	if (!(*head))
	{
		*head = node;
	}
	else
	{
		while (curr->next)
		{
			curr = curr->next; //go to the end of the list, then append the new node
		}
		curr->next = node;
	}
}
//Gets a string
void myFgets(char str[], int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}
/*
Delete the given list
Input: the list's head
output: set the head of the list to null
*/
void deleteList(personNode** head)
{
	personNode* temp = NULL;
	personNode* curr = *head;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*head = NULL;
}
/*
The function prints a given list
Input: the list head
Output: prints the list
*/
void printList(personNode** head)
{
	personNode* curr = *head;
	while (curr)
	{
		printf("Name: %s, Age: %d\n", curr->name, curr->age);
		curr = curr->next;
	}
}
/*
The function returns the length of given list.
Input: the list head
Output: the list length
*/
int listLength(personNode** head)
{
	int length = 0;
	personNode* curr = *head;
	if (!curr)
	{
		length = 0;
	}
	else
	{
		length = 1 + listLength(&(curr->next));
	}
	return length;
}
/*
The function creates a new copy of a given list
Input: the head of list you wish to copy
Output: a pointer to the head of the new copy
*/
personNode* copyList(personNode** head)
{
	personNode* curr = *head;
	personNode* newList = NULL;
	while (curr)
	{
		personNode* newPersonCopy = createPersonNode(curr->name, curr->age);
		insertNode(&newList, newPersonCopy);
		curr = curr->next;
	}
	return newList;
}