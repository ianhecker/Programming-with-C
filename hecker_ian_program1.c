/* 
 * Ian Hecker
 * CSCI112, outlab1
 * 2/20/17
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Function prototype
int is_valid(int input);

//Prompts int from user
int get_input(void)
{
	int input;
	
	//Print out for user
	printf("Enter an odd number less than or equal to 9 and greater than 0 > ");
	scanf("%d", &input);
	
	//Calls is_valid to check rules
	return is_valid(input);
}
//Holds rules that user_int must follow
int is_valid(int input)
{
	if(input < 1)//Check for number less than zero
	{
		printf("You have entered a number less than 1. Please try again.\n");
		get_input();
	}
	else if(input % 2 == 0)//Check for number that is even
	{
		printf("You have entered an even number. Please try again.\n");
		get_input();		
	}
	else if(input > 9)//Check for greater than 9 int
	{
		printf("You have entered a number greater than 9. Please try again.\n");
		get_input();
	}
	return input;
}
//Prints out diamond shape based on user input
void print_pattern(int user_num)
{
	int counter = 1;
	
	//loop for top of diamond
	for(counter; counter <= user_num; counter += 2)
	{
		printf("%*s", (user_num - counter), "");//Spaces before num

		int tmp = 1;
		while(tmp <= counter)
		{
			printf("%d ", tmp);
			tmp++;
		}
		printf("\n");
	}

	counter -=4;//Decrements counter

	//loop for bottom half of diamond
	for(counter; counter >= 0; counter -=2)
	{
		printf("%*s", (user_num - counter), "");//Space before num
		
		int tmp = 1;
		while(tmp <= counter)
		{
			printf("%d ", tmp);
			tmp++;
		}
		printf("\n");
	}
}
//main function that calls other functions
int main(void)
{	
	print_pattern(get_input());	
	
	return (0);
}
