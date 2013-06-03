#include <stdio.h>
#include <time.h>

int dice1,dice2,dice3;//variable declarations.. global variable so that these declarations will used in other functions..
int dice4,dice5,dice6;

int diceRoll();
int reRoll(int x,int y,int z);
void wait();

main(){ //all cases are performed.
int Player=1;
int m1=4000, m2=4000, bet;
int c;
while((m1!=0 && m1>0) && (m2!=0 && m2>0)){
	printf("\nPlayer %d's turn.\n",Player);
	printf("Enter your bet: ");
	scanf("%d",&bet);
	printf(" \nPlayer %d\n    M1:%d	   M2:%d\n    Bet:%d\n\n",Player,m1,m2,bet);
	c=diceRoll();//function that will roll the dice
	if(c==1){//no number in common. the p[layer lose
		printf("\nPlayer %d loses 2x!\n",Player);
			if(Player==1){	
				m1=m1-(bet*2);
				m2=m2+(bet*2);}
			else { m1=m1+(bet*2);
				   m2=m2-(bet*2);}
		}
	else if(c==2){//
		printf("\nPlayer %d wins 2x!\n",Player);
		 	if(Player==1){
		 		m1=m1+(bet*2);
				m2=m2-(bet*2);}
			else { m1=m1-(bet*2);
			   	   m2=m2+(bet*2);}
		}
	else if(c==3){
		printf("\nPlayer %d wins 3x!\n",Player);
			if(Player==1){
				m1=m1+(bet*3);
				m2=m2-(bet*3);}
			else { m1=m1-(bet*3);
				   m2=m2+(bet*3);}
		}
	else if(c==4){
		printf("\nPlayer %d wins 1x!\n",Player);
			if(Player==1){
			   m1=m1+bet;
			   m2=m2-bet;}
			else{m1=m1-bet;
				 m2=m2+bet;}
		
		}
	else if(c==5){
		printf("\nOpponent wins 1x!\n");
			if(Player==1){
			   m1=m1-bet;
			   m2=m2+bet;}
			else {m1=m1+bet;
				  m2=m2-bet;}
		}
	else if(c==6){
		printf("\nIt's a draw!\n\nChange turn.\n");
		}
	else if(c==7){
		printf("\nOpponent wins 3x!\n");
			if(Player==1){
			   m1=m1-(bet*3);
			   m2=m2+(bet*3);}
			else{m1=m1+(bet*3);
				 m2=m2-(bet*3);}
		}
	printf("       **********************************\n");
	printf("       *     Player 1            Player 2    *\n");
	printf("       * Money1: %d          Money2: %d  *\n",m1,m2);
	printf("       **********************************\n");
	
	if(Player==1)
	Player++;
	else if(Player==2)
	Player--;
	}
if(m1<=0) printf("\nPlayer 2 wins the game!!\n\n");
else if(m2<=0) printf("\nPlayer 1 wins the game!!\n\n");
}

int diceRoll(){    //to get the value of dice.will return if 1 if the value of the 3 dice vary from 1 to 3. return 2 if the values are from 4-6. return 3 if the values of the 3 dice are equal.
int d,command;
srand(time(NULL));
wait();
dice1=(rand()%6)+1;
wait();
dice2=(rand()%6)+1;
wait();
dice3=(rand()%6)+1;
printf("\nDice roll: %d %d %d\n",dice1,dice2,dice3);
if ((dice1==1 && dice2==2 && dice3==3)||
	(dice1==1 && dice2==3 && dice3==2)||
	(dice1==2 && dice2==1 && dice3==3)||
	(dice1==2 && dice2==3 && dice3==1)||
	(dice1==3 && dice2==2 && dice3==1)||
	(dice1==3 && dice2==1 && dice3==2)) return 1;

else if ((dice1==4 && dice2==5 && dice3==6)||
		 (dice1==4 && dice2==6 && dice3==5)||
		 (dice1==5 && dice2==4 && dice3==6)||
		 (dice1==5 && dice2==6 && dice3==4)||
		 (dice1==6 && dice2==4 && dice3==5)||
		 (dice1==6 && dice2==5 && dice3==4)) return 2;

else if (dice1==dice2 && dice1==dice3) return 3;
		
else if (dice1==dice2 || dice1==dice3){// will print the value indicated in the dice 1. and it will be the point/s of the player who roll the dice.
		printf("\nYour points: %d\n",dice1);
		printf("Opponent will also roll the dice.\n");
		d=reRoll(dice1,dice2,dice3);
		if(d==1) return 2;
		else if(d==2) return 1;
		else if(d==3) return 7;
		else if(d==4) return 4;
		else if(d==5) return 5;
		else if(d==6) return 6;
		}

else if (dice2==dice3){
		printf("\nYour points: %d\n",dice2);
		printf("Opponent will also roll the dice.\n");
		d=reRoll(dice1,dice2,dice3);
		if(d==1) return 2;
		else if(d==2) return 1;
		else if(d==3) return 7;
		else if(d==4) return 4;
		else if(d==5) return 5;
		else if(d==6) return 6;
		}
		
else {	printf("\nNo Pair! Roll again. Press [1].\n");//will reroll again if there is no pair.
		scanf("%d",&command);
		if(command==1){diceRoll();}
		else printf("Invalid command.\n");
	  
		}
}


