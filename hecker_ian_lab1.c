
/*
 *Ian Hecker
 *Lab 1, CSCI 112
 *1/18/2017
 */
#include <stdio.h>

int main()
{
   /* declare variables */	
   float celsius, fahrenheit;

   /* Prompt input of temp in Celsius */
   printf("What is the temperature in Celsius? > ");
   scanf("%f", &celsius);
   
   /* Convert Celsius to Fahrenheit */
   fahrenheit = ((celsius * 9) / 5) + 32;

   /* Display converted Fahrenheit temp */
   printf("The temperature in Fahrenheit is: %.3f\n", fahrenheit);

   /* Prompt input of temp in Fahrenheit */
   printf("What is the temperature in Fahrenheit? > ");   
   scanf("%f", &fahrenheit);

   /* Convert Fahrenheit to Celsius */
   celsius = ((fahrenheit - 32) * 5) / 9;

   /* Display converted temp in Celsius */
   printf("\nThe temperature in Celsius is : %.3f\n", celsius);

   /* Exit program */
   return(0);
}
