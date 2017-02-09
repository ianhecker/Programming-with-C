/*
 * Ian Hecker
 * Lab2, CSCI112
 * 2/1/17
 */
#include <stdio.h>

/* Declaring methods inside of lab2.c */
float get_input(int);
float get_next(float, float);
void print_result(float);

/*Main function of program*/
int main(void)
{
   float x_left; /* The x variable on left of equation  */
   float x_right; /* The x variable on right side of equation */
   float x_final; /* The output of the equation */	

   /* Ask user for input and set as variables */
   x_left = get_input(1);
   x_right = get_input(2);
   
   /* Calling equation function, then moving variables up a spot */
   /* xMinusOne --> xMinusTwo, etc */
   x_final = get_next(x_left, x_right);
      x_left = x_right;
      x_right = x_final;
   x_final = get_next(x_left, x_right);
      x_left = x_right;
      x_right = x_final;
   x_final = get_next(x_left, x_right);
   
   /* Print result of equation running three times */
   print_result(x_final);
   
   /* End program */
   return(0);
}
/* Method that prints out prompt and scans in variables */
float get_input(int print_option)
{
   if(print_option == 1)
	{printf("\nEnter a value for Xn-2: ");}
   else if(print_option == 2)
	{printf("\nEnter a value for Xn-1: ");}
   
   float x_input = 0;
   scanf("%f", &x_input);
   return x_input;
}
/* Method that utilizes equation to find x_final */
float get_next(float x_left, float x_right)
{
   float x_output;
   x_output = (x_left / 2) + (3 * x_right); /* Equation for finding x_final */
   return x_output;
}
/* Prints out result of equation running three times */
void print_result(float x_final)
{
   printf("\nThe result is %.2f\n", x_final);
}
/* Have a good day, TA-grader! */
