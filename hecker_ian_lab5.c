/* 
 * Ian Hecker
 * CSCI112, Lab5
 * 3/2/17
 */
 
#include <stdio.h>
#include <math.h>
 
int barcode[12];//Barcode array

//Gets user input of 12 ints
void get_input(void)
{
	int num;
	printf("Enter a bar code to check. Separate digits with a space >\n");
	for(int i=0; i<12; i++)
	{
		//Scan in 12 ints
		scanf("%d", &num);
		barcode[i] = num;
	}
	//Print out ints user entered
	printf("\nYou entered the code: ");
	for(int i=0; i<12; i++)
	{
		printf("%d ", barcode[i]);
	}
	printf("\n");
}
//Check odd ints in barcode[]
int check_odd(void)
{
	int odd_sum = 0;
	for(int i=0; i<12; i+=2)//Iterate over odd ints
	{
		odd_sum += barcode[i];
	}
	odd_sum *= 3;
	
	printf("STEP 1: Sum of the odds times 3 is %d\n", odd_sum);
	return odd_sum;
}
//Check even ints of barcode[]
int check_even(void)
{
	int even_sum = 0;
	for(int i=1; i<11; i+=2)//Iterate over even ints
	{
		even_sum += barcode[i];
	}
	printf("STEP 2: Sum of the even digits is %d\n", even_sum);
	return even_sum;
}
//Return sum of odd and even ints in barcode[]
int total_sum(int sum1, int sum2)
{
	int total_sum = sum1 + sum2;
	printf("STEP 3: Total sum is %d\n", total_sum);
	return total_sum;
}
//Create check digit from last digit of total sum
int check_digit(int total_sum)
{
	int check_digit = 10 - (total_sum % 10);
	printf("STEP 4: Calculated check digit is %d\n", check_digit);
	return check_digit;
}
//Checks if checkDigit == last int int barcode[]
void validate(int check_digit)
{
	printf("STEP: 5 Check digit and last digit ");
	if(check_digit == barcode[11])
	{
		printf("match\n");
		printf("Barcode is VALID.\n");
	}
	else
	{
		printf("do not match\n");
		printf("Barcode is INVALID.\n");
	}
}
//Main function
int main(void)
{
	int oddsum, evensum, totalsum, checkdigit;
	
	get_input();
	
	oddsum = check_odd();
	evensum = check_even();
	 
	totalsum = total_sum(oddsum, evensum); 
	 
	checkdigit = check_digit(totalsum);
	 
	validate(checkdigit);
	
	return(0);
}



