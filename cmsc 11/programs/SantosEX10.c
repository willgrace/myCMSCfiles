/*Graycel Santos
T-4L*/
#include <strings.h>
#include <stdio.h>

//definition of data type for fullname
typedef struct {
	char First[20];
	char Mid[20];
	char Last[20];
}Fullname;

//data type of the student's info
typedef struct{
	Fullname name;
	float quiz[2];
	float exam[3];
	float lab[2];
	float prog;
	float prefi;
}Studinfo;

main()
{

	Studinfo student[2];			//students declaration
	int i,j;
	float sumQ, Q, sumE, E, sumL, L, PA;	
	
	
	for (i=0; i<2; i++)				//loop for input of the two students
	{
	printf("\nstudent number %d >>\n", i+1);
	printf("enter name[First Middle Last]: ");
	scanf("%s %s %s", student[i].name.First, student[i].name.Mid, student[i].name.Last);
	printf("enter your quiz score 1 & 2: ");
	scanf("%f %f", &student[i].quiz[0], &student[i].quiz[1]);
	printf("enter your score in the 3 exams: ");
	scanf("%f %f %f", &student[i].exam[0], &student[i].exam[1], &student[i].exam[2]);
	printf("enter your score in the last 2 exercises: ");
	scanf("%f %f", &student[i].lab[0], &student[i].lab[1]);
	printf("enter your score in your program assignment: ");
	scanf("%f", &student[i].prog);
	putchar('\n');
	
	
	//computation of the prefinal grade of each student
	sumQ = (student[i].quiz[0] + student[i].quiz[1]);
	Q = (sumQ/10.0)*0.05;
	sumE = (student[i].exam[0] + student[i].exam[1] + student[i].exam[2]);
	E = (sumE/60.0)*0.45;
	sumL= (student[i].lab[0] + student[i].lab[2]);
	L = (sumL/20.0)*0.20;
	PA = (student[i].prog/10.0)*0.10;
	
	student[i].prefi = (Q + E + L + PA)*100; //assignment of the prefi grade
	
	}

	//output all data and their prefi grade
	for (j=0; j<2; j++) //printing the array of structures 
	{
	printf("Name: %s %s %s \nQuizzes scores: %.2f %.2f \nExams scores: %.2f %.2f %.2f \nLab exercises scores: %.2f %.2f \n Project assignment score: %.2f \nPre-final Grade: %.2f. \n",
		student[j].name.First, student[j].name.Mid, student[j].name.Last, student[j].quiz[0], student[j].quiz[1], student[j].exam[0],
		student[j].exam[1], student[j].exam[2], student[j].lab[0], student[j].lab[1], student[j].prog, student[j].prefi);
	putchar('\n');
	}

}
//end of program
