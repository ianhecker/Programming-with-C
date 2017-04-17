/*
* Ian Hecker
* CSCI112, Lab9
* 4/13/17
*/

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Constants
#define MAX_ELEMENTS 20
#define MAX_STR_SIZE 80

//Structure for custom data type
struct element_t{
	int atomic_num;
	char name[20];
	char chem_name[20];
	char class[20];
	double atomic_weight;
	int electrons[7];
};

//Renaming custom data type to Element
typedef struct element_t Element;
//Creating custom pointer for data type Element
typedef Element *Ptr_element;

//Array for Elements
Element array_t[MAX_ELEMENTS];

/* Function prototypes */
Element scan_elements(void);
void print_elements(int element_num);

/* Main method, holds input checking logic */
int main(int argc, char *argv[])
{
	int N = 0;
	/* Error Checking Section */	
	if(argc > 2 || argc < 2)//Checks if there is > 1 or < 1 argument given on command line
		{printf("ERROR: You must provide exactly one argument to this program.\n\n");		
		return 0;}//Ends program early
		
	//Checks if the given string argument is 2
	else if(argc == 2)		
		{N = (int) strtol(argv[1], NULL, 10);//Convert string argument into an int
		if(N < 0 || N > 20)//If given int is less than 0, throw error
		{printf("ERROR: You must provide an integer greater than 0 and less than or equal to 20.\n\n");	
		return 0;}}//Ends program early
	/* End Error Checking Section */
		
		int i;
		for(i = 0; i < N; i++)//Scan in N elements; N is user input amount
			{array_t[i] = scan_elements();}
	
		print_elements(N);
		
	return 0;
}

/* Method to scan in N elements into array */
Element scan_elements(void)
{
	//Variables to manipulate an instance
	Element element;
	Ptr_element ptr;
		ptr = &element;
	
	//Holds scanned in line from user
	char temp[MAX_STR_SIZE];
		char *begin_temp = temp;
		char *end_temp = temp;
		
	//Holds a word from line of user	
	char word[20];
		char *pos_word = &word[0];
	
	//Iterator for variables in Element	
	int variable = 0;
	
	//Points to position in electrons[]
	int *ptr_elec = ptr->electrons;
	
	//Scans in line from user
	if(fgets(temp, MAX_STR_SIZE, stdin))
	{
		while(*end_temp)
		{
			end_temp++;		
			if(*end_temp == '\0')
			{
				//End of string
			}
			//Look for space at end of word
			else if(*end_temp == ' ')
			{	
				//Loop until left pointer = right pointer
				while(begin_temp < end_temp)
				{									
					//Assigns char from found word into word[]
					*pos_word = *begin_temp;
					pos_word++;
					begin_temp++;
				}
				*pos_word = '\0';
				pos_word = &word[0];				
				
				//Switches for variables in Element
				switch(variable)
				{
					//Atomic Number
					case 0:				
						ptr->atomic_num = (int) strtol(word, NULL, 10);						
						variable++;
						break;
					//Name
					case 1:
						strncpy(ptr->name, word, 20);
						variable++;
						break;
					//Chemical Symbol
					case 2:
						strncpy(ptr->chem_name, word, 20);
						variable++;
						break;
					//Class
					case 3:
						strncpy(ptr->class, word, 20);
						variable++;
						break;
					//Atomic Weight
					case 4:
						ptr->atomic_weight = atof(word);
						variable++;
						break;
					//Electrons[]
					case 5:						
						*ptr_elec = (int) strtol(word, NULL, 10);
						ptr_elec++;
						break;
					
					default:
						break;
					
				}				
				begin_temp = end_temp + 1;
			}
		}/* End of while */		
	}
	return element;
}
/* Method prints out formatted Elements */
void print_elements(int N)
{
	//Variables to hold instances for printing
	Element element, smallest, largest;
	Ptr_element ptr;
	
	//Print number of elements
	printf("%d total elements.\n", N);
	
	//Loop to find largest and smallest atomic number
	int k, largest_num, smallest_num, temp;
	largest_num = 0; smallest_num = 10000;
	for(k = 0; k < N; k++)
	{
		element = array_t[k];
		ptr = &element;
		temp = ptr->atomic_num;
		
		//Largest atomic number check
		if(temp > largest_num)
		{
			largest = array_t[k];
			largest_num = temp;
		}
		//Smallest atomic number check
		if(temp < smallest_num)
		{
			smallest = array_t[k];
			smallest_num = temp;
		}
	}
	
	//Print out largest and smallest element by atomic number
	ptr	= &smallest;	
	printf("%s had the smallest atomic number.\n", ptr->name);
	ptr = &largest;
	printf("%s had the largest atomic number.\n", ptr->name);
	
		//Begin loop for printing formatted elements
		int i;
		for(i = 0; i < N; i++)
		{
			//Get instance of element from array_t
			element = array_t[i];
			//Make pointer to element
			ptr = &element;
	
			printf("---------------\n");
			
			//Loop to alter spacing after atomic number and 
			//Chemical symbol if atomic number is single digit
			if(ptr->atomic_num < 10)
			{
				printf("| %d %0.4f\n", ptr->atomic_num, ptr->atomic_weight);
				printf("| %s %s\n| ", ptr->chem_name, ptr->name);
			}			
			//If atomic number > 10, use /t for spacing
			else
			{
				printf("| %d\t%0.4f\n", ptr->atomic_num, ptr->atomic_weight);
				printf("| %s\t%s\n| ", ptr->chem_name, ptr->name);
			}
			
			//Begin loop for printing out electron array			
			int j;
			for(j = 0; j < 6; j++)
			{
				//Breaks when reach the end of array early
				if(ptr->electrons[j] == '\0')
				{break;}
				
				//Check if number is NULL or 0, DONT print then
				if(ptr->electrons[j] != 0 || NULL)
				{
					printf("%d ", ptr->electrons[j]);
				}
			}			
			printf("\n---------------\n");
		}
		printf("\n");
}