int reRoll(int dice1,int dice2,int dice3){//the opponent will now roll the dice. same as diceroll.
int commandice2;
srand(time(NULL));
wait();
dice4=(rand()%6)+1;
wait();
dice5=(rand()%6)+1;
wait();
dice6=(rand()%6)+1;
printf("\ndice roll:%d %d %d\n",dice4,dice5,dice6);
printf("\n");
if ((dice4==1 && dice5==2 && dice6==3)||
	(dice4==1 && dice5==3 && dice6==2)||
	(dice4==2 && dice5==1 && dice6==3)||
	(dice4==2 && dice5==3 && dice6==1)||
	(dice4==3 && dice5==2 && dice6==1)||
	(dice4==3 && dice5==1 && dice6==2)) return 1;

else if ((dice4==4 && dice5==5 && dice6==6)||
		 (dice4==4 && dice5==6 && dice6==5)||
		 (dice4==5 && dice5==4 && dice6==6)||
		 (dice4==5 && dice5==6 && dice6==4)||
		 (dice4==6 && dice5==4 && dice6==5)||
		 (dice4==6 && dice5==5 && dice6==4)) return 2;

else if (dice4==dice5 && dice4==dice6) return 3;

else if (dice4==dice5 || dice4==dice6){
	printf("\nOpponent's points: %d\n",dice4);		//reroll, for the forth case.. where the value of the two dice are equal..
			 if((dice1==dice2 && dice1>dice4)||
				(dice1==dice3 && dice1>dice4)||
				(dice2==dice3 && dice2>dice4)) return 4;
		else if((dice1==dice2 && dice1<dice4)||
				(dice1==dice3 && dice1<dice4)||
				(dice2==dice3 && dice2<dice4)) return 5;
		else if((dice1==dice2 && dice1==dice4)||
				(dice1==dice3 && dice1==dice4)||
				(dice2==dice3 && dice2==dice4)) return 6;
		}

else if (dice5==dice6){
		printf("\nOpponent's points: %d\n",dice5);
			 if((dice1==dice2 && dice1>dice5)||
				(dice1==dice3 && dice1>dice5)||
				(dice2==dice3 && dice2>dice5)) return 4;
		else if((dice1==dice2 && dice1<dice5)||
				(dice1==dice3 && dice1<dice5)||
				(dice2==dice3 && dice2<dice5)) return 5;
		else if((dice1==dice2 && dice1==dice5)||
				(dice1==dice3 && dice1==dice5)||
				(dice2==dice3 && dice2==dice5)) return 6;
		}
		
else {	printf("No Pair. Opponent needs to roll again. Press [1].\n");
		scanf("%d",&commandice2);
		if(commandice2==1){reRoll(dice1,dice2,dice3);}
		else printf("Invalid command.\n");
			}
}

void wait(){//this function is used to have a break.. or
	int x,y;
	x = clock();
	while(x+(rand()%1000+1000)>clock()){
		y = clock();
		}
}
