#include <stdio.h>                      

void start();                           
void print();                           
void ask();                             
void equivalent();

char table[4][4]={{' ','1','2','3'},{'1','_','_','_'},{'2','_','_','_'},{'3','_','_','_'}}; 

main ()  
{
int i,j;
int r, c, x=0;                   
char e='x';  
int choice=0;
while(choice!=2){
printf("\t=================================================\n");
printf("\t*    press 1 to play easy round.                *\n");
printf("\t*    press 2 to play average round.             *\n");
printf("\t*    press 3 to play difficult round.           *\n");
printf("\t*    press 4 for instructions.                  *\n");
printf("\t*    press 5 to exit.                           *\n");
printf("\t=================================================\n");
scanf("%d", &choice);
if (choice==1)
{
start();
print();
}

void start()
{
int i,j;                                
for (i=0;i<4;i++)
{
 for (j=0;j<4;j++)                      
 { printf("%8c",table[i][j]);
 }
 putchar('\n');
 putchar('\n'); 
 }
}

void print()                     
{
int r, c, x=0;                   
char e='x';                          

for(x=0;x<9;x++){
{
ask();                   
table[r][c]=e;    
}
equivalent();
}    
}

void ask()
{
int r, c, x=0;            
char e='x';

printf("Row: ");          
scanf("%d", &r);
printf("Col: ");          
scanf("%d", &c);
printf("%c", e);        

table[r][c]=e;            
start();                   
     
}

void equivalent()
{
int r,c;
if(table[1][1]=='x')
	{
	table[r][c]='3';
	start();
	}
else if(table[1][3]=='x')
	{
	table[r][c]='2';
	start();
	}
else if(table[2][3]=='x')
	{
	table[r][c]='2';
	start();
	}
else if(table[3][1]=='x')
	{
	table[r][c]='2';
	start();
	}
else if(table[3][2]=='x')
	{
	table[r][c]='2';
	start();
	}
else if(table[1][2]=='x')
	{
	printf("game over!");
	exit( );
	}
else if(table[2][1]=='x')
	{
	printf("game over!");
	exit( );
	}
else if(table[2][2]=='x')
	{
	printf("game over!");
	exit( );	
}
}
