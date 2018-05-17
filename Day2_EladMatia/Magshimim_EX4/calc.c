/*********************************
* Class: MAGSHIMIM C1			 *
* Week 2           				 *
**********************************/

#include <stdlib.h>
#include <stdio.h>

/*
The program gets two numbers and a choice of a math operation and performs it (if possible)
Input: None
Output: The program returns 0 upon successful completion of its running
*/
int main(void)
{
	// variables definition
	int num1 = 0, num2 =0;// thats awosome! 
	unsigned int choice = 0;
	//pointers
	int* pNum1 = &num1;
	int* pNum2 = &num2;
	unsigned int* pChoice = &choice;
	//getting numbers from user
	printf("please enter the first number (a): ");
	scanf("%d", pNum1);
	printf("please enter the second number (b): ");
	scanf("%d", pNum2);

	//printing menu
	printf("\nWelcome to the Magashimim Calculator!");
	printf("\nPlease choose the math operation:");
	printf("\n1.	adding a+b");
	printf("\n2.	subtracting a-b");
	printf("\n3.	multiplying a*b");
	printf("\n4.	dividing a/b");

	//getting choice from user
	printf("\nYour choice:");
	scanf("%d", pChoice);

	printf("\n\n");
	
	//acting according to choice
	switch (choice)
	{
		case 1: //adding
			//printf("%d + %d = %d\n", num1, num2, num1 + num2);
			printf("%d + %d = %d\n", *pNum1, *pNum2, *pNum1 + *pNum2); 
			break;
		case 2: //subtracting
			printf("%d - %d = %d\n", *pNum1, *pNum2, *pNum1 - *pNum2);
			break;
		case 3: //multiplying
			printf("%d * %d = %d\n", *pNum1, *pNum2, *pNum1**pNum2);
			break;
		case 4: //dividing
			if (*pNum2 == 0) //check for division by zero
			{
				printf("can't divide by zero!!!\n");
			}
			else
			{
				printf("%d / %d = %.2f", *pNum1, *pNum2, (float)*pNum1 / *pNum2); //casting, because we will get fructions
			}
			break;
		default: //if the user didn't choose between 1-4
			printf("choice is not valid\n");
	}
	getchar();
	getchar();
	return 0;
} 