/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <string.h>

#define SIZE 20

personNode* createPersonNode(char name[], int age);
void insertNode(personNode** head, personNode* node);
void deleteList(personNode** head);
void myFgets(char str[], int n);

typedef struct personNode {
	char name[SIZE];
	int age; 
	personNode* next;
}personNode;

int main(void)
{
	int numOfPeople = 0;
	int i = 0;
	int age = 0;
	char name[SIZE] = { 0 };
	personNode* listHead = NULL; // always the head of the list. has to keep it updated

	printf("How many people are you?");
	scanf("%d", &numOfPeople);

	for (i = 0; i < numOfPeople; i++)
	{
		personNode* newPerson = NULL;
		printf("What is the name of person %d?", i+1);
		myFgets(name, SIZE);
		printf("What is the age of person %d?", i+1);
		newPerson = createPersonNode(name, age);
		insertNode(&listHead, newPerson);
	}
	deleteList(listHead);
	getchar();
	return 0;
}
/*
The function creates new person node.
Input: name of the person and his age
Output: the new person struct
*/
personNode* createPersonNode(char name[], int age)
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