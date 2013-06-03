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

info contact[100];

FILE *fp;

void addcontact();
void viewall();
void searchcontact();
void display_contact(info ss);
void reset();

int list;


main()
{

int choice=0, i;

    printf("\t     Welcome to 'MY PERSONAL Phone Book'         \n");


while(choice!=5){
    printf("\t=================================================\n");
    printf("\t*    Enter 1 to add a new contact.              *\n");
    printf("\t*    Enter 2 to display all contacts.           *\n");
    printf("\t*    Enter 3 to search a contact.               *\n");
    printf("\t*    Enter 4 to delete all contacts.            *\n");
    printf("\t*    Enter 5 to exit program                    *\n");
    printf("\t=================================================\n");
    scanf("%d", &choice);

switch(choice){

	case 1: addcontact();
			break;

	case 2: viewall();
			break;

	case 3: searchcontact();

			break;

	case 4: reset();
		i=0;
			break;

    	case 5: printf("\nThank you for using 'My Personal Phone Book'\n Good Bye!!\n");
			break;

	default: printf("Invalid Input\n");
}
}
}





void addcontact(){//this is the function to add contact

	int i, j;

   	 printf("\t\tHow many contact?  ");
   	 scanf("\t\t%d", &list);
    	 putchar('\n');

    
	fp=fopen("contacts.txt","a");

{	
	for( i=0; i<list; i++ )
    {	
	printf("\t\tContact %d:\n", i+1);
	printf("\tFirst name(no space):");
	scanf("\t%s", contact[i].name.fname);
	printf("\tLast name(no space):");
    scanf("\t%s", contact[i].name.lname);
	printf("\tNo#:");
	scanf("\t%li", &contact[i].no);
	printf("\tE-mail:");
	scanf("\t%s", contact[i].eadd);
	
	fprintf(fp, "Fullname: %s %s \nNo#:      %li\nE-mail:   %s\n", contact[i].name.fname,contact[i].name.lname,contact[i].no,contact[i].eadd);
	putchar('\n');
	}
}
	fclose(fp);

putchar('\n');
    putchar('\n');
    printf("\t\t-----------------------------------------------\n");
    printf("\t\tThank you for adding new contact/s\n");
    printf("\t\tPlease choose another option\n");
    printf("\t\t-----------------------------------------------\n");
    putchar('\n');
    putchar('\n');
	}


void searchcontact()
{
    char nametofind[20], compare[20];
    int position;

    printf("\t\tOBSERVE CASE SENTIVITY\n");
    printf("\t\tCapitalized all first letters\n");
    putchar('\n');
    printf("\t\tEnter name of the contact to search: ");
    scanf("%s", nametofind);
    putchar('\n');
    putchar('\n');

        for ( position=0; position<list; position++ )
            {
                if ( strcmp( nametofind, contact[position].name.fname )==0 )
                    {
                            printf("\t\t%s has the following information:\n", nametofind);
                            putchar('\n');
                            display_contact(contact[position]);
                            strcpy( compare, contact[position].name.fname);
                    }
            }
        if     ( strcmp( nametofind, compare )==0 )
            {
                putchar('\n');
                putchar('\n');
                printf("\t\t-----------------------------------------------\n");
                printf("\t\tThank you for using 'My Personal Phone Book!\n");
                printf("\t\tPlease choose another option.\n");
                printf("\t\t-----------------------------------------------\n");
                putchar('\n');
                putchar('\n');
            }
        else
            {
                printf("\t\t-----------------------------------------------\n");
                printf("\t\tE R R O R!\n");
                printf("\t\tSorry but the name you entered is not in your list of contacts.\n");
                printf("\t\tPlease try again using a different name.\n");
                printf("\t\t-----------------------------------------------\n");
                putchar('\n');
            }
}


void display_contact(info ss)
{
    printf("\t\tName: %s %s\n", ss.name.lname,ss.name.fname);
    printf("\t\tNo#: %li\n", ss.no);
    printf("\t\tE-mail: %s\n", ss.eadd);

    putchar('\n');
    putchar('\n');
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
















