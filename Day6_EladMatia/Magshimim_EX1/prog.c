/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <string.h>

#define SIZE 30
#define NUM_OF_ANIMALS 2
typedef struct animal
{
	char kind[SIZE];
	char name[SIZE];
	int age;
}animal;

void myFgets(char str[], int n);
void printAnimal(animal animal);
int compare(animal a1, animal a2);
int main(void)
{
	// initialize the animals
	animal firstAnimal = { "", "", 0 };
	animal secondAnimal = { "","", 0 };
	animal animals[NUM_OF_ANIMALS] = {firstAnimal, secondAnimal};

	int i = 0;
	for (i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			printf("First Animal\n");
		}
		else
		{
			printf("Second Animal\n");
		}
		printf("Enter animal type: ");
		myFgets(animals[i].kind, SIZE);
		printf("Enter animal name: ");
		myFgets(animals[i].name, SIZE);
		printf("Enter animal age: ");
		scanf("%d", &animals[i].age);
		getchar();
	}
	printAnimal(animals[0]);
	printAnimal(animals[1]);
	if (compare(animals[0], animals[1]))
	{
		printf("Same Animal\n");
	}
	else
	{
		printf("Different Animals\n");
	}
	printf("sizeof(struct animal) = %d", sizeof(animal));
	getchar();
	return 0;
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
/*
The function prints an animal struct
Input: animal struct
Output: none
*/
void printAnimal(animal animal)
{
	printf("%s is a %s, %d years old\n", animal.name, animal.kind, animal.age);
}
/*
The function compared two animals to see if they are identical
Input: two animal structs
Output: 1 if they are identical, 0 othersize
*/
int compare(animal a1, animal a2)
{
	if (a1.age == a2.age && !strcmp(a1.name, a2.name) && !strcmp(a2.kind, a2.kind))
	{
		return 1;
	}
	return 0;
}