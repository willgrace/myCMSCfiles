/*  Graycel Santos
    2009-32132
    CMSC 11, T-4L

  ++++++++++++++++++++++++++++++++++++++++++++++-PROJECT ASSIGNMENT-++++++++++++++++++++++++++++++++++++++++++++++++++

				>>>>>>>>>"My (mini) Personal Phone Book<<<<<<<<<< 

	This is a program that is closely related to a Phone Book. It records and displays contact information
	of the person you want/have added to the list. It can also perform different actions like searching a
	contact you recently added and viewing the new list alphabetically or viewing the old contact list stored
	in a file. It also manage to delete all stored data and write a new list...that is if the user doesn't
	want to contact those people in the old stored list that he/she will delete. However, the program needs
	authorization before the user can avail its services. It requires the user to enter a new account he/she
	created and log-in, or else the user cannnot use 'MY PERSONAL PHONE BOOK'.
		
  ++++++++++++++++++++++++++++++++++++++++++++++-====================-++++++++++++++++++++++++++++++++++++++++++++++++++
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//structures that manages to store different needed information from the user
typedef struct{
char first[100];
char last[100];
}full;//this is the structure for the names of the contact

typedef struct{
char eadd[50];
char cel[20];
char tel[20];
full name;
}info;//this is the structure for the whole information of the contact.

typedef struct{
char account[50];
char password[50];
}member;//structure for the user's account information

typedef struct{			
char name[50];
int age;
char tel[20];
char cel[20];
char eadd[50];
}user;//structure for the user's account information





//////////////////////////////////////////////////////////////////////////////////////////////////Global declaration/////////////////////////////////////////////////////////////////////////////////////////////////////////////


member rec[50];
user profile[50];
info contact[100];
int list;

FILE *fp;






//////////////////////////////////////////////////////////////////////////////////////////////////////Function declaration////////////////////////////////////////////////////////////////////////////////////////////////////
//


//This declares the fuctions used to run this program efficiently & effectively


void reminder();
void new(member rec[50], char b[], int c);
void login(member rec[50], char d[], char e[]);
void write(member rec[50], int f);
void newuser(member rec[50], int r);
void record(user profile[50], int g);
void pro(user profile[50], int r);
void addcontact();
void viewall();
void sorted(info s[], int n);
void searchcontact();
void searched(info ss);
void erase();






////////////////////////////////////////////////////////////////////////////////////////////////////////////Main function//////////////////////////////////////////////////////////////////////////////////////////////////////////

//It all starts here :D


main()
{


//local variables declarations

int choice, a=0;		
char password[20];
char account[20];
int intj, inti;



	system("clear");


	for(intj=0; intj<5-1; intj++){		//right triangle (for design only) 
		for(inti=0; inti<intj+1; inti++){
				printf("x");
		}
		putchar('\n');				
	}

    	printf("\tWelcome to 'MY PERSONAL Phone Book'  >>>> ");
	putchar('\n');

	for(intj=4;intj>0;intj--){		//inverted right triangle (for design only)
			
			for(inti=0;inti<intj;inti++){
				printf("x");
			}
		putchar('\n');
				
	}
		putchar('\n');
		putchar('\n');

while(choice!=4){
	
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t* Press 1: Instructions and Reminders.           	 *\n");
	printf("\t* Press 2: Create an account                             *\n");
	printf("\t* Press 3: Log-in                                        *\n");
	printf("\t* Press 4: Exit                                          *\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++\n");
	    printf("\nEnter: ");
	    scanf("%d", &choice); 
	    printf("\n");
	    system("clear");
	
		switch(choice){	//This is the first switch-case used. It offers the user to choose the first action they want the program to do
				
			case 1: reminder();
		
				break;

			case 2: printf("\t\tHello there!\t\n");
				printf("\tEnter your new account:");
					scanf("%s", account);
					new(rec, account ,a);//function call for creating a new account
					a++;
					break;
							
						
			case 3: 
				printf("\tEnter your...\n");
				printf("\tAccount:");
				scanf("%s", account);
				printf("\tPassword:");
				scanf("%s", password);
				login(rec, account, password);//function call for logging-in
				break;
						
			case 4: 
				putchar('\n');//this the end of service
				printf("\t\t----------------------------------------------------------------------------------\n");
				printf("\t\tThank you for opening and using 'My Personal Phone Book!   \n");
				printf("\t\tUntil Next time, Goodbye!.                                      \n");
				printf("\t\t----------------------------------------------------------------------------------\n");
				putchar('\n');	
				break;

		      default:  	printf("\t\t-----------------------------------------------------------------------------------\n"); 
				printf("\t\tE R R O R!	     				 \n");
				printf("\t\tYou have entered an INVALID INPUT!		 \n");
				printf("\t\tPlease choose another option		         \n");
				printf("\t\t-----------------------------------------------------------------------------------\n");
				putchar('\n');
					
	       	}
		
 	}
}

//End of main program






//////////////////////////////////////////////////////////////////////////////////////////////////////Function definition////////////////////////////////////////////////////////////////////////////////////////////////////////

//This is where the "dirty work" is!





void reminder(){	//this is the function to view simple important reminders for the user
	
	fp=fopen("reminders.txt","r");//reads and open the file reminders
	
	 if(fp==NULL){

		system("clear");
                putchar('\n');
                printf("\t\t--------------------------------------------------------------------------\n");
                printf("\t\tE R R O R!                               \n");
                printf("\t\tThere is NO Reminder File in the Directory.    \n");
                printf("\t\tPlease proceed and choose another option.     \n");
                printf("\t\t----------------------------------------------------------------------------\n");
                putchar('\n');
         }

         else{
	
		char c=getc(fp);
		while(!feof(fp)){
		printf("%c",c);
		c=getc(fp);
		}
		
                putchar('\n');
                printf("\t\t-----------------------------------------------\n");
                printf("\t\tPlease choose another option. \n");
                printf("\t\t-----------------------------------------------\n");
                putchar('\n');
	

	fclose(fp);
		}
}






void new(member rec[], char b[], int c)//a function that creates a new account for an authorized access of the Phone Book
{


	int i;


	for(i=0;i<50;i++){
			
		if(strcmp(b, rec[i].account)==0){//this checks if the account entered by the user was already entered
			printf("\t\tAccount already exist.\n");
		break;
		}
		
		else if(i==49)
		{
			strcpy(rec[c].account, b);//The user will be able to login after creating his/her new account
			printf("\tEnter password:");
			scanf("%s", rec[c].password);
			putchar('\n');
			printf("\t\tSUCCESS!!\nYou can now log-in and use 'My Personal Phone Book'\n");
			putchar('\n');
			write(rec, c);//function call to store the user information in a file
			
		break;
		}
	}
}





void login(member rec[], char d[], char e[]){//a function for the logging-in process of the member


int i;
	
	for(i=0;i<50;i++){
			
		if(strcmp(d, rec[i].account)==0){//determines if the entered account is a member
	
			if(strcmp(e, rec[i].password)==0){//checks if the user's password is correct and let him/her log-in successfully
				
				system("clear");
				newuser(rec, i);//calls the function where the user will give some personal info				
				break;
			}
				
			else{
				printf("\t\tINVALID PASSWORD!!\n\n\n");//displays an legitimate account but entered an invalid password
				break;
			}
		}
			
		else if(i==49){

			printf("\t\tACCOUNT DO NOT EXIST!\n");//displays that the account entered is illegitimate so the user cannot add a contact list
			break;
			}
	}
			
}






void write(member rec[], int f){//function that records to a file the list of all created accounts during the execution of the program

	int i;

	fp=fopen("member.txt", "w");//writes to the file named member.txt the record of the created account
		
		for(i=0; i<=f;i++){
			
			fprintf(fp, "User %d:\n", i+1);
			fprintf(fp, "Account:  %s\n", rec[i].account);
			fprintf(fp, "Password: %s\n\n\n", rec[i].password);
		}
		
	fclose(fp);

}



void newuser(member rec[], int r){//function to input some required information about the user
		
	
		system("clear");
		printf("\t-------------------------------------------------------------------\n");
		printf("\tYou have succesfully logged-in in 'My Personal Phone Book' \n");
		printf("\tFirst, share (just a little) personal information about you.     \n");
		printf("\t  	   Please enter the following		      \n");
		printf("\t-------------------------------------------------------------------\n");
		putchar('\n');
	fp=fopen("userinfos.txt","w");//create or append the old stored file in the directory

	{	
		
	
			printf("\t\tUser %d:\n", r+1);
			printf("\tNick name: ");
			scanf("\t%s", profile[r].name);
			printf("\tAge:");
		    	scanf("\t%d", &profile[r].age);
			printf("\tTel No#: ");
			scanf("\t%s", profile[r].tel);
			printf("\tCel No#: ");
			scanf("\t%s", profile[r].cel);
			printf("\tE-mail:");
			scanf("\t%s", profile[r].eadd);
			putchar('\n');
	
	//this stores the entered info in the files
			fprintf(fp, "\nYou are... %s", profile[r].name);
			fprintf(fp, "\nAge... %d", profile[r].age);
			fprintf(fp, "\nContact No#... \nTel No#: %s Cel No#: %s", profile[r].tel, profile[r].cel);
			fprintf(fp, "\nE-mail address... %s ", profile[r].eadd);
			putchar('\n');
		
	}
	
	fclose(fp);
	system("clear");


	putchar('\n');
	putchar('\n');
	printf("\t\t-----------------------------------------------\n");
    	printf("\t\tThank you for the few information about you     \n");
    	printf("\t\t-----------------------------------------------\n");
    	putchar('\n');
    	putchar('\n');
	record(profile, r);

}


void record(user profile[], int g){//the function to add new contact list and delete the old stored contact list plus the current one created

	int choose, option;
		system("clear");
		printf("\n\n\t     	   	  Hello %s!!      		 \n", profile[g].name);
		printf("\t         Now you can use the program            	 \n");
		printf("\t     		Enter you choice 		 \n");		
	
	while(choose!=6){
		printf("\t=================================================\n");
		printf("\t*    Press 1 to View %s's profile.               	*\n", profile[g].name);
		printf("\t*    Press 2 to Add a new contact.               	*\n");
		printf("\t*    Press 3 to Display all contacts.              	*\n");
		printf("\t*    Press 4 to Search a contact.		   	*\n");
		printf("\t*    Press 5 to Delete all contacts.                 *\n");
		printf("\t*    Press 6 to Log-out                        	*\n");//this choice goes back to the main
		printf("\t=================================================\n");
			printf("\nEnter: ");
			scanf("%d", &choose); 
			printf("\n");
			system("clear");


	switch(choose){
		
		case 1: pro(profile, g);//function call to add new contact
		
			break;		
		
		case 2: addcontact();//function call to add new contact
		
			break;

		case 3:	printf("How do you want to see it? \n");
			printf("Press [1] View new list alphabetically\n");
			printf("Press [2] View stored file\n");
				printf("\nEnter: ");
				scanf("%d", &option);

					if(option==1) sorted(contact, list);//function call to sort and view it alphabetically
					else if(option==2)  viewall();//function call to view it all in the stored file without sorting it
					else printf("INVALID INPUT!\n");//the user entered an invalid input
		

			break;

		case 4: searchcontact();//function call to search a contact recently added by the user

			break;

		case 5: erase();//funtion call to delete all information entered in the contact list in the stored old file and the recently entered.
			
			break;

	    	case 6: //the user will go back to main function			
			break;

		default: printf("\t\t--------------------------------------------------\n");
			 printf("\t\tE R R O R!                            \n");
			 printf("\t\tYou have entered an INVALID INPUT!     \n");
			 printf("\t\tPlease choose another option             \n");
			 printf("\t\t-----------------------------------------------\n");
			 putchar('\n');
		}
	}
}



void pro(user profile[], int r){//function for viewing the profile of the current user
	system("clear");
	printf("\t\tUser %d:\n", r+1);
	putchar('\n');
	printf("\tNickname: %s  Age:  %d", profile[r].name, profile[r].age);
	putchar('\n');
	printf("\tTel No#: %s  Cel No#: %s ", profile[r].tel, profile[r].cel);
	putchar('\n');
	printf("\tE-mail:");
	printf("\t%s", profile[r].eadd);
	putchar('\n');
	putchar('\n');

}






void addcontact(){//this is the function to add contacts in the user's new list

	int i, j;

	printf("\t\tHow many contact/s you will add in your list?  ");//question to identify how many contact to be entered by the current user
	scanf("\t\t%d", &list);
	putchar('\n');

    
	fp=fopen("contacts.txt","a");//create or append the old stored file in the directory

	{	
		for( i=0; i<list; i++ ){
	
			printf("\t\tContact %d:\n", i+1);
			printf("\tFirst name(no space):");
			scanf("\t%s", contact[i].name.first);
			printf("\tLast name(no space):");
		    	scanf("\t%s", contact[i].name.last);
			printf("\tTelephone No#: ");
			scanf("\t%s", contact[i].tel);
			printf("\tCellphone No#: ");
			scanf("\t%s", contact[i].cel);
			printf("\tE-mail:");
			scanf("\t%s", contact[i].eadd);
	
	//the new entered contact list will be saved automatically in the old stored file in the directory
			fprintf(fp, "\nFullname: %s %s", contact[i].name.first,contact[i].name.last);
			fprintf(fp, "Tel No#:     %s\nCel No#:   %s\n", contact[i].tel,contact[i].cel);
			fprintf(fp, "E-mail:   %s\n", contact[i].eadd);
			putchar('\n');
		}
	}
	
	fclose(fp);
	system("clear");


	putchar('\n');
	putchar('\n');
	printf("\t\t-----------------------------------------------\n");
    	printf("\t\tThank you for adding your new contact/s        \n");
    	printf("\t\tPlease choose another option                   \n");
    	printf("\t\t-----------------------------------------------\n");
    	putchar('\n');
    	putchar('\n');
}





void sorted(info s[], int n){//function to sort the list recently entered by the user alphabetically

	int y,z, temp;
	info temp2;

		if(contact==NULL){
			printf("ERROR");
		}
		else{
			for(y=0;y<n-1;y++){
				for(z=y+1;z<n;z++){
					temp=strcmp(s[y].name.last, s[z].name.last);//checks which last name will go first

					if(temp>0){
						temp2=s[y];
						s[y]=s[z];
						s[z]=temp2;
					}
				}

			}

		for(y=0;y<n;y++){//for loop that prints out the sorted contacts
        		printf("%s, %s \n", s[y].name.last, s[y].name.first);
			printf("%s \n", s[y].tel);
			printf("%s \n", s[y].cel);
			printf("%s\n\n", s[y].eadd);
    		}
	}
}






void viewall(){//this reads the files,therefore it will print all the contacts in the old stored list.
	
	fp=fopen("contacts.txt","r");//opens the contacts file
	
		if(fp==NULL){

			system("clear");
                        putchar('\n');
		        printf("\t\t-----------------------------------------------\n");
		        printf("\t\tE R R O R!                                     \n");
		        printf("\t\tThere is NO Contact List in the Directory yet. \n");
		        printf("\t\tPlease choose another option.                  \n");
		        printf("\t\t-----------------------------------------------\n");
		        putchar('\n');
                    }

               else{
			system("clear");
			char c=getc(fp);
			while(!feof(fp)){
			printf("%c",c);
			c=getc(fp);
			}
		
		putchar('\n');
                putchar('\n');
                printf("\t\t-----------------------------------------------\n");
                printf("\t\tPlease choose another option.                  \n");
                printf("\t\t-----------------------------------------------\n");
                putchar('\n');
                putchar('\n');
	
	fclose(fp);
		}
}





void searchcontact(){//function to search the entered name the user want to find in the recently entered contact list of the user

	int h;
	char givename[50], compare[50];
	
		printf("\t\tOBSERVE CASE SENTIVITY\n");//reminds the user that he/she must enter the name in how he/she added it
		putchar('\n');
		printf("\t\tEnter name of the entered contact to search: ");
		scanf("%s", givename);//the name to be search
		putchar('\n');
		putchar('\n');

        for ( h=0; h<list; h++ ){
               
		 if ( strcmp( givename, contact[h].name.first )==0 ){//determines if the name is in the list

			    system("clear");                            
			    printf("\t\t%s :\n", givename);//found name will be in the output
                            putchar('\n');
                            searched(contact[h]);//function call to display the searched contact's information
                            strcpy( compare, contact[h].name.first);
                    }
            }
        if( strcmp( givename, compare )==0 ){//checks if the name exists in the list
		
		putchar('\n');
		putchar('\n');
		printf("\t\t-----------------------------------------------\n");
		printf("\t Please choose another option. \n");
		printf("\t\t-----------------------------------------------\n");
		putchar('\n');
		putchar('\n');
	}
        else{
		system("clear");//gives an error message if the name was not in the list
                printf("\t\t---------------------------------------------------------------\n");
                printf("\t\tE R R O R!\n");
                printf("\t\tSorry but the name you entered is not in your list of contacts.\n");
                printf("\t\tPlease try again using a different name.\n");
                printf("\t\t---------------------------------------------------------------\n");
                putchar('\n');
            }
}





void searched(info ss){//function called by the search contact to display the information of the searched name

	printf("\t\tName: %s %s\n", ss.name.last,ss.name.first);
	printf("\t\tTel No#: %s\n", ss.tel);
	printf("\t\tCel No#: %s\n", ss.cel);
	printf("\t\tE-mail: %s\n", ss.eadd);

	putchar('\n');
	putchar('\n');
}





void erase(){//function to delete all recently entered contact list and the old stored contact list in the saved file
	char c=getc(fp);
	
	fp=fopen("contacts.txt", "w");

		putchar('\n');
		system("clear");
                putchar('\n');
                printf("\t\t-----------------------------------------------\n");
		printf("\t\tSuccess!                                       \n");
		printf("\t\tAll contacts in the list were deleted!            \n");
                printf("\t\tPlease choose another option.                  \n");
                printf("\t\t-----------------------------------------------\n");
                putchar('\n');
                putchar('\n');

	fclose(fp);
	
}//the user may or may not enter new contact list and log-out and exit the program 'My Personal Phone Book'





/*
  ++++++++++++++++++++++++++++++++++++++++++++++++-PROJECT ASSIGNMENT-+++++++++++++++++++++++++++++++++++++++++++++++++++

					   >>>>>>>>>"My (mini) Personal Phone Book<<<<<<<<<< 
				
							  END OF PROGRAM


XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

References: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~I can't do this wthou them~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	Ms. Kristela Mae-Joy Valentin { for helping me construct functions to add, search and delete contacts in this Mini Phone Book }
	Ms. Nicole Tibay { for teaching me how to make a function for accounts }
	
	
	Retrived 25 September 2010 from..
	
	Dot Net Perls, Sam Allen.
		http://dotnetperls.com/array-parameter
	Java2s
		http://www.java2s.com/Code/C/String/Stringcomparehowtousestrncmp.htm
		http://www.java2s.com/Code/C/String/Searchstring.htm
		http://www.java2s.com/Code/C/Structure/CatalogStructure.htm
	Cprogramming
		http://www.cprogramming.com/tutorial/lesson9.html
		http://cboard.cprogramming.com/c-programming/
	
	

*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
