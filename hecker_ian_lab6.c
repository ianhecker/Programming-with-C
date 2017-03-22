/* 
* Ian Hecker
* CSCI112, Inlab6
* 3/9/17
*/

//included libraries
#include <stdio.h>
#include <math.h>

// List of all function prototypes

// displays user menu, reads input, and validates input
int user_menu(void);

// Equation functions that are pass by reference
void equation1(float *);            // calculate motion equation 1
void equation2(float *);            // calculate motion equation 2
void equation3(float *);            // calculate motion equation 3
void equation4(float *);            // calculate motion equation 4

// User input functions return a value from user
float get_position_initial(void);   // Prompts user for x0
float get_position_final(void);     // Prompts user for xf
float get_velocity_initial(void);   // Prompts user for v0
float get_velocity_final(void);     // Prompts user for vf
float get_acceleration(void);       // Prompts user for a
float get_time(void);               // Prompts user for t

// Main function of program. Calls other functions accordingly
int main (void)
{
	// Print welcome message
	printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");

	// Variable for the user choice menu.
	int user_choice;

	do
	{
		user_choice = user_menu();  // print menu, validate choice is between 1 and 5

		// You will pass the address of this variable to your equation functions. 
		float result;               // Variable to hold calculated result

		// Handle menu choice selected by user
		switch( user_choice )
		{
			case 1:
				// Call equation 1
				equation1(&result);
				break;
			case 2:
				// Call equation 2
				equation2(&result);
				break;
			case 3:
				// Call equation 3
				equation3(&result);
				break;
			case 4:
				// Call equation 4
				equation4(&result);
				break;
			case 5:
				// exit program if user selected QUIT
				printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
				return 0;
				break;
		}

		// Print out the calculated result with four digits after the decimal place
		printf("Your result is %.4f.\n\n", result);


	} while ( user_choice != 5 );

	return 0; // exit with no error
}

// displays user menu, reads input, and validates input
int user_menu(void)
{
	int input;// User input var
	
	do // Loop until int > 0 && int < 6 is inputted
	{
		printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
		scanf("%d", &input);
		
		if(input < 1 || input > 5)// Invalid option output
			{printf("Invalid Option. Please try again.\n\n");}
			
	} while(input < 1 || input > 5);// Break case
	return input;// Return input
}

// Equation functions that are pass by reference
void equation1(float *velocity_final)// calculate motion equation 1
{
	//vi, a, t needed
	float vi, a, t;//Variables for equation
	
	//Calling for input on vars
	vi = get_velocity_initial();
	a =  get_acceleration();
	t =  get_time();
	
	//Equation which changes float at parameter address
	*velocity_final = vi + a * t;
}
void equation2(float *position_initial)// calculate motion equation 2
{
	//xi, vi, t, a
	float xi, vi, t, a;//Variables for equation
	
	//Calling for input on vars
	xi = get_position_initial();
	vi = get_velocity_initial();
	t =  get_time();
	a =  get_acceleration();
	
	//Equation which changes float at parameter address
	*position_initial = xi + vi * t + 0.5*a * powf(t, 2);
}
void equation3(float *velocity_final)// calculate motion equation 3
{
	//vi, a, xf, xi
	float vi, a, xf, xi;//Variables for equation
	
	//Calling for input on vars
	vi = get_velocity_initial();
	a =  get_acceleration();
	xf = get_position_final();
	xi = get_position_initial();
	
	//Equation which changes float at parameter address
	*velocity_final = sqrt(powf(vi, 2) + 2*a*(xf - xi));
}
void equation4(float *position_final)// calculate motion equation 4
{
	//xi, vf, vi, t
	float xi, vf, vi, t;//Variables for equation
	
	//Calling for input on vars
	xi = get_position_initial();
	vf = get_velocity_final();
	vi = get_velocity_initial();
	t =  get_time();
	
	//Equation which changes float at parameter address
	*position_final = xi + 0.5*(vf + vi) * t;
}

// User input functions return a value from user
float get_position_initial(void)// Prompts user for x0
{	
	float xi;
	printf("    Enter initial position > ");
	scanf("%f", &xi);// Scans in input
	return xi;
}
float get_position_final(void)// Prompts user for xf
{
	float xf;
	printf("    Enter final position > ");
	scanf("%f", &xf);// Scans in input
	return xf;
}
float get_velocity_initial(void)// Prompts user for v0
{
	float vi;
	printf("    Enter initial velocity > ");
	scanf("%f", &vi);// Scans in input
	return vi;
}	
float get_velocity_final(void)// Prompts user for vf
{
	float vf;
	printf("    Enter final velocity > ");
	scanf("%f", &vf);// Scans in input
	return vf;
}
float get_acceleration(void)// Prompts user for a
{
	float a;
	printf("    Enter acceleration > ");
	scanf("%f", &a);// Scans in input
	return a;
}
float get_time(void)// Prompts user for t
{
	float t;
	printf("    Enter time > ");
	scanf("%f", &t);// Scans in input
	return t;
}