/* 
 * Ian Hecker
 * Lab 3, CSCI 112
 * 2/9/17
 */

#include <stdio.h>
#include <math.h>

/* Variables for to store data */
int N;	
double smallest, largest, average, range, std_dev;

/* Gets an integer N from input */
int get_N(void)
{	
    printf("Enter a value for N that is >= 0: ");
    scanf("%d", &N);
	
    if(N < 0){/* If N is a negative #, prompt input again */
        printf("Invalid value for N\n");
	get_N();}
    else{	  
	return N;}
}

/* Gets double from user input */
double get_input(void)
{
    double input;
    printf("Enter a number: ");
    scanf("%lf", &input);
    return input;
}

/* Searches number_array for smallest double */
double get_smallest(double number_array[])
{	
    smallest = number_array[0];
   
    for(int i=1; i<N; i++)
    {
        if(number_array[i] < smallest)
	{
            smallest = number_array[i];          
	}
    }
    return smallest;
}

/* Searches number_array for largest double */
double get_largest(double number_array[])
{	
    largest = number_array[0];
	
    for(int i=1; i<N; i++)
    {
	if(number_array[i] > largest)
	{
            largest = number_array[i];
	}
    }
    return largest;
}

/* Returns average of doubles in array */
double get_average(double number_array[])
{
    if(N == 0)	{return 0;}
    else
    {		
    	for(int i=0; i<N; i++)
    	{
	    average += number_array[i];
    	}
        average /= N;
        return average;
    }
}

/* returns the largest element minus the smallest element */
double get_range(void)
{
    return (largest - smallest);
}

/* Computes the standard deviation of entered doubles */
double get_std_dev(double number_array[])
{
    if(N == 0){return 0;}
    else
    {
        double S = 0;
		
	for(int i=0; i<N; i++)
	{
	    /* Summing up the squares of numbers */
	    S += pow(number_array[i], 2);
        }	
    return sqrt(((S/N) - pow(average, 2)));
    }
}

/* Prints out summary of number stats */
void print_summary(void)
{
    printf("The Highest is: %.3f\n", largest);
    printf("The Lowest is: %.3f\n", smallest);
    printf("The Average is: %.3f\n", average);
    printf("The Range is: %.3f\n", range);
    printf("The Standard deviation is: %.3f\n", std_dev);
}

int main(void)
{
    /* Get N from user */
    N = get_N();

    /* Create array to store numbers */
    double number_array[N];
    
    /* Ask user for input N times, store in array */
    for(int i=0; i<N; i++)
        {number_array[i] = get_input();}
	
    /* Calling functions to get stats */
    smallest = get_smallest(number_array);
    largest  = get_largest(number_array);	
    average  = get_average(number_array);	
    range    = get_range();	
    std_dev  = get_std_dev(number_array);	

    /* Print out stats */
    print_summary();
	
    /* Exit program */
    return(0);
}
/* Have a nice day, Kierstyn! */





