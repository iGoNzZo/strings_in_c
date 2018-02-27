/* 8.37.c program to make ingredient substitution for recipies
 * Steven Gonzalez 009387092 Hw3
 */
#include <stdio.h>
#include <string.h>

//variable declarations 
char *ingredients[12] = {"eggs", "milk", "sour cream", "lemon juice", 
					 	"sugar", "butter", "flower", "mayonayse", 
					 	"cooking oil", "bread", "salt", "tortilla"};		 	
char *cholesterol[12] = {"egg whites", "soy milk", "yogert", "vineger", 
						"honey", "margerine", "rye", "cottage cheese", 
						"apple sauce", "whole grain", "sea salt", "rye"};
char *bloodPressure[12] = {"egg whites", "almond milk", "cottage cheese", 
						"white wine", "vanilla", "apple sauce", 
						"rice flour", "cottage cheese", "vineger oil", 
						"whole grain", "sea salt", "weat"};
char *weightLoss[12] = {"egg whites", "soy milk", "greek yogert", "lime juice",
					   "aguave nector", "yogert", "mayo/yogert", "olive oil", 
					   "whole grain", "sea salt", "corn"};
char *heartDisease[12] = {"egg whites", "soy milk", "yogert", "vineger", 
						"honey", "margerine", "rye", "cottage cheese", 
						"apple sauce", "whole grain", "sea salt", "rye"};
char *measures[12] = {"1/4 cups", "1/6 cups", "1/5 cups", "1/2 cups", "1/2 cups", "1 cups",
				 "3/2 cups", "5/2 cups", "1 cups", "1/2 cups", "3/4 cups", "2 cups"};
char *badMeasures[12] = {"1/2 cups", "1/4 cups", "3/5 cups", "1 cups", "2 cups", "3 cups",
				 "3/2 cups", "1 cups", "3 cups", "3/2 cups", "1/6 cups", "7/2 cups"};		 
char *given[5] = {'\0'};
char *givenMeasurements[5] = {'\0'};


// function declarations 
void cholest();
void bPressure();
void wLoss();
void hDisease();

//main function 
void main()	{
	//array of functions declaration 
	void(*f[4])(double) = {cholest, bPressure, wLoss, hDisease};
	int option; // variable to hold option 
	
	//user prompts 
	printf("\nPick a substitution option \n"
		  "\t1 - Cholesterol\n"
		  "\t2 - High Blood Pressure\n"
		  "\t3 - Weight Loss\n"
		  "\t4 - Heart Disease\n"
		  "\t5 - exit\n");	
	scanf("%d", &option); // read in user option 
	option--; // decrement counter for accurate indexing 
	
	//loop while option != 4
	while(option != 4)	{
	// local variable declarations 
		char input[500];
		char *words;
		
		//user prompts to get 5 ingredients 
  		printf("\n\tEnter 5 ingredients seperated "
  			   "by a comma (,), no spaces-Example: \n");
		printf("\t\teggs,milk,flour,mayonase,butter\n");
		fgets(input, 500, stdin); // read in ingreadients 
		scanf("%s", input);	 // now scan the input 
		
		//set words pointer to token
		words = strtok(input, ",");
		
		int i = 0;
		//loop while pointer does not point to nothing 
		while(words != NULL)	{
			//printf("%s\n", words);
			given[i] = words; // set token to index i of given array 
			words = strtok(NULL, ","); // get next token of user input 
			i++; // increment counter for indexing 
		}
		// call to proper function of function array 
		(*f[option])(option);
		
		//user prompts to get next option 
		printf("\nPick a substitution option \n"
		  "\t1 - Cholesterol\n"
		  "\t2 - High Blood Pressure\n"
		  "\t3 - Weight Loss\n"
		  "\t4 - Heart Disease\n"
		  "\t5 - exit\n");	
		scanf("%d", &option); // read in the option 
		option--; // decrement counter for accurate indexing 
	}
	//end program 
	printf("Goodbye!\n");
} // end main function 

//cholest function 
void cholest()	{
	// local variable declarations 
	char input[500] = {'\0'};
	char *measurements;
	int i,j; // variable for loops 
	
	// user prompt to get measurements 
	printf("\tEnter measurements for given ingredients, "
		"seperated by a comma (,), Example:\n"
		"\t\t1/4,1,2/3,2,3\n");
	fgets(input, 500, stdin); // read user input 
	scanf("%s", input); // scan user input 
	
	//measurements = token of input 
	measurements = strtok(input, ",");
	
	i = 0;
	//loop while measuments pointer does not point to  null
	while(measurements != NULL)	{
		//printf("%s\n", measurements);
		givenMeasurements[i] = measurements; // set given ingredients 
		measurements = strtok(NULL, ","); // take next token of the given string 
		i++; // increment counter to keep track of array indexing
	} // end while loop 
		
	//make comparisons between given and option standards 
	for(i = 0; i < 5; i++)	{
		for(j = 0; j < 12; j++)	{
		//check for bad ingredients 
			if(strcmp(given[i], ingredients[j]) == 0) {
			// make suggestions for bad ingredients 
				printf("you should substitute: "
				"%s cups %s with %s cups %s \n",givenMeasurements[i], given[i], measures[j], cholesterol[j]);
			} // end if statemenet 
		} // end inner for loop
	} // end outter for loop
} // end cholest function 


