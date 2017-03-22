/*
* Ian Hecker
* CSCI112, Program 2
* 3/22/17
*/

//Included libraries
#include <stdio.h>
//Max array size
#define MAX_ARRAY_SIZE 50

int     populate_array( int array[] );                  // Fill array with values from user.
void    print_array( int array[], int n );              // Print out the array values
void    swap( int array[], int index1, int index2 );    // Swap two array elements. 
void    quicksort( int array[], int low, int high );    // Sorting algorithm
int     partition( int array[], int low, int high );    // Find the partition

int main(void)
{
	//declare array of size MAX_ARRAY_SIZE
	int array[MAX_ARRAY_SIZE];
	
	//call function populate_array, store as variable n
	int n = populate_array(array);
	
	//print out value in array by calling function print_array
	printf("The initial array contains:\n");
	print_array(array, n);
	
	//Call quicksort(array, 0, n-1);
	quicksort(array, 0, n - 1);
	
	//verify list is sorted by printing out list --> call print array function
	printf("The array is now sorted:\n");
	print_array(array, n);
	
	//return 0 to avoid errors
	return(0);
}
//Prompts user for n and n amount of integers
int populate_array(int array[])
{
	 int n;
	while(1)
		
		{printf("Enter the value of n > ");
		scanf("%d", &n);
		//If N is negative, repeat loop
		if(n < 0)
		{printf("%d is less than zero. Please try again.\n\n", n);}
		
		//If n is greater than MAX, repeat loop
		else if(n > MAX_ARRAY_SIZE)
		{printf("%d exceeds the maximum array size. Please try again.\n\n", n);}
		
		//if n is the right size, break loop
		else if(n <= MAX_ARRAY_SIZE)
		{break;}}
	
	 int user_int;
	 printf("Enter %d integers (positive, negative, or zero) > \n", n);
	//Scan in n integers from user into array
	for(int i=0; i < n; i++)
		
		{scanf("%d", &user_int);
		array[i] = user_int;}
		
	return n;
}
//Prints array, # on individual lines
void print_array(int array[], int n)
{
	for(int i=0; i < n; i++)
	
		{printf("%+5d\n", array[i]);}
}
//swap two int positions in array
void swap(int array[], int index1, int index2)
{
	int temp;
	temp = array[index2];
	array[index2] = array[index1];
	array[index1] = temp;
}
//Recursive sorting method. Breaks down problems into smaller chunks
void quicksort(int array[], int low, int high)
{
	 int pivot;
	if(low < high)
		
		{pivot = partition(array, low, high);
		//Sort lower half of array and upper half
		quicksort(array, low, pivot - 1);
		quicksort(array, pivot + 1, high);}
}
//creates a pivot and "partition", swaps integers
int partition(int array[], int low, int high)
{
	int pivot;
	pivot = array[high];
	
	int i = low;
	for(int j=low; j < high; j++)
		
		{if(array[j] <= pivot)
			{swap(array, i, j);
			i = i + 1;}}
	
	swap(array, i, high);
	return i;
}