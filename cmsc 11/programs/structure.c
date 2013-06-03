/*Created by Adrian John A. Biton
    2009-25443
    CMSC 11- T1L
*/

#include <stdio.h>
#include <string.h>

typedef struct{
    int month, day, year;
} birth;

typedef struct{
    char name[20];
    birth bday;
    int quiz[3], telno;
} student;

student cs11[100];

void addnewrecord();
void searchstudent();
void display_student(student ss);
void displayall ();
void changerecord(student *ss);
void changestudent(student *ss);

int norecords;

main ()
{
    int choice;

    putchar('\n');
    putchar('\n');
    do
    {
    printf("\t\t ===============================================\n");
    printf("\t\t| Enter 1 to add a new contact                 |\n");
    printf("\t\t| Enter 2 to search contacts by their name     |\n");
    printf("\t\t| Enter 3 to display all contacts              |\n");
    printf("\t\t| Enter 4 to edit a contact                    |\n");
    printf("\t\t| Enter 5 to exit                              |\n");
    printf("\t\t ===============================================\n");
    putchar('\n');
    printf("\t\tEnter choice: ");
    scanf("%d", &choice);
    putchar('\n');

    if (choice==1)
    {
        addnewrecord();

    }
    else if (choice==2)
    {
        searchstudent();
    }
    else if (choice==3)
    {
        displayall ();
    }
    else if (choice==4)
    {
        changerecord(cs11);
    }
    }while(choice!=5);

}


void addnewrecord()
{
    int i, j;

    printf("\t\tHow many records?  ");
    scanf("\t\t%d", &norecords);
    putchar('\n');

    for( i=0; i<norecords; i++ )
    {
        printf("\t\tStudent no. %d:\n", i+1);
        printf("\t\tEnter name: ");
        scanf("%s", &cs11[i].name);
        putchar('\n');
        printf("\t\tBirthday\n");
        printf("\t\tEnter month in number: ");
        scanf("%d", &cs11[i].bday.month);
        printf("\t\tEnter day in number: ");
        scanf("%d", &cs11[i].bday.day);
        printf("\t\tEnter year in number: ");
        scanf("%d", &cs11[i].bday.year);
        putchar('\n');
        printf("\t\tQuiz scores\n");
        for ( j=0; j<3; j++)
        {
            printf("\t\tQuiz %d: ", j+1);
            scanf("%d", &cs11[i].quiz[j]);
        }
        putchar('\n');
        printf("\t\tEnter telephone number: ");
        scanf("%d", &cs11[i].telno);

        putchar('\n');
    }

    putchar('\n');
    putchar('\n');
    printf("\t\t-----------------------------------------------\n");
    printf("\t\tThank you for adding new record/s\n");
    printf("\t\tPlease choose another option\n");
    printf("\t\t-----------------------------------------------\n");
    putchar('\n');
    putchar('\n');
}


void searchstudent()
{
    char nametofind[20], compare[20];
    int position;

    printf("\t\tOBSERVE CASE SENTIVITY\n");
    printf("\t\tCapitalized all first letters\n");
    putchar('\n');
    printf("\t\tEnter name of student to search: ");
    scanf("%s", nametofind);
    putchar('\n');
    putchar('\n');

        for ( position=0; position<norecords; position++ )
            {
                if ( strcmp( nametofind, cs11[position].name )==0 )
                    {
                            printf("\t\t%s has the following information:\n", nametofind);
                            putchar('\n');
                            display_student(cs11[position]);
                            strcpy( compare, cs11[position].name);
                    }
            }
        if     ( strcmp( nametofind, compare )==0 )
            {
                putchar('\n');
                putchar('\n');
                printf("\t\t-----------------------------------------------\n");
                printf("\t\tThank you for using this program!\n");
                printf("\t\tPlease choose another option.\n");
                printf("\t\t-----------------------------------------------\n");
                putchar('\n');
                putchar('\n');
            }
        else
            {
                printf("\t\t-----------------------------------------------\n");
                printf("\t\tE R R O R!\n");
                printf("\t\tSorry but the name you entered is not registered in this program.\n");
                printf("\t\tPlease try again using a different name.\n");
                printf("\t\t-----------------------------------------------\n");
                putchar('\n');
            }
}

