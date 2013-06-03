/*Minesweeper*/

#include <stdio.h>                      
#include <stdlib.h>

void start();                           
void print();                           
void ask();                             
void equivalent();
void easy();
void ave();
void start1();                           
void print1();                           
void ask1();                             
void equivalent1();
void choices();
void file();
void printall();
void difficult();
void start2();                           
void print2();                           
void ask2();                             
void equivalent2();

char table[4][4]={{' ','1','2','3'},{'1','_','_','_'},{'2','_','_','_'},{'3','_','_','_'}}; 
char table1[7][7]={{' ','1','2','3','4','5','6'},{'1','_','_','_','_','_','_'},{'2','_','_','_','_','_','_'},{'3','_','_','_','_','_','_'},{'4','_','_','_','_','_','_'},{'5','_','_','_','_','_','_'},{'6','_','_','_','_','_','_'},}; 
char table2[13][13]={{' ','1','2','3','4','5','6','7','8','9','A','B','C'},{'1','_','_','_','_','_','_','_','_','_','_','_','_'},{'2','_','_','_','_','_','_','_','_','_','_','_','_'},{'3','_','_','_','_','_','_','_','_','_','_','_','_'},{'4','_','_','_','_','_','_','_','_','_','_','_','_'},{'5','_','_','_','_','_','_','_','_','_','_','_','_'},{'6','_','_','_','_','_','_','_','_','_','_','_','_'},{'7','_','_','_','_','_','_','_','_','_','_','_','_'},{'8','_','_','_','_','_','_','_','_','_','_','_','_'},{'9','_','_','_','_','_','_','_','_','_','_','_','_'},{'A','_','_','_','_','_','_','_','_','_','_','_','_'},{'B','_','_','_','_','_','_','_','_','_','_','_','_'},{'C','_','_','_','_','_','_','_','_','_','_','_','_'}}; 
FILE *fp;


main ()  
{
int o=0;
int choice=0;
while(choice!=6){
printf("\t\t  ######################################\n");
printf("\t\t  ###  ###  #    #  ##  #     ##    ####\n");
printf("\t\t  ###   #   ##  ##  ##  #  ####  ##  ###\n");
printf("\t\t  ###       ##  ##   #  #    ###   #####\n");
printf("\t\t  ###  # #  ##  ##      #  ######   ####\n");
printf("\t\t  ###  ###  ##  ##  #   #  ####  ##  ###\n");
printf("\t\t  ###  ###  #    #  ##  #     ##    ####\n");
printf("\t\t  ######################################\n");
printf("\t\t=========================================\n");
printf("\t\t*        Press 1:Instructions.          *\n");
printf("\t\t*        Press 2:Easy round.            *\n");
printf("\t\t*        Press 3:Average round.  	*\n");
printf("\t\t*        Press 4:Difficult round.  	*\n");
printf("\t\t*        Press 5:View previous game     *\n");
printf("\t\t=========================================\n");
scanf("%d", &choice);
switch(choice){
	case 1: printf("\t\t\t\tINSTRUCTIONS\n");
			printf("==============================================================================\n");
	        printf("*  Minesweeper is a puzzle game where you locate mines using only your brain *\n"); 
			printf("*  and a little bit of luck.You start the game by entering the number of the *\n");
			printf("*  row and column of your chosen blank item.What is in it:either a dash (#), *\n");
			printf("*  a number or an 'X'. If you found an 'X', it means the game is over. If you*\n");
			printf("*  uncovered a dash(#) or a number , you survive and get to try again. The   *\n");
			printf("*  numbers might help you in predicting the location of 'X'. It tells how    *\n");
			printf("*  many 'X' are on its adjacent sides; it could be horizontal, vertical or   *\n");
			printf("*  diagonal.Once you find a few clear blanks, you can start to deduce which  *\n");
			printf("*  blank spaces have 'X' in them and which don't.You win the game once you   *\n");
			printf("*  have revealed all the un#mined space.Good luck!                           *\n");
			printf("==============================================================================\n");
			break;
	case 2: putchar('\n');
		    printf("\t\t***************\n");
		    printf("\t\t*  EASY ROUND *\n");
		    printf("\t\t***************\n");
		    printf("\n \n");
			easy();
			break;
	case 3: putchar('\n');
		    printf("\t\t\t******************\n");
		    printf("\t\t\t*  AVERAGE ROUND *\n");
		    printf("\t\t\t******************\n");
		    putchar('\n');
		    ave();
		    break;
	case 4: putchar('\n');
		    printf("\t\t\t********************\n");
		    printf("\t\t\t*  DIFFICULT ROUND *\n");
		    printf("\t\t\t********************\n");
		    putchar('\n');
		    printf("##############note:rows&columns (A=10,A=11,A=12)#################\n");
			putchar('\n');
			difficult();
		    break;
	case 5: printall();
			break;
		}
}
}


