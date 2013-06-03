/*Kristela Mae-Joy R. Valentin 2009-35001 T-3L*/
#include <stdio.h>
#include <string.h>

//this program manages records of students, by adding records,printing all entered informations, and deliting all the entered data.
typedef struct{
char fname[100];
char mname[100];
char lname[100]; 		
}fullname;//this is the structure for the name

typedef struct{
int age;
fullname name;
}info;//this is the structure for the whole iformation.
		

FILE *fp;

void addrecord();
void printall();
void reset();
   

main(){
int choice=0;
while(choice!=4){
printf("\t=================================================\n");
printf("\t*    Enter 1 to add a new student record.       *\n");
printf("\t*    Enter 2 to display all student record.     *\n");
printf("\t*    Enter 3 to delete all stored information.  *\n");
printf("\t*    Enter 4 to exit program                    *\n");
printf("\t=================================================\n");
scanf("%d", &choice);
switch(choice){
	case 1:addrecord();
			break;
	case 2:printall();
			break;
	case 3:reset();
			break;
	default: printf("bye!\n");
}
}
}

void addrecord(){//this is the function to add records
	
	info student;
	int norecords;
	fp=fopen("student.txt","a");

{
	printf("\tFirst name:", student.name.fname);
	scanf("\t%s", student.name.fname);
	printf("\tMiddle name:", student.name.mname);
	scanf("\t%s", student.name.mname);
	printf("\tLast name:", student.name.lname);
	scanf("\t%s", student.name.lname);
	printf("\tAge:", student.age);
	scanf("\t%d", &student.age);
	}
	fprintf(fp, "Fullname: %s %s %s \nAge:%d\n", student.name.fname,student.name.mname,student.name.lname,student.age);
	putchar('\n');
	fclose(fp);
	}

void printall(){//this reads the files,therefore it will print all the data.
	fp=fopen("student.txt","r");
	char c=getc(fp);
	while(c!=EOF){
	printf("%c",c);
	c=getc(fp);
	}
	printf("\t\tpress the number of your desired action.\n");
	fclose(fp);
	}
	
void reset(){
	char c=getc(fp);
	fp=fopen("student.txt", "w");
	printf("all data were erased!\n");
	fclose(fp);
	}
	


	
	
	
	
   
	
	
	
	
   
	
	
	
	
   
	
	