void display_student(student ss)
{
    printf("\t\tName: %s\n", ss.name);
    printf("\t\tBday: %d-%d-%d\n", ss.bday.month, ss.bday.day, ss.bday.year);
    printf("\t\tQuizzes: %d, %d, %d\n", ss.quiz[0], ss.quiz[1], ss.quiz[2]);
    printf("\t\tTelno: %d\n", ss.telno);

    putchar('\n');
    putchar('\n');
}

void displayall ()
{
    int p;

    printf("\t\tThis program contains the following student records:");
    putchar('\n');

    for ( p=0; p<norecords; p++)
    {
    putchar('\n');
    printf("\t\tName: %s\n", cs11[p].name);
    printf("\t\tBday: %d-%d-%d\n", cs11[p].bday.month, cs11[p].bday.day, cs11[p].bday.year);
    printf("\t\tQuizzes: %d, %d, %d\n", cs11[p].quiz[0], cs11[p].quiz[1], cs11[p].quiz[2]);
    printf("\t\tTelno: %d\n", cs11[p].telno);
    putchar('\n');
    putchar('\n');
    }

    putchar('\n');
    putchar('\n');
    printf("\t\t-----------------------------------------------\n");
    printf("\t\tPlease choose another option.\n");
    printf("\t\t-----------------------------------------------\n");
    putchar('\n');
    putchar('\n');
}

void changerecord(student *ss)
{
    char nametofind[20], compare[20];
    int position, j;

    printf("\t\tOBSERVE CASE SENTIVITY\n");
    printf("\t\tCapitalized all first letters\n");
    putchar('\n');
    printf("\t\tEnter name of student to change: ");
    scanf("%s", nametofind);
    putchar('\n');
    putchar('\n');

        for ( position=0; position<norecords; position++ )
            {
                if ( strcmp( nametofind, cs11[position].name )==0 )
                    {
                            printf("\t\t%s has the following information:\n", nametofind);
                            putchar('\n');
                            display_student(cs11[position]);
                            putchar('\n');
                            putchar('\n');
                            strcpy( compare, cs11[position].name);
                            changestudent(&cs11[position]);

                            printf("\t\t-----------------------------------------------\n");
                            printf("\t\tThe changes made has been saved.\n");

                    }
            }
        if     ( strcmp( nametofind, compare )==0 )
            {
                printf("\t\tPlease choose another option.\n");
                printf("\t\t-----------------------------------------------\n");
                putchar('\n');
            }
        else
            {
                printf("\t\t-----------------------------------------------\n");
                printf("\t\tE R R O R!\n");
                printf("\t\tSorry but the name you entered is not registered in this program.\n");
                printf("\t\tPlease try again using a different name.\n");
                printf("\t\t-----------------------------------------------\n");
                putchar('\n');
            }
}
void changestudent(student *ss)
{
        int j;
                            printf("\t\tPlease type the new changes\n");
                            printf("\t\tEnter name: ");
                            scanf("%s", &ss->name);
                            putchar('\n');
                            printf("\t\tBirthday\n");
                            printf("\t\tEnter month in number: ");
                            scanf("%d", &ss->bday.month);
                            printf("\t\tEnter day in number: ");
                            scanf("%d", &ss->bday.day);
                            printf("\t\tEnter year in number: ");
                            scanf("%d", &ss->bday.year);
                            putchar('\n');
                            printf("\t\tQuiz scores\n");

                            for ( j=0; j<3; j++)
                            {
                                printf("\t\tQuiz %d: ", j+1);
                                scanf("%d", &ss->quiz[j]);
                            }
                            putchar('\n');
                            printf("\t\tEnter telephone number: ");
                            scanf("%d", &ss->telno);

                            putchar('\n');
                            putchar('\n');
}
