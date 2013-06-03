
    /*     This is a program of Tic Tac Toe game compose of three rows, three columns and two characters - 'x' and 'o'.
	 The checking of the winner is done after all the spaces in the game have been filled.*/
	 

#include <stdio.h>                      //header file

void start();                           //function prototype
void check();                           //function prototype
void print();                           //function prototype
void ask();                             // function prototype

char table[4][4]={{' ','1','2','3'},{'1','_','_','_'},{'2','_','_','_'},{'3','_','_','_'}}; //global variable

main ()  
{
start();                                //function call
print();                                // function call
check();
}

void start()
{
int i,j;                                //local variables
for (i=0;i<4;i++)
{
 for (j=0;j<4;j++)                      // This function is for printing the initial table of the tic tac toe game
 { printf("%8c",table[i][j]);
 }
 putchar('\n');
 putchar('\n');
 }
}


void print()                     //This function is for asking the player the row and column where he/she wants to enter his/her character
{
int r, c, x=0;                   //local variables
char e;                          //local variables

ask();                           //function call to ask for the row number,column number and the character for the first time
for (x=0;x<8;x++)                //loops to ask for eight times the row number,column number and the character 
{
  printf("Row: ");               //asking for the row number
  scanf("%d", &r);  
  printf("Col: ");               //asking for the column number
  scanf("%d", &c);
  printf("Entry: ");             //asking for the character that will be used by the player(preferably 'x' or 'o')
  scanf("%c",&e);
  scanf("%c",&e);

  if (table[r][c]=='x'||table[r][c]=='o'){  //checking if the position entered by the player is already occupied
      printf("Position occupied.Please enter another position.\n");
      ask();                             }
	  
  else 
     {table[r][c]=e;      //assigning the character entered by the user to the previous element in the multidimentional array which is '_'
      start();}  

}
check();                  //function call
}

void ask()
{
int r, c, x=0;            //local variables
char e;

printf("Row: ");          //asking for the row number
scanf("%d", &r);
printf("Col: ");          //asking for the column number
scanf("%d", &c);
printf("Entry: ");        //asking for the character that will be used by the player(preferably 'x' or 'o')
scanf("%c",&e);
scanf("%c",&e);

table[r][c]=e;            //assigning the character entered by the user to the previous element in the multidimentional array which is '_'
start();                  //function call to print the table with the new character entered by the player
     
}

void check()              // function to check if three consecutive same characters in a straight line are entered in the array, either vertival, horizontal or diagonal
{

                                                                   //checking of characters in diagonal line
if (table[1][1]=='x'&&table[2][2]=='x'&&table[3][3]=='x')
  printf("Congratulations player 1!\n");
else if (table[1][1]=='o'&&table[2][2]=='o'&&table[3][3]=='o')
  printf("Congratulations player 2!\n");                            
  else if (table[1][3]=='x'&&table[2][2]=='x'&&table[3][1]=='x')   //if the straight character is 'x' player 1 wins, if 'o' player 2 wins
  printf("Congratulations player 1!\n");
else if (table[1][3]=='o'&&table[2][2]=='o'&&table[3][1]=='o')
  printf("Congratulations player 2!\n");

                                                                   //checking for characters in horizontal line
else if (table[1][1]=='x'&&table[1][2]=='x'&&table[1][3]=='x')
  printf("Congratulations player 1!\n");
else if (table[1][1]=='o'&&table[1][2]=='o'&&table[1][3]=='o')
  printf("Congratulations player 2!\n");
else if (table[2][1]=='x'&&table[2][2]=='x'&&table[2][3]=='x')
  printf("Congratulations player 1!\n");  
else if (table[2][1]=='o'&&table[2][2]=='o'&&table[2][3]=='o')
  printf("Congratulations player 2!\n");
else if (table[3][1]=='x'&&table[3][2]=='x'&&table[3][3]=='x')
  printf("Congratulations player 1!\n");
else if (table[3][1]=='o'&&table[3][2]=='o'&&table[3][3]=='o')
  printf("Congratulations player 2!\n");
  
                                                                   //checking of characters in vertical line
else if (table[1][1]=='x'&&table[2][1]=='x'&&table[3][1]=='x')
  printf("Congratulations player 1!\n");
else if (table[1][1]=='o'&&table[2][1]=='o'&&table[3][1]=='o')
  printf("Congratulations player 2!\n");
else if (table[1][2]=='x'&&table[2][2]=='x'&&table[3][2]=='x')
  printf("Congratulations player 1!\n");
else if (table[1][2]=='o'&&table[2][2]=='o'&&table[3][2]=='o')
  printf("Congratulations player 2!\n");
else if (table[1][3]=='x'&&table[2][3]=='x'&&table[3][3]=='x')
  printf("Congratulations player 1!\n");
else if (table[1][3]=='o'&&table[2][3]=='o'&&table[3][3]=='o')
  printf("Congratulations player 2!\n");
else printf("No winner.Try again.");
}

                                                                  //end of program