void easy()
{
int x;
start();
print();
file();
if (x=7)
{
printf("\t\t**********************************\n");
printf("\t\t*    Congratulations!You won!    *\n");
printf("\t\t**********************************\n");
putchar('\n');
}
}

void file()
{
int i,j;
char r = 'equivalent()';          
fp=fopen("mines.txt","a");
{
fprintf(fp,"%8c",r);
}
putchar('\n');
fclose(fp);
}

void printall()
{
	char c=getc(fp);
	fp=fopen("mines.txt","r");
	while(c!=EOF){
	printf("%d",c);
	c=getc(fp);
	}
	printf("\t\tpress the number of your desired action.\n");
	putchar('\n');
	fclose(fp);
}
	
void choices()
{
int a;
int choice;
while(choice!=6){
printf("\t\t  ######################################\n");
printf("\t\t  ###  ###  #    #  ##  #     ##    ####\n");
printf("\t\t  ###   #   ##  ##  ##  #  ####  ##  ###\n");
printf("\t\t  ###       ##  ##   #  #    ###   #####\n");
printf("\t\t  ###  # #  ##  ##      #  ######   ####\n");
printf("\t\t  ###  ###  ##  ##  #   #  ####  ##  ###\n");
printf("\t\t  ###  ###  #    #  ##  #     ##    ####\n");
printf("\t\t  ######################################\n");
printf("\t\t=========================================\n");
printf("\t\t*        Press 1:Instructions.          *\n");
printf("\t\t*        Press 2:Easy round.            *\n");
printf("\t\t*        Press 3:Average round.  	*\n");
printf("\t\t*        Press 4:Difficult round.  	*\n");
printf("\t\t*        Press 5:View previous game     *\n");
printf("\t\t*        Press 6:Exit game.        	*\n");
printf("\t\t=========================================\n");
scanf("%d", &choice);
switch(choice){
	case 1: printf("\t\t\t\tINSTRUCTIONS\n");
			printf("==============================================================================\n");
	        printf("*  Minesweeper is a puzzle game where you locate mines using only your brain *\n"); 
			printf("*  and a little bit of luck.You start the game by entering the number of the *\n");
			printf("*  row and column of your chosen blank item.What is in it:either a dash (#), *\n");
			printf("*  a number or an 'X'. If you found an 'X', it means the game is over. If you*\n");
			printf("*  uncovered a dash(#) or a number , you survive and get to try again. The   *\n");
			printf("*  numbers might help you in predicting the location of 'X'. It tells how    *\n");
			printf("*  many 'X' are on its adjacent sides; it could be horizontal, vertical or   *\n");
			printf("*  diagonal.Once you find a few clear blanks, you can start to deduce which  *\n");
			printf("*  blank spaces have 'X' in them and which don't.You win the game once you   *\n");
			printf("*  have revealed all the un#mined space.Good luck!                           *\n");
			printf("==============================================================================\n");
			break;
	case 2: putchar('\n');
		    printf("\t\t***************\n");
		    printf("\t\t*  EASY ROUND *\n");
		    printf("\t\t***************\n");
		    putchar('\n');
		    easy();
		    break;
	case 3: putchar('\n');
		    printf("\t\t\t******************\n");
		    printf("\t\t\t*  AVERAGE ROUND *\n");
		    printf("\t\t\t******************\n");
		    putchar('\n');
		    ave();
		    break;
	case 4: putchar('\n');
		    printf("\t\t\t********************\n");
		    printf("\t\t\t*  DIFFICULT ROUND *\n");
		    printf("\t\t\t********************\n");
		    putchar('\n');
		    difficult();
		    break;
	case 5: file();
			printall();
			break;
	default:printf("\t\t\t##########CLOSE GAME###########\n");
			putchar('\n');
			exit(1);
			}
}
}

