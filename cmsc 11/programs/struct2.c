#include <stdio.h>
#include <string.h>
#define N 5


typedef struct name_tag{

	char LastName[20];
	char FirstName[20];
	char Middle[5];

}FullName;

typedef struct birth_tag{

	char Month[10];
	int	day;
	int year;

}Birth;

typedef struct Info_tag{

	FullName Name;
	Birth Date;

}BirthInfo;

void addBirthday(BirthInfo a[], int x);
void sortName(BirthInfo a[], int x);
void sortYear(BirthInfo a[], int x);
void viewCelebrant(BirthInfo a[], int x);

main(){

BirthInfo person[N];
int choice1, choice2, i=0;


	do{

	printf("Select one from the choices:\n");
	printf("[1] Add Birthday Info\n");
	printf("[2] View All\n");
	printf("[3] View Birthday Celebrant\n");
	printf("[4] Exit\n");
	printf("Choice: ");
	scanf("%d", &choice1);
	printf("\n");

		switch(choice1){

		case 1: addBirthday(person, i);
				i++;
				break;

		case 2: printf("Select kind of view:\n");
				printf("[1] View alphabetically\n[2] View by year\n Choice: ");
				scanf("%d", &choice2);
				if(choice2==1) sortName(person, i);
				else if(choice2==2) sortYear(person, i);
				else printf("Invalid choice\n");
				break;

		case 3: viewCelebrant(person,i);
				break;

		case 4: return(0);

		default: printf("Choice invalid\n");
		}



	}while(choice1!=4);

}

void addBirthday(BirthInfo a[], int x){

	printf("Enter Lastname:");
	scanf("%s", a[x].Name.LastName);
	printf("Enter Firstname:");
	scanf("%s", a[x].Name.FirstName);
	printf("Enter Middle Initial:");
	scanf("%s", a[x].Name.Middle);
	printf("Enter Month of Birth:");
	scanf("%s", a[x].Date.Month);
	printf("Enter Day of Birth:");
	scanf("%d", &(a[x].Date.day));
	printf("Enter Year of Birth:");
	scanf("%d", &(a[x].Date.year));
}

void sortName(BirthInfo a[], int x){

int y,z, temp;
BirthInfo temp2;

	for(y=0;y<x-1;y++){
		for(z=y+1;z<x;z++){
			temp=strcmp(a[y].Name.LastName, a[z].Name.LastName);

				if(temp>0){
					temp2=a[y];
					a[y]=a[z];
					a[z]=temp2;
				}
		}

	}

    for(y=0;y<x;y++){
        printf("%s, %s %s\n%s %d %d\n\n\n", a[y].Name.LastName, a[y].Name.FirstName, a[y].Name.Middle, a[y].Date.Month, a[y].Date.day, a[y].Date.year);
    }
}

void sortYear(BirthInfo a[], int x){

int y, z, temp;
BirthInfo temp2;

	for(y=0;y<x-1;y++){
		for(z=y+1;z<x;z++){

             temp=a[y].Date.year-a[z].Date.year;
             if(temp>0){
                temp2=a[y];
                a[y]=a[z];
                a[z]=temp2;

             }
		}

	}
    for(y=0;y<x;y++){
            printf("%s, %d %d\n%s %s %s\n\n", a[y].Date.Month, a[y].Date.day, a[y].Date.year,
						a[y].Name.LastName, a[y].Name.FirstName, a[y].Name.Middle);
    }
}

void viewCelebrant(BirthInfo a[],int x){

char tempMonth[10];
int tempDay, tempYear, y, z, args=0;

	printf("What is the Birthday of the Celebrant?\n");
	printf("Month: ");
	scanf("%s", tempMonth);
	printf("Day: ");
	scanf("%d", &tempDay);
	printf("Year: ");
	scanf("%d", &tempYear);

		for(y=0; y<=x; y++){

		z=strcmp(tempMonth,a[y].Date.Month);
			if(z==0){
				if(tempDay==a[y].Date.day){
					if(tempYear==a[y].Date.year){
						printf("%s, %d %d\n%s %s %s\n\n", a[y].Date.Month, a[y].Date.day, a[y].Date.year,
						a[y].Name.LastName, a[y].Name.FirstName, a[y].Name.Middle);
						args=args+1;
					}
				}
			}

		}
		if(args==0)	
			printf("No result found.\n");
}

