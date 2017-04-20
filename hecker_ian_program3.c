/*
* Ian Hecker
* CSCI112, Program3
* 4/21/17
*/

//Libraries
#include <stdio.h>
#include <stdlib.h>

//Preprocessor directive
#define NAME_SIZE 25

//Custom data type for student
struct data_type{
	int sid;
	char last_n[NAME_SIZE];
	char first_n[NAME_SIZE];
	float *grades;
	float gpa;
};

//Renaming data_type to student
//Creating pointer data type for student
typedef struct data_type student;
typedef student *ptr_student;

/* Prototypes for methods */
student	input_student(int grade_num);
float 	calc_gpa(student s, int grade_num);
void 	print_record(ptr_student ptr_s, int student_num, int grade_num);
void	free_mem(ptr_student, int student_num);

/* Main method of program */
//1) Prompts user for num of students/grades
//2) Prints total num of students/grades
//3) Utilizes calloc to allocate memory for array of students
//4) Inputs students into array through for loop with input_student
//5) Calls print_record to print all student information
//6) Calls free_mem to release alloated memory
int main(int argc, char *argv[])
{
	//Vars for first int in file or input
	//Scans in vars
	int student_num, grade_num;
		scanf("%d", &student_num);
		scanf("%d", &grade_num);
	//Print out user inputted vars for student/grade num
	printf("Number of students: %d\n", student_num);
	printf("Number of grades (each): %d\n", grade_num);
	
	//Vars for first student; for properly allocating
	//the right amount of memory for each student.
	//Otherwise, it only gives each student's grade pointer
	//room for one float number -> errors
	//Setting up the first student, then using the amount of
	//space that one uses for the base for other students works
	student s;
		s = input_student(grade_num);
	student *array_s = (student *)calloc(student_num, sizeof(s));
		*array_s = s;
	
	//For loop to read in students into array 
	int i;
	for(i = 1; i < student_num; i++)
	{
		//Starts at 1; already added first student above
		//when allocating memory properly
		s = input_student(grade_num);
		(*(array_s + i)) = s;
	}
	
	//Calls print method to print out all students in array
	print_record(array_s, student_num, grade_num);
	
	//Calls free_mem to release allocated memory
	free_mem(array_s, student_num);
	
	//Exit
	return 0;
}
/* Input Student Information */
//1) Declares new student, scans in variables
//2) Allocated memory for an array of length grade_num
//...!!!Important to call this before allocating memory for!!!
//...!!!array of students. Pointer needs to know how many floats!!!
//...!!!before space is made for each student in array!!!
//3) Reads in grades into student pointer
//4) Calls calc_gpa to find gpa for student
//5) Returns student instance to caller method
student input_student(int grade_num)
{	
	//Setting new student vars
	student s;
		scanf("%d", &s.sid);//Set sid
		scanf("%s", s.last_n);//Set last name
		scanf("%s", s.first_n);//Set first name
	
	//Allocate memory for float array of grades
	s.grades = (float *)calloc(grade_num, sizeof(float));
	
	//Scan in determined num of grades into allocated array
	int i;
	for(i = 0; i < grade_num; i++)
	{	
		scanf("%f", &s.grades[i]);
	}
	
	//Call calc_gpa with current student record and grade_num
	s.gpa = calc_gpa(s, grade_num);//Set gpa to value found from calc_gpa
	
	return s;
}
/* Calculate student GPA */
//1) Calculates student gpa from list of grades
//2) Returns gpa to caller method
float calc_gpa(student s, int grade_num)
{
	//Variables for gpa and grade array
	float gpa;
	float *grade_list;
	
	grade_list = s.grades;
	//add each float in student grades[] to gpa
	int i;
	for(i = 0; i < grade_num; i++)
	{
		gpa += *grade_list++;
	}
	
	//Divide gpa by num of grades for average
	gpa /= grade_num;
	
	return gpa;
}
/* Print all student information */
//1) Take pointer to array of students
//.. Take total num of students
//.. Take total num of grades
//2) Print out all students and all respective information
void print_record(ptr_student array_s, int student_num, int grade_num)
{
	//Var for holding place in student grade list
	float *ptr_grade;
	
	//Loop to print out each student
	int i, j;
	for(i = 0; i < student_num; i++)
	{	
		//Printing out student information
		//(*(array_s + i)).VARIABLE is the current student's VARIABLE
		printf("ID: %d, ", (*(array_s + i)).sid);
		printf("Name: %s %s, ", (*(array_s + i)).first_n, (*(array_s + i)).last_n);
		printf("GPA: %0.2f\nGrades: ", (*(array_s + i)).gpa);
		
		//Loop to print out each grade for student
			ptr_grade = (*(array_s + i)).grades;
		for(j = 0; j < grade_num; j++)
		{			
			printf("%0.1f ", *ptr_grade);
			ptr_grade++;
		}
		printf("\n");
	}
}
/* method to free allocated memory */
//1) Releases grade pointer in each student and sets to null
//2) Releases student array, sets equal to null
void free_mem(student *array_s, int student_num)
{
	int i;
	for(i = 0; i < student_num; i++)
	{
		free(array_s[i].grades);
		array_s[i].grades = NULL;		
	}
	free(array_s);
	array_s = NULL;	
}