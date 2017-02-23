/*
* Ian Hecker
* CSCI112, Lab4
* 2/23/17
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define LOOP_LIMIT 90

typedef enum
	{Sine,
	Cosine,
	Tangent,
	QUIT} menu_t;

menu_t is_valid(menu_t);
 
menu_t get_input(void)
{
	printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n");
	printf("Enter your choice > ");

	menu_t choice;
	scanf("%u", &choice);
	
	return is_valid(choice);
}
menu_t is_valid(menu_t choice)
{
if(choice < Sine || choice > QUIT)
	{printf("%d is an invalid option. Please try again.\n", choice);
	get_input();}
else	
	return choice;
}

double get_radians(double angle)	
{
	return (angle/180) * PI;
}

void program_loop(void)
{
	for(int i=0; i < LOOP_LIMIT; i++)
		{menu_t choice = get_input();
		double output;
		double angle = 0;		

		switch(choice)
			
			{case Sine:
				for(angle; angle <= 90; angle+=15)
					{output = sin(get_radians(angle));					
					printf("	sin(%d) = %.4f\n", (int)angle, output);}
				break;
			
			case Cosine:
				for(angle; angle <= 90; angle+=15)
					{output = cos(get_radians(angle));					
					printf("	cos(%d) = %.4f\n", (int)angle, output);}
				break;
			
			case Tangent:
				for(angle; angle <= 90; angle+=15)
					{if(angle != 90)
						{output = tan(get_radians(angle));					
						printf("	tan(%d) = %.4f\n", (int)angle, output);}
					else
						{printf("	tan(%d) = UNDEFINED\n", (int)angle);}
					}
				break;
				
			case QUIT:
				i = LOOP_LIMIT;
				printf("You chose QUIT. Thank you, come again!\n");
				break;
				
			default:
				break;}
	}
}
int main(void)
	{program_loop();}