void bPressure()	{
	// local variable declarations 
	char input[500] = {'\0'};
	char *measurements;
	int i,j; // variable for loops 
	
	// user prompt to get measurements 
	printf("\tEnter measurements for given ingredients, "
		"seperated by a comma (,), Example:\n"
		"\t\t1/4,1,2/3,2,3\n");
	fgets(input, 500, stdin); // read user input 
	scanf("%s", input); // scan user input 
	
	//measurements = token of input 
	measurements = strtok(input, ",");
	
	i = 0;
	//loop while measuments pointer does not point to  null
	while(measurements != NULL)	{
		//printf("%s\n", measurements);
		givenMeasurements[i] = measurements; // set given ingredients 
		measurements = strtok(NULL, ","); // take next token of the given string 
		i++; // increment counter to keep track of array indexing
	} // end while loop 
		
	//make comparisons between given and option standards 
	for(i = 0; i < 5; i++)	{
		for(j = 0; j < 12; j++)	{
		//check for bad ingredients 
			if(strcmp(given[i], ingredients[j]) == 0) {
			// make suggestions for bad ingredients 
				printf("you should substitute: "
				"%s cups %s with %s cups %s \n",givenMeasurements[i], given[i], measures[j], bloodPressure[j]);
			} // end if statemenet 
		} // end inner for loop
	} // end outter for loop
} // end bPressure function 

void wLoss()	{
	// local variable declarations 
	char input[500] = {'\0'};
	char *measurements;
	int i,j; // variable for loops 
	
	// user prompt to get measurements 
	printf("\tEnter measurements for given ingredients, "
		"seperated by a comma (,), Example:\n"
		"\t\t1/4,1,2/3,2,3\n");
	fgets(input, 500, stdin); // read user input 
	scanf("%s", input); // scan user input 
	
	//measurements = token of input 
	measurements = strtok(input, ",");
	
	i = 0;
	//loop while measuments pointer does not point to  null
	while(measurements != NULL)	{
		//printf("%s\n", measurements);
		givenMeasurements[i] = measurements; // set given ingredients 
		measurements = strtok(NULL, ","); // take next token of the given string 
		i++; // increment counter to keep track of array indexing
	} // end while loop 
		
	//make comparisons between given and option standards 
	for(i = 0; i < 5; i++)	{
		for(j = 0; j < 12; j++)	{
		//check for bad ingredients 
			if(strcmp(given[i], ingredients[j]) == 0) {
			// make suggestions for bad ingredients 
				printf("you should substitute: "
				"%s cups %s with %s cups %s \n",givenMeasurements[i], given[i], measures[j], weightLoss[j]);
			} // end if statemenet 
		} // end inner for loop
	} // end outter for loop
} // end wLoss function 

void hDisease()	{
	// local variable declarations 
	char input[500] = {'\0'};
	char *measurements;
	int i,j; // variable for loops 
	
	// user prompt to get measurements 
	printf("\tEnter measurements for given ingredients, "
		"seperated by a comma (,), Example:\n"
		"\t\t1/4,1,2/3,2,3\n");
	fgets(input, 500, stdin); // read user input 
	scanf("%s", input); // scan user input 
	
	//measurements = token of input 
	measurements = strtok(input, ",");
	
	i = 0;
	//loop while measuments pointer does not point to  null
	while(measurements != NULL)	{
		//printf("%s\n", measurements);
		givenMeasurements[i] = measurements; // set given ingredients 
		measurements = strtok(NULL, ","); // take next token of the given string 
		i++; // increment counter to keep track of array indexing
	} // end while loop 
		
	//make comparisons between given and option standards 
	for(i = 0; i < 5; i++)	{
		for(j = 0; j < 12; j++)	{
		//check for bad ingredients 
			if(strcmp(given[i], ingredients[j]) == 0) {
			// make suggestions for bad ingredients 
				printf("you should substitute: "
				"%s cups %s with %s cups %s \n",givenMeasurements[i], given[i], measures[j], heartDisease[j]);
			} // end if statemenet 
		} // end inner for loop
	} // end outter for loop
} // end hDisease function 


