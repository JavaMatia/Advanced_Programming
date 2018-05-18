/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void data(char* file, char* find);
int main(void)
{
	char* a = "C:\\Users\\eladm\\Downloads\\example.csv";
	char* i = "a";
	//Write your code here...
	data(a, i);
	getchar();
	return 0;
}
void data(char* file, char* find)
{
	FILE* csv = fopen(file, "r");
	char* arr = 0;
	int i = 0;
	int j = 0;
	int row = 1;
	int hasComa = 0;
	int arrayIndex = 0;


	//get the length of the file
	fseek(csv, 0, SEEK_END);
	int length = ftell(csv) * sizeof(char);
	arr = (char*)malloc(length);
	fseek(csv, 0, SEEK_SET); //GO BACK

	char* tempValue = (char*)malloc(length);
	for (i = 0; i < length; i++)
	{
		arr[i] = fgetc(csv);
		printf("%c", arr[i]);
	}
	// use do.... while for the length. fgetc returns char
	for (i = 0; i < length-1; i++)
	{
		hasComa = 0;
		if ((arr[arrayIndex] != "\n")) // If the character is not newline
		{
			for (j = 0; j < length && !hasComa; j++) //go over until you see a coma or a newline

			{
				if ((arr[arrayIndex] != ",") && (arr[arrayIndex] != "\n"))
				{
					printf("%c", arr[arrayIndex]);
					tempValue[j] = arr[arrayIndex]; //assign the value from the array
					arrayIndex++;
				}
				else
				{
					hasComa = 1; //we found a coma, meaning the word has ended

				}
			}
			if (strcmp(tempValue, find))
			{
				printf("Yes!, %d", row);
			}
			else
			{
				row++;
			
			}
		tempValue = 0;
		}
		else
		{
			tempValue = 0;
		}
	}













	free(tempValue);
	free(arr);
	fclose(csv);
}
