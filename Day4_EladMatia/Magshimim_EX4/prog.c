/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE !FALSE
#define MAX 100
#define EXIT 5

int validInput(int number, int minValue, int maxValue);
void setGrades(int* gradesArray, int length);
void printMenu(int* gradesArray, int numOfGrades);
void calculateAverage(int* gradesArray, int length);
void changeGrade(int* gradesArray, int length);
int changeNumberOfGrades(int* gradesArray, int length);
void printArray(int* gradeArray, int length);

int main(void)
{
	int numOfGrades = 0;
	printf("Enter number of grades: ");
	scanf("%d", &numOfGrades);
	getchar();
	int* gradesArray = (int*)malloc(sizeof(int)*numOfGrades); //alocate space for the array
	setGrades(gradesArray, numOfGrades);
	printMenu(gradesArray, numOfGrades);
	free(gradesArray);
	getchar();
	return 0;
}
/*
The function check for valid input
Input: Number - the number to check. minValue - the minimum value number can be. maxValue - the maximum value number can be
Output: True if input is valid, false otherwise
*/
int validInput(int number, int minValue, int maxValue)
{
	if (number >= minValue && number <= maxValue)
	{
		return TRUE;
	}
	return FALSE;
}
/*
The function gets the initial grades
Input: The grades array and its length
Output: None
*/
void setGrades(int* gradesArray, int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		printf("Enter grade %d: ", i + 1);
		scanf("%d", &gradesArray[i]);
		getchar();
		while (!validInput(gradesArray[i], 0, MAX))
		{
			printf("Invalid grade. 0-100 only. Try again: ");
			scanf("%d", &gradesArray[i]);
			getchar();
		}
	}
}
/*
The function prints the menu and calls the functions
Input: Grades array and its length
Output: None
*/
void printMenu(int* gradesArray, int numOfGrades)
{
	int choice = 0;
	while (choice != EXIT) {

		printf("1 - Calculate average");
		printf("\n2 - Change a grade");
		printf("\n3 - Change number of grades");
		printf("\n4 - Print grades");
		printf("\n5 - Exit");
		printf("\nChoose option: ");
		scanf("%d", &choice);
		getchar();
		while (!validInput(choice, 1, EXIT))
		{
			printf("Invalid choice. Try again: ");
			scanf("%d", &choice);
			getchar();
		}
		switch (choice)
		{
		case 1:
			calculateAverage(gradesArray, numOfGrades);
			break;
		case 2:
			changeGrade(gradesArray, numOfGrades);
			break;
		case 3:
			numOfGrades = changeNumberOfGrades(gradesArray, numOfGrades);
			break;
		case 4:
			printArray(gradesArray, numOfGrades);
			break;
		default:
			break;
		}
	}

}
/*
The function calculates the average grade
Input: Grades array and its length
Output: None
*/
void calculateAverage(int* gradesArray, int length) //the automatic system says average should be 100 while it shouldn't
{
	float sum = 0;
	int i = 0;
	for (i = 0; i < length; i++)
	{
		sum += gradesArray[i];
	}
	printf("The grades average is: %.2f\n", sum / length);
}
/*
The function updates a specific grade
Input: The grades array and its length
Output: None
*/
void changeGrade(int* gradesArray, int length)
{
	int grade = 0;
	printf("Which grade would you like to change? %d-%d: ", 1, length);
	scanf("%d", &grade);
	getchar();
	while (!validInput(grade, 1, EXIT)) // validate choice
	{
		printf("Invalid choice. Try again: ");
		scanf("%d", &grade);
		getchar();
	}
	printf("Enter new grade: ");
	scanf("%d", &gradesArray[grade - 1]);
	getchar();
	while (!validInput(gradesArray[grade - 1], 0, MAX))
	{
		printf("Invalid grade. 0-100 only. Try again: ");
		scanf("%d", &gradesArray[grade - 1]);
		getchar();
	}

}
/*
The function making the grades array bigger by the user choice. 
Input: Grades array and its length
Output: The new length of the array
*/
int changeNumberOfGrades(int* gradesArray, int length)
{
	int newGrades = 0;
	printf("Enter new number of grades: ");
	scanf("%d", &newGrades);
	getchar();
	gradesArray = (int*)realloc(gradesArray, sizeof(int)*newGrades); //reallocate new space for the new array.
	
	while (length < newGrades)
	{
		printf("Enter grade %d: ", length+1);
		scanf("%d", &gradesArray[length]);
		getchar();
		while (!validInput(gradesArray[length], 0, MAX)) //check input
		{
			printf("Invalid grade. 0-100 only. Try again: \n");
			scanf("%d", &gradesArray[length]);
			getchar();
		}
		length++;
	}
	if (newGrades < length) // if the user wants to change the number of grades to something smaller
	{
		length = newGrades;
	}
	return length; //return the new length of the array!
}
/*
The function prints an array
Input: Grades array and its length
Output: none
*/
void printArray(int* gradeArray, int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		printf("%d ", gradeArray[i]);
	}
	printf("\n");
}