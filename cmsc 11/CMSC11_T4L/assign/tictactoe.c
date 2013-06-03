
Description: a program that executes the game tic-tac-toe
that inputs and prints the moves of player x or player o*/

#include<stdio.h>

char board(int r, int c); // function prototype for printing the board of the game
char coordinates(int r, int c, char w);// function prototype for printing the input of the player
char sign(); // function prototype for getting the players' sign
int col();// function prototype for getting the players' desired column
int row();// function prototype for getting the players' desired row
char winner();//checking the possibilities of winning and printing the winner

char mark[4][4]={{'0','1','2','3'},{'1','_','_','_'},{'2', '_','_','_'},{'3','_','_','_'}};//first assignment of character of the games' board; a global variable

//start of main function
main()
{
int r, c, j;//local variable for row, column and the counter
char w;// local variable for the sign
//the loop serves as the counter of moves or turns
for (j=0; j<=9; j++)
	{
		r=row();
		c=col();
		w=sign();	
		coordinates(r, c, w);
		winner();
	}
}

//prints the current status of the games
char board(int r, int c)
{
for (r=0; r<4; r++)

	{	for (c=0; c<4; c++)
		
			{
				printf("%5c", mark [r][c]);
			}				
		printf("\n");
	}
return mark[4][4];
}

//inputs the players' row, column and sign; it changes the value of certain char in the board to the player's sign
char coordinates(int r, int c, char w)
{
if ((mark[r][c]=='x')||(mark[r][c]=='o'))//checks if the position is not yet taken
printf("position is already taken!\n input another position\n");
else  if ((w=='x')||(w=='o'))//checks if the input mark is correct
{mark[r][c]=w;
board( r, c);
return mark[r][c];
}
}

// inputs the sign
char sign()
{
char w,k;
printf("please enter your mark: (x or o)\n");
	scanf("%c", &w);
	scanf("%c", &k);
if (k=='x' || k=='o')//prints if the input is wrong
return k;
else printf("incorrect input\n");
}

//inputs the column
int col()
{
int c;
printf("please enter which column you want to place your mark: (1-3)\n");
	scanf("%d",&c);
if (c<4 && c!=0)
return c;
else printf("incorrect input\n");
}

//inputs the row
int row()
{
int r;
printf("please enter which row you want to place your mark:(1-3)\n");
	scanf("%d",&r);
if (r<4 && r!=0)
return r;
else printf("incorrect input\n");
}

//identifies the winner and prints the winner
char winner()
{
int r,c;
if ((mark[1][1]==mark[1][2])&&(mark[1][3]==mark[1][2])) //all char in first row are the same
	{
		if (mark[1][1]=='x')
			printf("winner: player x\n");
		else if (mark[1][1]=='o')
			printf("winner: player 'o'\n");
	}
else if ((mark[2][1]==mark[2][2])&&(mark[2][3]==mark[2][2]))//all char in second row are the same
	{
		if (mark[2][1]=='x')
			printf("winner: player x\n");
		else if (mark[2][1]=='o')
			printf("winner: player 'o'\n");
	}
else if ((mark[3][1]==mark[3][2])&&(mark[3][3]==mark[3][2]))//all char in third row are the same
	{
		if (mark[3][1]=='x')
			printf("winner: player x\n");
		else if (mark[3][1]=='o')
			printf("winner: player 'o'\n");
	}
else  if ((mark[1][1]==mark[2][1])&&(mark[3][1]==mark[1][1]))//all char in first columns are the same
	{
		if (mark[1][1]=='x')
			printf("winner: player x\n");
		else if (mark[1][1]=='o')
			printf("winner: player 'o'\n");
	}
else  if ((mark[1][2]==mark[2][2])&&(mark[3][2]==mark[1][2]))//all char in second columns are the same
	{
		if (mark[1][2]=='x')
			printf("winner: player x\n");
		else if (mark[1][2]=='o')
			printf("winner: player 'o'\n");
	}
else  if ((mark[1][3]==mark[2][3])&&(mark[3][3]==mark[1][3]))//all char in third columns are the same
	{
		if (mark[1][3]=='x')
			printf("winner: player x\n");
		else if (mark[1][3]=='o')
			printf("winner: player 'o'\n");
	}
else  if ((mark[1][1]==mark[2][2])&&(mark[3][3]==mark[1][1]))//all char in the diagonal are the same
	{
		if (mark[2][2]=='x')
			printf("winner: player x\n");
		else if (mark[2][2]=='o')
			printf("winner: player 'o'\n");
	}
else  if ((mark[1][3]==mark[2][2])&&(mark[3][1]==mark[2][2]))//all char in the diagonal are the same
	{
		if (mark[2][2]=='x')
			printf("winner: player x\n");
		else if (mark[2][2]=='o')
			printf("winner: player 'o'\n");
	}
}
