/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 250
#define EXIT 4

int getLine(char* file, char* find);
void myFgets(char str[], int n);

int main(int argc, char** argv)
{	
	int choice = 0;
	char* value = (char*)malloc(LENGTH*sizeof(char));
	int response = 0;

	if (argc < 2)
	{
		printf("Usage: <program_name>.exe <csv file path>");
		return 1;
	}
	else
	{
		// lets check if we can open the file
		FILE* check = fopen(argv[1], "r");
		if (check == NULL)
		{
			printf("Error openning file");
			fclose(check);
			return 1;
		}
		fclose(check);
	}

	do
	{
		printf("1 - Search a term in the document\n2 - change a value in the document.\n3 - copy a value from one place to another\n4 - Exit ");
		scanf("%d", &choice);
		getchar();
		while (choice > EXIT || choice < 1)
		{
			printf("Try again");
			printf("1 - Search a term in the document\n2 - change a value in the document.\n3 - copy a value from one place to another\n4 - Exit ");
			scanf("%d", &choice);
			getchar();
		}
		if (choice == 1)
		{
			printf("Enter value to seach: ");
			myFgets(value, LENGTH);
			response = getLine(argv[1], value);
			if (!response)
			{
				printf("Value wasn't found\n");
			}
			else
			{
				printf("Value was found on row %d\n", response);
			}
		}
		else if (choice == EXIT)
		{
			printf("Goodbye!");
		}
	} while (choice != EXIT);
	free(value);
	return 0;
}
/*
The function seaches for the value in the csv. returns the value's row or 0 if it couldn't find anything
Input: the csv file path, and the string to find
Ouput: 0 if the value wasn't found, the row otherwise
*/
int getLine(char* file, char* find)
{
	FILE* csv = fopen(file, "r");
	int i = 0;
	int row = 1;
	int hasComa = 0;
	int arrayIndex = 0;
	int character = 0;
	int found = 0;

	fseek(csv, 0, SEEK_END);
	int length = ftell(csv) * sizeof(char);
	fseek(csv, 0, SEEK_SET);

	char* tempValue = (char*)malloc((length*(sizeof(char)) + 1));

	for (int j = 0; j<length; j++)
	{
		hasComa = 0;
		i = 0;
		do
		{
			character = fgetc(csv);
			if ((char)(character != ',') && ((char)character != '\n') && character != EOF)
			{
				tempValue[i] = (char)character; //assign the value 
			}
			else
			{
				hasComa = 1; //we found a coma, meaning the word has ended
				//convert tempValue to a string:
				tempValue[i] = 0;

			}

			i++;

		} while (character != EOF && !hasComa); //go over until you see a coma or a newline

		if (!strcmp(tempValue, find))
		{
			found = 1; //just in case
			return row;
		}

		if ((char)character == '\n') //if the character is newline, we need to ++ the row!
		{
			row++;
		}
		
	}
	if (!found)
	{
		return 0;
	}
	free(tempValue);
	fclose(csv);
}

//Gets a string
void myFgets(char str[], int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}