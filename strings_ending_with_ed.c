/* 8.24.c program to check if given words end in "ed"
 * Steven Gonzalez 009387092 Hw3
 */
#include <stdio.h>
#include <string.h>

//program definitions 
#define MAXWLENGTH 100

//variable declarations 
char line[MAXWLENGTH] = {'\0'};
char *word;

//main function 
void main()	{
	//prompt to get user input 
	printf("Type a word (exit to quit): ");
	fgets(line, MAXWLENGTH, stdin); // gets user input and puts it in line
	
	//loop while line != "exit"
	while(strcmp(line, "exit\n")!= 0)	{
		//checks if last indexes are "ed"
		if(strcmp(line + (strlen(line)-3), "ed\n") == 0)	{
		//print word if last indexs are "ed"
			printf("Word ends with ed: %s\n", line);
		}	// end if statement 
		
		//prompt to get next user input 
		printf("Type a word (exit to quit): ");
		fgets(line, MAXWLENGTH, stdin); // gets user input and puts it in line
	}	// end while loop 
} // end main function 
