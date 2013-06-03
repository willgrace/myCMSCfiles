/*Tibay, Nicole I.
CMSC11 T-4L
Description: This program is named Linux Dengue Awareness Program. From the name itself, it is created for
a temporary diagnosis of Dengue fever, it is not intended to replace the actual diagnosis done in hospitals.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n=0,a;				//declarations of global variables
int answer, convert;
float pound, tempheight;
char content[1000];

typedef struct{			//structure for the user's account information
	char account[20];
	char password[20];
}accountinfo;

typedef struct{			//structure for the name identification of the patient
	char surname[20];
	char firstname[20];
	char middle[10];
}id;

typedef struct{			//structure for personal information of the patient to be diagnosed
	id name;
	int age;
	char gender[10];
	char bloodtype[10];
	float weight;
	float height;
}patient;

patient person1;			//variable declaration
accountinfo list[50];

void account1();			//declarations of functions used in the program
void diagnosis(int i);
void login(accountinfo list[50], char account[], char password[]);
void create(accountinfo list[50], char z[], int a);
void print(accountinfo list[50], int a);
void yesno();
void addinfo();
void detect();
void record(int i);
void chill();
void headache();
void paineyes();
void musclejointpain();
void nausea();
void fever();
void rushes();


main(){

account1();			//a function call for the log-in and sign-in of users at the start of the program

}


void account1()		//a function that determines if the user is authorized to access the program
{
int choice,a=0;		//local variables declarations
char password[20];
char account[20];

do{
	printf("\t\t**************************************************\n");	//displays the log-in/sign-in menu
	printf("\t\t* Welcome to Linux Dengue Awareness Program      *\n");
	printf("\t\t* This program will help you determine if        *\n");
	printf("\t\t* you are infected by the Dengue fever or        *\n");
	printf("\t\t* just experiencing common flu.                  *\n");
	printf("\t\t* To avail our program you must have an account. *\n");
	printf("\t\t**************************************************\n\n");
	printf("\t\t* Press 1: Create an account                     *\n");
	printf("\t\t* Press 2: Log-in                                *\n");
	printf("\t\t* Press 3: Exit                                  *\n");
	printf("\t\t**************************************************\n");
	printf("\t\t  Enter choice: ");
	scanf("%d", &choice);
	system("clear");
	
		switch(choice){			//a switch statement for the performance of the chosen operation
				
				case 1: 	printf("\t\tEnter new account:");
							scanf("%s", account);
							create(list, account ,a);//function call for creating a new account
							a=a+1;
							break;
							
						
				case 2: 
							printf("\t\tWelcome!\n");//function call for logging-in
							printf("\t\tAccount:");
							scanf("%s", account);
							printf("\t\tPassword:");
							scanf("%s", password);
							login(list, account, password);
							break;
						
				case 3: 		//a closing greeting before ending the program
							printf("\t\t****************************************\n");	
							printf("\t\t* Thank you for visiting our program   *\n");
							printf("\t\t* Come again!                          *\n");
							printf("\t\t****************************************\n");
							break;

		}
		
 }while(choice!=3);

}

void diagnosis(int i)							//function for the diagnosis proper
{
int option;
do{
	printf("\t\t***********************************\n");	//displays the services offered by Linux Dengue Awareness Program
	printf("\t\t*   Services offered:             *\n");
	printf("\t\t*  1. Enter patient's information *\n");
	printf("\t\t*  2. Detect patient's condition  *\n");
	printf("\t\t*  3. Record Diagnosis            *\n");
	printf("\t\t*  4. End session                 *\n");
	printf("\t\t***********************************\n");
	printf("\t\tEnter option: ");
	scanf("%d", &option);
	printf("\n");
	system("clear");

		switch(option){				//a switch statement for the execution of the chosen service
		
			case 1:	addinfo();		//function call for adding patient's information
				system("clear");
				break;

			case 2:	detect();		//function call for evaluating the patient's condition
				break;

			case 3:	record(i);		//function call for recording the result
					n=0;
				break;
		}
	}while(option!=4);

}

void addinfo(){						//a function for adding the patient's personal information
	
	printf("\t\tPatient's name: [surname] [given name] [middle initial]");
	scanf("%s %s %s", person1.name.surname,person1.name.firstname ,person1.name.middle);
	printf("\t\tAge: ");
	scanf("%d", &person1.age);
	printf("\t\tGender: ");
	scanf("%s", person1.gender);
	printf("\t\tBlood type:");
	scanf("%s", person1.bloodtype);
	printf("\t\tWeight: [in kilograms]: \n");
	printf("\t\tConvert pound to kilograms? [Yes= enter 1] [No= enter 0]");
	scanf("%d", &convert);
		
			if(convert==1)//an if-else statement for converting pound to kilograms/inputing weight in kilograms
			{
			printf("\n");
			printf("\t\tEnter weight in pound: ");
			scanf("%f", &pound);
			person1.weight=pound*0.453;
			}
			else
			{
			printf("\n");
			printf("\t\tEnter weight in kilogram: ");
			scanf("%f",&person1.weight);
			}
	
	printf("\t\tHeight: [in centimeters]\n");			
	printf("\t\t\tPress 1: Convert inches to centimeters\n");
	printf("\t\t\tPress 2: Convert foot/feet to centimeters\n");
	printf("\t\t\tPress 3: Input height in cm\n");
	printf("\t\tEnter choice:");
	scanf("%d", &convert);
		
			if(convert==1)//an if-else statement for converting inches to centimeters/ feet to centimeteres/ inputing height in centimeters
			{
			printf("\t\tEnter height in inches: ");
			scanf("%f",&tempheight);
			person1.height=tempheight*2.54;
			}
		
			else if(convert==2)
			{
			printf("\t\tEnter height in foot/feet: ");
			scanf("%f",&tempheight);
			person1.height=tempheight*30.48;
			}
			
			else
			{
			printf("\t\tEnter height: ");
			scanf("%f", &person1.height);
			}
			
	printf("\n");
}

void detect(){				//a function executing a series of questions to be responded by the user and outputs the result of the diagnosis

	chill();				//a series of function calls for the execution of the questions
	system("clear");
	headache();
	system("clear");
	paineyes();
	system("clear");
	musclejointpain();
	system("clear");
	nausea();
	system("clear");
	fever();
	system("clear");
	rushes();
	system("clear");
	printf("\t\t***************************************\n");
	printf("\t\tName: %s %s %s\n",  person1.name.surname,person1.name.firstname ,person1.name.middle);	//Displays the personal information entered by the user
	printf("\t\tAge: %d\n", person1.age);
	printf("\t\tGender: %s\n\n", person1.gender);
	printf("\t\tLinux Dengue Awareness Program DIAGNOSIS:\n\t\t%d percent probability that you are \n\t\tinfected by Dengue fever\n\n", n); //displays the analysis of the diagnosis
		if(n>=60)
		{
			printf("\t\tRESULT: You are infected by the Dengue fever.\n\t\tImmediately consult your doctor.\n\n");
		}
		else
		{
			printf("\t\tRESULT: You are under good condition or just experiencing common flu.\n\t\t\n");
		}
printf("\t\t***************************************\n\n\n");
printf("\t\tLinux Dengue Awareness Program is not accurate in nature.\n\t\tFor a more accurate diagnose of your condition,\n\t\tit is best prescibed to see your doctor.\n\n\n"); //displays a warning that the program is not an alternative for actual hospital diagnosis
}

void record(int i)				//a function that records the user's last session result
{
FILE *fp;
fp=fopen("dengue.txt","w");			//writes the result to the file named dengue.txt
fprintf(fp,"ACCOUNT: %s\n\nNAME: %s %s %s\nAGE: %d\nGENDER: %s\nBLOOD TYPE: %s\n WEIGHT: %.2f kg\n HEIGHT: %.2f cm\n", list[i].account, person1.name.surname, person1.name.firstname, person1.name.middle, person1.age, person1.gender, person1.bloodtype, person1.weight, person1.height);
fprintf(fp,"DIAGNOSIS: %d percent probability of being infected by Dengue fever\n", n);
	if(n>=60){
		fprintf(fp,"RESULT: INFECTED BY DENGUE FEVER\n");	//records to dengue.txt that the patient is positive of dengue fever
	}
	else{
		fprintf(fp,"RESULT: UNDER GOOD CONDITION or EXPERIENCING COMMON FLU\n");	//records to dengue.txt that the patient is negative of dengue fever
	}

fclose(fp);
}

void yesno()								//a function that displays the instructions for answering the questions
{
printf("\n");
printf("\t\t***************************************\n");
printf("\t\tKindly answer as honest as you can\n");
printf("\t\t[yes= enter 1][no= enter 0]\n");
printf("\t\t***************************************\n");
}

void chill()								//a function that indicates the presence of chill symptom
{
yesno();
printf("\t\tHave you been feeling cold these past days?");
scanf("%d", &answer);
	if(answer==1){
		n=n+5;							//adds 5% probability of having a dengue fever
	}
printf("\n");
printf("\t\t***************************************\n");
}

void headache()								//a function that indicates the presence of headache symptom
{
yesno();
printf("\t\tAre you having a headache?");
scanf("%d", &answer);
	if(answer==1){
		n=n+20;							//adds 20% probability of having a dengue fever
	}
printf("\n");
printf("\t\t***************************************\n");

}

void paineyes()								//a function that indicates the presence of pain in the eyes symptom
{
yesno();
printf("\t\tAre you suffering from pain behind the eyes?");
scanf("%d", &answer);
	if(answer==1){
		n=n+15;							//adds 15% probability of having a dengue fever
	}
printf("\n");
printf("\t\t***************************************\n");

}
void musclejointpain()						//a function that indicates the presence of muscle and joint pain symptom
{
yesno();
printf("\t\tAre you suffering from muscle and joint pain?");
scanf("%d", &answer);
	if(answer==1){
		n=n+15;							//adds 15% probability of having a dengue fever
	}
printf("\n");
printf("\t\t***************************************\n");

}

void nausea()							//a function that indicates the presence of nausea, vomitting or loss of appetite symptom
{
yesno();
printf("\t\tAre there any symptoms of nausea, vomitting, or loss of appetite?");
scanf("%d", &answer);
	if(answer==1){
		n=n+5;							//adds 5% probability of having a dengue fever
	}
printf("\n");
printf("\t\t***************************************\n");

}

void fever()							//a function that indicates the presence of the fever symptom
{
yesno();
printf("\t\tDo you have a fever?");
scanf("%d", &answer);
	if(answer==1){
		n=n+20;							//adds 20% probability of having a dengue fever
	}
printf("\n");
printf("\t\t***************************************\n");

}

void rushes()							//a function that indicates the presence of the rushes symptom
{
yesno();
printf("\t\tAre there any signs of rushes particularly on the face 3-4 days after the fever?");
scanf("%d", &answer);
	if(answer==1){
		n=n+20;							//adds 20% probabiblity of having a dengue fever
	}
printf("\n");
printf("\t\t***************************************\n");
printf("\n\n");
}

void create(accountinfo list[50], char z[], int a)		//a function that creates a new account for an authorized access of the diagnosis
{
int i;

		for(i=0;i<50;i++)
		{
			if(strcmp(z, list[i].account)==0)		//searches if the entered account is already existing
			{
			printf("\t\tAccount already exist.\n");
			break;
			}
		
			else if(i==49)
			{
			strcpy(list[a].account, z);			//legalize the entered account
			printf("\t\tEnter password:");
			scanf("%s", list[a].password);
			printf("\t\tYour account has been successfully created!!\n");
			print(list, a);
			break;
			}
		}
}

void login(accountinfo list[50], char x[], char y[])		//a function for the logging-in process of the member
{
int i;
	
		for(i=0;i<50;i++)
		{
			if(strcmp(x, list[i].account)==0)		//determines if the entered account is a member
			{
				if(strcmp(y, list[i].password)==0)
				{
					diagnosis(i);			//an if statement that will perform the diagnosis proper if the condition is satisfied
					system("clear");
					break;
				}
				
				else
				{
					printf("\t\tINVALID PASSWORD\n\n\n");	//displays an legitimate account but invalid password
					break;
				}
			}
			
			else if(i==49)
				{
				printf("\t\tACCOUNT NONEXISTENT\n");		//displays that the account entered is illegitimate
				break;
				}
		}
			
}

void print(accountinfo list[50], int a)				//a function that records to a file the list of all created accounts during the execution of the program
{
	int i;
	FILE *fp;
	fp=fopen("accounts.txt", "w");				//writes to the file named accounts.txt the record of the created account
		for(i=0; i<=a;i++)
		{
			fprintf(fp, "Customer #%d\nAccount: %s\n", i+1,list[i].account);
			fprintf(fp, "Password: %s\n\n\n", list[i].password);
		}
		
		fclose(fp);

}

/*End of Linux Dengue Awareness Program source code
 Yipee!!! (^.^)v
*/
