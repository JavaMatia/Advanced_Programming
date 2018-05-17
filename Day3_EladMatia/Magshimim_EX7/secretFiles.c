#include <stdio.h>
#include <string.h>

#define PASSWORD "maGshimim2017"
#define STR_LEN 16
#define FALSE 0
#define TRUE !FALSE

int main(void)
{
	int pass = FALSE;
    char buff[STR_LEN] = { 0 };

    printf("Enter the password: ");
    fgets(buff, STR_LEN, stdin);//if we use fgets, we have to specify the length of the string. with scanf, it just fill the memory with the required space.
					//after that, the password is partialy correct.
	*(buff + (strlen(buff) - 1)) = 0; // remove the enter
    if(strcmp(buff, PASSWORD)) // if the buffer is bigger than it should be, but the first 16 will be correct, so we will be able to access the file. we need to use fgets
    {
        printf ("Wrong Password \n");
    }
    else
    {
        printf ("Correct Password \n");
        pass = TRUE;
    }

    if(pass)
    {
        printf ("Access given to the secret files \n");
    }
	
	getchar();
    return 0;
}
