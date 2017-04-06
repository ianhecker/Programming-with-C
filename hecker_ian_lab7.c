/*
* Ian Hecker
* CSCI, Lab7
* 3/30/17
*/

#include <stdio.h>


/*
* Homegrown strncpy test program
*/
#include <stdio.h>
#include <string.h>

// Function prototypes
char *my_strncpy(char *dest, char *source, int n);
char *my_strncat(char *dest, char *source, int n);

// ********* Insert your my_strncpy implementation here! *************
char* my_strncpy(char *dest, char *source, int n)
{
	if((dest == NULL) || (source == NULL))
		return NULL;
	int i;
	for(i=0; i < n && source[i] != '\0'; i++)
		dest[i] = source[i];
	for(; i < n; i++)
		dest[i] = '\0';
	return dest;
}

// ********* Insert your my_strncat implementation here! *************
char* my_strncat(char *dest, char *source, int n)
{
	//Make pointer for original location of *dest
	char *cat_strn = dest;
	
	//Iterator for position
	int iter = 0;
	
	//While dest exists, increment
	while(*dest){dest++;}
	
	//Back up from '\0' character
	dest--;
	
	//If dest position does not equal '\n', increment
	if(*dest != '\n'){dest++;}
	
	//While iter < n, dest[] char = source[] char
	while(iter < n)
		{*dest = *source;
		dest++;
		source++;
		iter++;}
	
	//end dest with an "end-char-array" character
	*dest = '\0';
	return cat_strn;
}

int main() {
// Test your function with various source strings and values of n

char testSrc[] = "Hello";
char testDest[40] = "world";
int n = 5;

//Call my_strncat with char arrays
my_strncat(testDest, testSrc, n);
printf("CAT: %s \n", testDest);

//Call my_strncpy with char arrays
my_strncpy(testDest, testSrc, n);
printf("CPY: %s \n", testDest);

//Print out modified testDest array
printf("%s \n", testDest);
return 0;
}

