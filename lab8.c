/*
* Ian Hecker
* CSCI112, Lab8
* 4/6/17
*/

//Libraries utilized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


//Constant to limit char input
#define MAX_STRING_SIZE 80

/* Reverses strings based on inputted pointer locations */
void reverse(char *left, char *right)
{
	//Temporary holder for char
	char temp;
	//Loop until two locations meet in middle
	while (left < right)
	{
	//Assign left char to temp
	temp = *left;
	//Increment left as we assign right char to left position 
	*left++ = *right;
	//Decrement right as we assign temp char into right position
	*right-- = temp;
	}
}
/*-----------------------------------------*/
/* Reverses whole words in provided string */
void reverseWords(char *str)
{
	//Initialize word_start with beginning of str
	char *word_start = str;
	 /* temp is for word boundry */
	char *temp = str;

	/*Loop through while still inside of temp array bounds*/
	while(*temp)
	{
		//Increment	temp
		temp++;
		//Check if temp is at end of line
		if (*temp == '\n')
		{
			*temp = '\0';
			//Call reverse to swap last word
			reverse(word_start, temp - 1);
		}
		//Check if temp is at end of word
		else if(*temp == ' ')
		{
			//Call reverse() to swap found word
			reverse(word_start, temp - 1);
			//Increment start of word up to next word start
			word_start = temp + 1;
		}
		else if(*temp == '\0')
		{
			//Call reverse to swap last word
			reverse(word_start, temp - 1);
		}
		else if(!isalpha(*temp))
		{
			//Convert punctuation into a space
			*temp = ' ';
		}
	}
	/* End of while-loop */

	/* Call reverse() to flip entire string around */
	reverse(str, temp - 1);
}
/*--------------------------------------------------------------*/
/* Removes punctuation from a char array and moves letters over */
void remove_punc(char *str_src)
{
	//Initalize position holder
	size_t pos = 0;
	//Loop to go through cahr array
	for (char *p = str_src; *p; ++p)
		//Check for alphabetical and space chars
		if(isalpha(*p) || *p == ' ')
			//increment str_src pos and replace with char from pointer
			str_src[pos++] = *p;
	//End string with end chars to ensure reverse() works
	//str_src[pos] = '\n';
	str_src[pos] = '\0';
}
/* Driver function to test above functions */
int main(int argc, char *argv[])
{
	int N = 0;
	/* Error Checking Section */
	//Checks if there is > 1 or < 1 argument given on command line
	if(argc > 2 || argc < 2)
		{printf("ERROR: Please provide an integer greater than or equal to 0\n");
		//Ends program early
		return 0;}
		
	//Checks if the given string argument is 2
	else if(argc == 2)
		//Convert string argument into an int
		{N = (int) strtol(argv[1], NULL, 10);
		
		//If given int is less than 0, throw error
		if(N < 0)
		{printf("ERROR: Please provide an integer greater than or equal to 0\n");
		//Ends program early
		return 0;}}
	/* End of Error Section for parameters */
		
		//Char array to hold keyboard input
		char str_array[MAX_STRING_SIZE];
		
		int i;
		//Loops N times from user input
		for(i = 0; i < N; i++)
			//fgets() scans in entire line from user input
			{if(fgets(str_array, MAX_STRING_SIZE, stdin))
				//Call remove_punc() to remove punctuation
				{remove_punc(str_array);
				//If successfully scanned into char array, call reverse()
				reverseWords(str_array);
				//Print finished product
				printf("%s\n", str_array);}}
	
	printf("\n");
	//End main loop
	return 0;
}
/*-----------------------------------------*/