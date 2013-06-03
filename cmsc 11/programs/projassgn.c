/*  Graycel Santos
    2009-32132
    CMSC 11, T-4L

   -PROJECT ASSIGNMENT-
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//this program manages to store contacts, by adding contacts,printing all entered informations, and deleting all the entered data.
typedef struct{
char fname[100];
char lname[100];
}full;//this is the structure for the name



typedef struct{
char eadd[40];
char add[40];
long no;
full name;
}info;//this is the structure for the whole information.



FILE *fp;

void addcontact();
void viewall();
void reset();


main()
{

int choice=0;

    printf("\t     Welcome to 'MY PERSONAL Phone Book'         \n");


while(choice!=4){
    printf("\t=================================================\n");
    printf("\t*    Enter 1 to add a new contact.              *\n");
    printf("\t*    Enter 2 to display all contacts.           *\n");
    printf("\t*    Enter 3 to delete all contacts.            *\n");
    printf("\t*    Enter 4 to exit program                    *\n");
    printf("\t=================================================\n");
    scanf("%d", &choice);

switch(choice){

	case 1: addcontact();
			break;

	case 2: viewall();

			break;

	case 3: reset();
			break;

    case 4: printf("\nThank you for using 'My Personal Phone book'\n Good Bye!!\n");
			break;

	default: printf("Invalid Input\n");
}
}
}





void addcontact(){//this is the function to add contact

	info contact;
	fp=fopen("contacts.txt","a");

{
	printf("\tFirst name(no space):");
	scanf("\t%s", contact.name.fname);
	printf("\tLast name(no space):");
    scanf("\t%s", contact.name.lname);
	printf("\tNo#:");
	scanf("\t%li", &contact.no);
	printf("\tE-mail:");
	scanf("\t%s", contact.eadd);
	}
	fprintf(fp, "Fullname: %s %s \nNo#:      %li\nE-mail:   %s\n", contact.name.fname,contact.name.lname,contact.no,contact.eadd);
	putchar('\n');
	fclose(fp);
	}

void viewall(){//this reads the files,therefore it will print all the contacts in the list.
	fp=fopen("contacts.txt","r");
	char c=getc(fp);
	while(!feof(fp)){
	printf("%c",c);
	c=getc(fp);
	}
	printf("\t\tpress the number of your desired action.\n");
	fclose(fp);
	}

void reset(){
	char c=getc(fp);
	fp=fopen("contacts.txt", "w");
	printf("all contacts in the list were erased!\n");
	fclose(fp);
	}