void start()
{
int i,j;                                
for (i=0;i<4;i++)
{
 for (j=0;j<4;j++)                      
 { 
 printf("%8c",table[i][j]);
 }
 putchar('\n');
 putchar('\n'); 
 }
}

void print()                     
{
int r, c, x;                                  
for(x=1;x<7;x++){
{
ask();                   
}
equivalent();
}    
}

void ask()
{
int r, c;            
char e='x';
printf("Row: ");          
scanf("%d", &r);
printf("Col: ");          
scanf("%d", &c);
printf("%c", e);                           
table[r][c]=e;    
}

void equivalent()
{
if(table[1][1]=='x')
	{
	table[1][1]='3';
	start();
	}
else if(table[1][3]=='x')
	{
	table[1][3]='2';
	start();
	}
else if(table[2][3]=='x')
	{
	table[2][3]='2';
	start();
	}
else if(table[3][1]=='x')
	{
	table[3][1]='2';
	start();
	}
else if(table[3][2]=='x')
	{
	table[3][2]='2';
	start();
	}
else if(table[3][3]=='x')
	{
	table[3][3]='1';
	start();
	}
else if(table[1][2]=='x')
	{
	printf("game over!\n");  
	choices();
	}
else if(table[2][1]=='x')
	{
	printf("game over!\n");
	choices();
	}
else if(table[2][2]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
}///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ave()
{
int x;
start1();
print1();
if (x=30){
printf("\t\t**********************************\n");
printf("\t\t*    Congratulations!You won!    *\n");
printf("\t\t**********************************\n");
putchar('\n');
}
}

void start1()
{
int i,j;                                
for (i=0;i<7;i++)
{
 for (j=0;j<7;j++)                      
 { printf("%8c",table1[i][j]);
 }
 putchar('\n');
 putchar('\n'); 
 }
}

void print1()                     
{
int r, c, x;                   
char e='x';                       

for(x=1;x<30;x++){
{
ask1();                   
}
equivalent1();
}    
}

void ask1()
{
int r, c, x=0;            
char e='x';

printf("Row: ");          
scanf("%d", &r);
printf("Col: ");          
scanf("%d", &c);
printf("%c", e);                           
table1[r][c]=e;    
}

void equivalent1()
{
int r,c;

if(table1[1][2]=='x')
	{
	table1[1][2]='1';
	start1();
	}
else if(table1[1][3]=='x')
	{
	table1[1][3]='#';
	start1();
	}
else if(table1[1][4]=='x')
	{
	table1[1][4]='1';
	start1();
	}
else if(table1[1][5]=='x')
	{
	table1[1][5]='1';
	start1();
	}
else if(table1[1][6]=='x')
	{
	table1[1][6]='1';
	start1();
	}
else if(table1[2][1]=='x')
	{
	table1[2][1]='1';
	start1();
	}
else if(table1[2][2]=='x')
	{
	table1[2][2]='2';
	start1();
	}
else if(table1[2][3]=='x')
	{
	table1[2][3]='1';
	start1();
	}
else if(table1[2][4]=='x')
	{
	table1[2][4]='2';
	start1();
	}
else if(table1[2][6]=='x')
	{
	table1[2][6]='1';
	start1();
	}
else if(table1[3][1]=='x')
	{
	table1[3][1]='1';
	start1();
	}
else if(table1[3][2]=='x')
	{
	table1[3][2]='2';
	start1();
	}
else if(table1[3][4]=='x')
	{
	table1[3][4]='2';
	start1();
	}
else if(table1[3][5]=='x')
	{
	table1[3][5]='1';
	start1();
	}
else if(table1[3][6]=='x')
	{
	table1[3][6]='1';
	start1();
	}
else if(table1[4][1]=='x')
	{
	table1[4][1]='1';
	start1();
	}
else if(table1[4][3]=='x')
	{
	table1[4][3]='3';
	start1();
	}
else if(table1[4][4]=='x')
	{
	table1[4][4]='2';
	start1();
	}
else if(table1[4][5]=='x')
	{
	table1[4][5]='#';
	start1();
	}
else if(table1[4][6]=='x')
	{
	table1[4][6]='#';
	start1();
	}
else if(table1[5][1]=='x')
	{
	table1[5][1]='1';
	start1();
	}
else if(table1[5][2]=='x')
	{
	table1[5][2]='2';
	start1();
	}
else if(table1[5][4]=='x')
	{
	table1[5][4]='1';
	start1();
	}
else if(table1[5][5]=='x')
	{
	table1[5][5]='1';
	start1();
	}
else if(table1[5][6]=='x')
	{
	table1[5][6]='1';
	start1();
	}
else if(table1[6][1]=='x')
	{
	table1[6][1]='#';
	start1();
	}
else if(table1[6][2]=='x')
	{
	table1[6][2]='1';
	start1();
	}
else if(table1[6][3]=='x')
	{
	table1[6][3]='1';
	start1();
	}
else if(table1[6][4]=='x')
	{
	table1[6][4]='1';
	start1();
	}
else if(table1[6][5]=='x')
	{
	table1[6][5]='1';
	start1();
	}
else if(table1[1][1]=='x')
	{
	printf("game over!\n");
    choices();
	}
else if(table1[2][5]=='x')
	{
	printf("game over!\n");
	choices();
	}
else if(table1[3][3]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
else if(table1[4][2]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
else if(table1[5][3]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
else if(table1[6][6]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void difficult()
{
int x;

start2();
print2();
file();
if (x=132){
printf("\t\t**********************************\n");
printf("\t\t*    Congratulations!You won!    *\n");
printf("\t\t**********************************\n");
putchar('\n');
}
}

void start2()
{
int i,j;                                
for (i=0;i<13;i++)
{
 for (j=0;j<13;j++)                      
 { printf("%5c",table2[i][j]);
 }
 putchar('\n');
 putchar('\n'); 
 }
}


void print2()                     
{
int r, c, x;                   
char e='x';                       

for(x=1;x<132;x++){
{
ask2();                   
}
equivalent2();
}    
}

void ask2()
{
int r, c, x=0;            
char e='x';

printf("Row: ");          
scanf("%d", &r);
printf("Col: ");          
scanf("%d", &c);
printf("%c", e);                           
table2[r][c]=e;    
}

void equivalent2()
{
if(table2[1][1]=='x')
	{
	table2[1][1]='#';
	start2();
	}
else if(table2[1][2]=='x')
	{
	table2[1][2]='#';
	start2();
	}
else if(table2[1][3]=='x')
	{
	table2[1][3]='1';
	start2();
	}
else if(table2[1][5]=='x')
	{
	table2[1][5]='1';
	start2();
	}
else if(table2[1][6]=='x')
	{
	table2[1][6]='#';
	start2();
	}
else if(table2[1][7]=='x')
	{
	table2[1][7]='1';
	start2();
	}
else if(table2[1][8]=='x')
	{
	table2[1][8]='1';
	start2();
	}
else if(table2[1][9]=='x')
	{
	table2[1][9]='1';
	start2();
	}
else if(table2[1][10]=='x')
	{
	table2[1][10]='#';
	start2();
	}
else if(table2[1][11]=='x')
	{
	table2[1][11]='#';
	start2();
	}
else if(table2[1][12]=='x')
	{
	table2[1][12]='#';
	start2();
	}
else if(table2[2][1]=='x')
	{
	table2[2][1]='#';
	start2();
	}
else if(table2[2][2]=='x')
	{
	table2[2][2]='#';
	start2();
	}
else if(table2[2][3]=='x')
	{
	table2[2][3]='1';
	start2();
	}
else if(table2[2][4]=='x')
	{
	table2[2][4]='2';
	start2();
	}
else if(table2[2][5]=='x')
	{
	table2[2][5]='2';
	start2();
	}
else if(table2[2][6]=='x')
	{
	table2[2][6]='1';
	start2();
	}
else if(table2[2][7]=='x')
	{
	table2[2][7]='1';
	start2();
	}
else if(table2[2][9]=='x')
	{
	table2[2][9]='1';
	start2();
	}
else if(table2[2][10]=='x')
	{
	table2[2][10]='#';
	start2();
	}
else if(table2[2][11]=='x')
	{
	table2[2][11]='#';
	start2();
	}
else if(table2[2][12]=='x')
	{
	table2[2][12]='#';
	start2();
	}
else if(table2[3][1]=='x')
	{
	table2[3][1]='#';
	start2();
	}
else if(table2[3][2]=='x')
	{
	table2[3][2]='1';
	start2();
	}
else if(table2[3][3]=='x')
	{
	table2[3][3]='1';
	start2();
	}
else if(table2[3][4]=='x')
	{
	table2[3][4]='2';
	start2();
	}
else if(table2[3][6]=='x')
	{
	table2[3][6]='1';
	start2();
	}
else if(table2[3][7]=='x')
	{
	table2[3][7]='1';
	start2();
	}
else if(table2[3][8]=='x')
	{
	table2[3][8]='1';
	start2();
	}
else if(table2[3][9]=='x')
	{
	table2[3][9]='1';
	start2();
	}
else if(table2[3][10]=='x')
	{
	table2[3][10]='1';
	start2();
	}
else if(table2[3][11]=='x')
	{
	table2[3][11]='1';
	start2();
	}
else if(table2[3][12]=='x')
	{
	table2[3][12]='1';
	start2();
	}
else if(table2[4][1]=='x')
	{
	table2[4][1]='#';
	start2();
	}
else if(table2[4][2]=='x')
	{
	table2[4][2]='#';
	start2();
	}
else if(table2[4][4]=='x')
	{
	table2[4][4]='2';
	start2();
	}
else if(table2[4][5]=='x')
	{
	table2[4][5]='1';
	start2();
	}
else if(table2[4][6]=='x')
	{
	table2[4][6]='1';
	start2();
	}
else if(table2[4][7]=='x')
	{
	table2[4][7]='#';
	start2();
	}
else if(table2[4][8]=='x')
	{
	table2[4][8]='#';
	start2();
	}
else if(table2[4][9]=='x')
	{
	table2[4][9]='#';
	start2();
	}
else if(table2[4][10]=='x')
	{
	table2[4][10]='1';
	start2();
	}	
else if(table2[4][12]=='x')
	{
	table2[4][12]='1';
	start2();
	}	
else if(table2[5][1]=='x')
	{
	table2[5][1]='#';
	start2();
	}
else if(table2[5][2]=='x')
	{
	table2[5][2]='1';
	start2();
	}
else if(table2[5][3]=='x')
	{
	table2[5][3]='1';
	start2();
	}
else if(table2[5][4]=='x')
	{
	table2[5][4]='1';
	start2();
	}
else if(table2[5][5]=='x')
	{
	table2[5][5]='#';
	start2();
	}
else if(table2[5][6]=='x')
	{
	table2[5][6]='#';
	start2();
	}
else if(table2[5][7]=='x')
	{
	table2[5][7]='#';
	start2();
	}
else if(table2[5][8]=='x')
	{
	table2[5][8]='#';
	start2();
	}
else if(table2[5][9]=='x')
	{
	table2[5][9]='1';
	start2();
	}
else if(table2[5][10]=='x')
	{
	table2[5][10]='2';
	start2();
	}
else if(table2[5][11]=='x')
	{
	table2[5][12]='2';
	start2();
	}
else if(table2[5][12]=='x')
	{
	table2[5][12]='1';
	start2();
	}	
else if(table2[6][1]=='x')
	{
	table2[6][1]='#';
	start2();
	}
else if(table2[6][2]=='x')
	{
	table2[6][2]='#';
	start2();
	}
else if(table2[6][3]=='x')
	{
	table2[6][3]='3';
	start2();
	}
else if(table2[6][4]=='x')
	{
	table2[6][4]='#';
	start2();
	}
else if(table2[6][5]=='x')
	{
	table2[6][5]='#';
	start2();
	}
else if(table2[6][6]=='x')
	{
	table2[6][6]='#';
	start2();
	}
else if(table2[6][7]=='x')
	{
	table2[6][7]='#';
	start2();
	}
else if(table2[6][8]=='x')
	{
	table2[6][8]='#';
	start2();
	}
else if(table2[6][9]=='x')
	{
	table2[6][9]='1';
	start2();
	}
else if(table2[6][11]=='x')
	{
	table2[6][11]='2';
	start2();
	}
else if(table2[6][12]=='x')
	{
	table2[6][12]='1';
	start2();
	}
else if(table2[7][1]=='x')
	{
	table2[7][1]='#';
	start2();
	}
else if(table2[7][2]=='x')
	{
	table2[7][2]='#';
	start2();
	}
else if(table2[7][3]=='x')
	{
	table2[7][3]='#';
	start2();
	}
else if(table2[7][4]=='x')
	{
	table2[7][4]='#';
	start2();
	}
else if(table2[7][5]=='x')
	{
	table2[7][5]='#';
	start2();
	}
else if(table2[7][6]=='x')
	{
	table2[7][6]='1';
	start2();
	}
else if(table2[7][7]=='x')
	{
	table2[7][7]='1';
	start2();
	}
else if(table2[7][8]=='x')
	{
	table2[7][8]='#';
	start2();
	}
else if(table2[7][9]=='x')
	{
	table2[7][9]='1';
	start2();
	}
else if(table2[7][10]=='x')
	{
	table2[7][10]='1';
	start2();
	}
else if(table2[7][11]=='x')
	{
	table2[7][11]='2';
	start2();
	}
else if(table2[8][1]=='x')
	{
	table2[8][1]='#';
	start2();
	}
else if(table2[8][2]=='x')
	{
	table2[8][2]='#';
	start2();
	}
else if(table2[8][3]=='x')
	{
	table2[8][3]='#';
	start2();
	}
else if(table2[8][4]=='x')
	{
	table2[8][4]='#';
	start2();
	}
else if(table2[8][5]=='x')
	{
	table2[8][5]='1';
	start2();
	}
else if(table2[8][6]=='x')
	{
	table2[8][6]='2';
	start2();
	}
else if(table2[8][8]=='x')
	{
	table2[8][8]='1';
	start2();
	}
else if(table2[8][9]=='x')
	{
	table2[8][9]='#';
	start2();
	}
else if(table2[8][10]=='x')
	{
	table2[8][10]='#';
	start2();
	}
else if(table2[8][11]=='x')
	{
	table2[8][11]='1';
	start2();
	}
else if(table2[8][12]=='x')
	{
	table2[8][12]='1';
	start2();
	}
else if(table2[9][1]=='x')
	{
	table2[9][1]='1';
	start2();
	}
else if(table2[9][2]=='x')
	{
	table2[9][2]='#';
	start2();
	}
else if(table2[9][3]=='x')
	{
	table2[9][3]='#';
	start2();
	}
else if(table2[9][4]=='x')
	{
	table2[9][4]='#';
	start2();
	}
else if(table2[9][5]=='x')
	{
	table2[9][5]='1';
	start2();
	}
else if(table2[9][7]=='x')
	{
	table2[9][7]='2';
	start2();
	}
else if(table2[9][8]=='x')
	{
	table2[9][8]='1';
	start2();
	}
else if(table2[9][9]=='x')
	{
	table2[9][9]='#';
	start2();
	}
else if(table2[9][10]=='x')
	{
	table2[9][10]='#';
	start2();
	}
else if(table2[9][11]=='x')
	{
	table2[9][11]='#';
	start2();
	}	
else if(table2[9][12]=='x')
	{
	table2[9][12]='#';
	start2();
	}
else if(table2[10][2]=='x')
	{
	table2[10][2]='1';
	start2();
	}
else if(table2[10][3]=='x')
	{
	table2[10][3]='#';
	start2();
	}
else if(table2[10][4]=='x')
	{
	table2[10][4]='#';
	start2();
	}
else if(table2[10][5]=='x')
	{
	table2[10][5]='1';
	start2();
	}
else if(table2[10][6]=='x')
	{
	table2[10][6]='1';
	start2();
	}
else if(table2[10][7]=='x')
	{
	table2[10][7]='1';
	start2();
	}
else if(table2[10][8]=='x')
	{
	table2[10][8]='1';
	start2();
	}
else if(table2[10][9]=='x')
	{
	table2[10][9]='1';
	start2();
	}
else if(table2[10][10]=='x')
	{
	table2[10][10]='1';
	start2();
	}
else if(table2[10][11]=='x')
	{
	table2[10][11]='#';
	start2();
	}
else if(table2[10][12]=='x')
	{
	table2[10][12]='#';
	start2();
	}
else if(table2[11][1]=='x')
	{
	table2[11][1]='2';
	start2();
	}
else if(table2[11][2]=='x')
	{
	table2[11][2]='2';
	start2();
	}
else if(table2[11][3]=='x')
	{
	table2[11][3]='1';
	start2();
	}
else if(table2[11][4]=='x')
	{
	table2[11][4]='#';
	start2();
	}
else if(table2[11][5]=='x')
	{
	table2[11][5]='#';
	start2();
	}
else if(table2[11][6]=='x')
	{
	table2[11][6]='#';
	start2();
	}
else if(table2[11][7]=='x')
	{
	table2[11][7]='#';
	start2();
	}
else if(table2[11][8]=='x')
	{
	table2[11][8]='1';
	start2();
	}
else if(table2[11][10]=='x')
	{
	table2[11][10]='1';
	start2();
	}
else if(table2[11][11]=='x')
	{
	table2[11][11]='#';
	start2();
	}
else if(table2[11][12]=='x')
	{
	table2[11][12]='#';
	start2();
	}
else if(table2[12][1]=='x')
	{
	table2[12][1]='1';
	start2();
	}
else if(table2[12][3]=='x')
	{
	table2[12][3]='1';
	start2();
	}
else if(table2[12][4]=='x')
	{
	table2[12][4]='#';
	start2();
	}
else if(table2[12][5]=='x')
	{
	table2[12][5]='#';
	start2();
	}
else if(table2[12][6]=='x')
	{
	table2[12][6]='#';
	start2();
	}
else if(table2[12][7]=='x')
	{
	table2[12][7]='#';
	start2();
	}
else if(table2[12][8]=='x')
	{
	table2[12][8]='1';
	start2();
	}
else if(table2[12][9]=='x')
	{
	table2[12][9]='1';
	start2();
	}
else if(table2[12][10]=='x')
	{
	table2[12][10]='1';
	start2();
	}
else if(table2[12][11]=='x')
	{
	table2[12][11]='#';
	start2();
	}
else if(table2[12][12]=='x')
	{
	table2[12][12]='#';
	start2();
	}	
else if(table2[1][4]=='x')
	{
	printf("game over!\n");
    choices();
	}
else if(table2[2][8]=='x')
	{
	printf("game over!\n");
	choices();
	}
else if(table2[3][5]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
else if(table2[4][3]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
else if(table2[4][11]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
else if(table2[6][10]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
else if(table2[7][12]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
else if(table2[8][7]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
else if(table2[9][6]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
else if(table2[10][1]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
else if(table2[11][9]=='x')
	{	
	printf("game over!\n");	
	choices();
	}
else if(table2[12][2]=='x')
	{	
	printf("game over!\n");	
	choices();
	}	
}


