/*
* Ian Hecker
* CSCI112, Lab8
* 4/6/17
*/

//Libraries utilized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constant to limit char input
#define MAX_STRING_SIZE 80
//Define boolean terms
#define FALSE 0
#define TRUE 1

/* Prototypes of functions here */
void reverseWords(char *str);
void reverse(char *begin, char *end);

//Main function of lab8.c
int main(int argc, char *argv[])
{
	int N = 0;
	/* Error Checking Section */
	//Checks if there is > 1 or < 1 argument given on command line
	if(argc > 2 || argc < 2)
		{printf("ERROR: Please provide an integer greater than or equal to 0\n\n");
		//Ends program early
		return 0;}
		
	//Checks if the given string argument is 2
	else if(argc == 2)
		//Convert string argument into an int
		{N = (int) strtol(argv[1], NULL, 10);
		
		//If given int is less than 0, throw error
		if(N < 0)
		{printf("ERROR: Please provide an integer greater than or equal to 0\n\n");
		//Ends program early
		return 0;}}
	/* End of Parameter Error Section */
		
		//Char array to hold keyboard input
		char str_array[MAX_STRING_SIZE];
		
		int i;
		//Loops N times from user input
		for(i = 0; i < N; i++)
			//fgets() scans in entire line from user input
			{if(fgets(str_array, MAX_STRING_SIZE, stdin))
			//If successfully scanned into char array, call reverse()
				{reverse(str_array);}}
	
	//End main loop
	return 0;
}

/* Reverse Word function */
void reverseWords(char *s)
{
  char *word_begin = s;
  char *temp = s; /* temp is for word boundry */
 
  /*STEP 1 of the above algorithm */
  while( *temp )
  {
    temp++;
    if (*temp == '\0')
    {
      reverse(word_begin, temp-1);
    }
    else if(*temp == ' ')
    {
      reverse(word_begin, temp-1);
      word_begin = temp+1;
    }
  } /* End of while */
 
   /*STEP 2 of the above algorithm */
  reverse(s, temp-1);
}
void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}
 
/* Driver function to test above functions */
int main()
{
  char s[] = "i like this program very much";
  char *temp = s;
  reverseWords(s);
  printf("%s", s);
  getchar();
  return 0;
}

/*void reverse(char *str_src)
{
	char temp;
	
	size_t len = strlen(str_src) - 1;
	size_t i;
	size_t j = len;
	
	for(i = 0; i < len; i++)
		
		{temp = str_src[i];
		str_src[i] = str_src[j];
		str_src[j] = temp;
		j--;
		
		if(j == len / 2)
		{break;}}
	
	printf("%s\n", str_src);
	
	char *home = str_src;
	printf("home = %s\n", home);
	
	
	int quit = FALSE;
	i = 0;
	j = 0;
	int iter = 0;
	while(quit == FALSE)
	{
		printf("i: %zu j: %zu\n" , i, j);
		while(1)
		{
			if(str_src[iter] != ' ')
			{
				printf("str_src[%d] = %s\n", iter, str_src[iter]);
				j++;
				iter++;
			}
			else if(str_src[iter] == ' ')
			{
				printf("Stop 1\n");
				break;
			}
			else if(str_src[iter] == '\0')
			{
				printf("Stop 2\n");
				quit = TRUE;
				break;
			}
			printf("i: %zu j: %zu\n" , i, j);
		}
		quit = TRUE;
	
		
		int word_end = j;
		printf("Word end = %zu\n", j);
		len = j - i;
		printf("Len of word = %zu\n", len);
		for(; i <= len; i++)
			
			{temp = home[i];
			home[i] = home[j];
			home[j] = temp;
			j--;
			
			if(j ==  len / 2)
			{break;}}
		
		printf("home string = %s\n", home);
		
		i = word_end + 2;
		j = i;
		if(*str_src != '\0')
		{str_src++;}
		}
		
	
	printf("Final str = %s\n", home);
}*/