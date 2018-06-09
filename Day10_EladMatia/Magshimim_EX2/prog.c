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
#define NUM_OF_FRIENDS 3
#define EXIT 7


typedef struct personNode {
	char name[SIZE];
	int age;
	struct personNode* next;
}personNode;

int listLength(personNode** head);
void printLine(personNode** head);
personNode* createPersonNode(char name[SIZE], int age);
void insertNode(personNode** head, personNode* node);
void deleteList(personNode** head);
void addToLine(personNode** head);
void removePerson(personNode** head);
void myFgets(char str[], int n);
void VIP(personNode** head);
void inLine(personNode** listHead);
void reverse(personNode** head);

int main(void)
{
	int choice = 0;
	personNode* listHead = NULL; //this is the head of the list.
	while (choice != EXIT)
	{
		printf("\nWelcome to MagshiParty Line Management Software!\nPlease enter your choice from the following options: \n");
		printf("1 - Print line\n");
		printf("2 - Add person to line\n");
		printf("3 - Remove person from line\n");
		printf("4 - VIP guest\n");
		printf("5 - Search in line\n");
		printf("6 - Reverse line\n");
		printf("7 - Exit\n");
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			printf("%d in line: \n", listLength(&listHead));
			printLine(&listHead);
			break;
		case 2:
			addToLine(&listHead);
			break;
		case 3:
			removePerson(&listHead);
			break;
		case 4:
			VIP(&listHead);
			break;
		case 5:
			inLine(&listHead);
			break;
		case 6:
			reverse(&listHead);
			break;
		default:
			break;
		}
	}
	printf("Goodbye!");
	deleteList(&listHead);
	getchar();
	return 0;
}
/*
The function prints a given list
Input: the list head
Output: prints the list
*/
void printLine(personNode** head)
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
The function insert a person to the line in Israeli fushion
Input: List head
Output: none
*/
void addToLine(personNode** head)
{
	char name[SIZE] = { 0 };
	personNode* curr = *head;
	int age = 0;
	personNode* newPerson = NULL;
	char friends[NUM_OF_FRIENDS][SIZE] = { 0 };
	int i = 0;
	int inserted = 0;

	printf("Enter name: ");
	myFgets(name, SIZE);
	printf("Enter age: ");
	scanf("%d", &age);
	getchar();
	newPerson = createPersonNode(name, age);
	printf("Enter name of 3 friends: \n");
	for (i = 0; i < NUM_OF_FRIENDS; i++)
	{
		printf("Friend %d: ", i + 1);
		myFgets(friends[i], SIZE); //file an array of friends' names
	}

	while (curr && !inserted)
	{

		if (!strcmp(curr->name, friends[0]) || !strcmp(curr->name, friends[1]) || !strcmp(curr->name, friends[2])) // is one of your friends 
		{
			// insert here.
			//if we had inserted a person, exit the loop
			newPerson->next = curr->next;
			curr->next = newPerson;
			inserted = 1; // exit the loop
		}
		else
		{
			curr = curr->next;
		}
	}
	if (!inserted) // if the person know no one
	{
		insertNode(head, newPerson);

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

void removePerson(personNode** head)
{
	char name[SIZE] = { 0 };
	personNode* temp = NULL;
	personNode* curr = *head;
	int done = 0;
	printf("Enter name to remove: ");
	myFgets(name, SIZE);
	if (curr) // if the list is not empty
	{
		if (!strcmp((*head)->name, name)) //check if we are deleting the first person in line
		{
			temp = *head;
			*head = (*head)->next;
			free(*head);
			done = 1;
		}
		else
		{
			while (curr->next && !done)
			{
				if (!strcmp(curr->next->name, name)) // we want to catch the node before the one we want to delete
				{
					temp = curr->next; // put aside the node to delete
					curr->next = temp->next; // link the node before it, to the node after it
					free(temp); // delete the node
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
/*
The function adds a guest to the front of the line because he is VIP
Input: the list head
Output: None
*/
void VIP(personNode** head)
{
	// we are updating our list's head
	char name[SIZE] = { 0 };
	int age = 0;
	personNode* newPerson = NULL;

	printf("VIP guest!\n");
	printf("Enter name: ");
	myFgets(name, SIZE);
	printf("Enter age: ");
	scanf("%d", &age);
	getchar();
	newPerson = createPersonNode(name, age);
	newPerson->next = *head;
	*head = newPerson;
}
/*
The function searches a name in the line
Input: the list head
Output: None
*/
void inLine(personNode** listHead)
{
	personNode* curr = *listHead;
	char name[SIZE] = { 0 };
	int exit = 0;
	printf("Print name to search: ");
	myFgets(name, SIZE);
	while (curr && !exit)
	{
		if (!strcmp(name, curr->name))
		{
			printf("%s found in line", name);
			exit = 1;
		}
		curr = curr->next;
	}
	if (!exit)
	{
		printf("%s not in line ", name);
	}
}
/*
The function reverses a list 
Input: the list head
Output: none
taken from: https://www.geeksforgeeks.org/reverse-a-linked-list/
*/
void reverse(personNode** head)
{
	personNode* prev = NULL;
	personNode* curr = *head;
	personNode* next = NULL;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}