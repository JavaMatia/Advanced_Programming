/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50


typedef struct list {
	char** reasons;
	int numOfReasons;
}list;

char dilema[SIZE] = { 0 }; //global dilema


void menu(list* proList, list* conList);
void myFgets(char str[], int n);
void addToList(list* list);
void print(list* proList, list* conList);
void cleanMemory(list* list1, list* list2);

int main(void)
{

	//allocate 1 space for a reason for start
	list proList = { 0, 0 }; //allocate 1 space for a reason for start
	list conList = { 0, 0 };


	menu(&proList, &conList);
	getchar();
	return 0;
}
/*
The function prints the menu and call all the essential functions
Input: two lists structs
Output: None
*/
void menu(list* proList, list* conList)
{
	int choice = 0;
	printf("What is your dilema? ");
	myFgets(dilema, SIZE);
	while (choice != 4) 
	{
		printf("Choose option:\n1 - Add PRO reason\n2 - Add CON reason\n3 - Print reasons\n4 - Exit\n");
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			printf("Enter a reason to add to list PRO: ");
			addToList(proList);
			break;
		case 2:
			printf("Enter a reason to add to list CON: ");
			addToList(conList);
			break;
		case 3: 
			print(proList, conList);
		default:
			break;
		}
	}
	cleanMemory(proList, conList);
}
/*
This function adds a reason to the proList
Input: a pointer of list
Output: None
*/
void addToList(list* list)
{
	//first of all, if we want to add item to this list, we need to allocate + 1 space in the reasons array
	list->reasons = (char**)realloc(list->reasons, (list->numOfReasons + 1)*sizeof(char*));
	//alocate space for the actual string: 250 characters
	list->reasons[list->numOfReasons] = (char*)malloc(sizeof(char)*(SIZE * 5));

	myFgets(list->reasons[list->numOfReasons], SIZE * 5);

	//reallocate the space back:

	list->reasons[list->numOfReasons] = (char*)realloc(list->reasons[list->numOfReasons], sizeof(char)*(strlen(list->reasons[list->numOfReasons]) + 1));
	list->numOfReasons++;

}
/*
the functions prints the list
Input: two lists
Output: the reason list
*/
void print(list* proList, list* conList)
{
	int i = 0;
	printf("Your dilema: \n%s\n\n", dilema);
	printf("List PRO\n---------\n");
	for (i = 0; i < proList->numOfReasons; i++)
	{
		printf("%s\n", proList->reasons[i]);
	}
	printf("\n\nList CON\n---------\n");
	for (i = 0; i < conList->numOfReasons; i++)
	{
		printf("%s\n", conList->reasons[i]);
	}
	printf("\n");
}
/*
the function frees the memory so we won't get any memory leaks
Input: the two lists which where allocated during runtime
Output: None
*/
void cleanMemory(list* list1, list* list2)
{
	int i = 0;
	for (i = 0; i < list1->numOfReasons; i++)
	{
		free(list1->reasons[i]); //clear all the strings
	}
	free(list1->reasons); // clear the reasons itself

	for (i = 0; i < list2->numOfReasons; i++)
	{
		free(list2->reasons[i]); //clear all the strings
	}
	free(list2->reasons); // clear the reasons itself
	printf("Good luck!");
}
/*
the function takes a string as input
Input: string and its size
Output: String in the memory with no enter
*/
void myFgets(char str[], int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}

