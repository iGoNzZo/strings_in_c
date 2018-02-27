/* 8.23.c program to take user input and print words that start 
 * with 'b' 
 * Steven Gonzalez 009387092 Hw3
 */
#include <stdio.h>
#include <string.h>

//program definitions 
#define MAXWLENGTH 100

//variable declaration 
char line[MAXWLENGTH] = {'\0'};
char *word;

//main function 
void main()	{
	//prompt to get user input 
	printf("Type a word (exit to quit): ");
	fgets(line, MAXWLENGTH, stdin); // gts user input and sets it to input 
	
	//loop while line != 0
	while(strcmp(line, "exit\n")!= 0){
		if(line[0] == 'b')	{
		//if the word starts with 'b' print it 
			printf("\nWord starts with b: %s\n", line);
		}	// end if statement 
		
		//promt to get next user inputed word 
		printf("Type a word (exit to quit): ");
		fgets(line, MAXWLENGTH, stdin); // gets user input for line 
	}	//end while loop 
} // end main 
