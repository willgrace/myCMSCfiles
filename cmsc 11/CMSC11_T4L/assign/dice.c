/*
CLOY DOMINIQUE T. PLUMO
MARCH 2010

DICE BATTLERS v2.0
	note: This program is solely for my academic purposes
	and is not meant to be COPIED BY OTHERS for their own
	academic purposes. COPY THIS AND I WILL SUE YOU. HAHA.

nnn = 3x
123 = -x2
456 = x2
xxn = n points, hang then compare

*/
#include <stdio.h>
#include <time.h>

int diceroll();
void showdice(int);
void wait();
void header();

main(){
int bet, p, ep, t, your, enemy, bat=0;
int d1, d2, d3, end=0, choice;
char turn[10];

header();

strcpy(turn, "Player 1");
t = 0;

p = 1000;
ep = 1000;

while(end!=1){
	if(p<=0){
		printf("Player 1 has lost all your money! GAMEOVER!\n\n");
		end=1;
		}
	else if(ep<=0){
		printf("Player 2 has lost all money! GAMEOVER!\n\n");
		end=1;
		}
		
	if(end==0){
		printf("\n\nTurn: %s", turn);
		printf("\n\n# S E L E C T #\n\n[1] To PLAY!\n[2] TO EXIT\n[3] FOR INSTRUCTIONS\n\nM1: %d\tM2: %d\n\nMode: ", p, ep);
		scanf("%d", &choice);
		
		if(t==0)
			bet = p + 1;
		else if(t==1)
			bet = ep + 1;
		}
	
	if(end==0)
	switch(choice){
		case 1:
			
			if(t==0){
				while(bet>p){
					printf("\n# P L A C E   Y O U R   B E T #\n\nBet: ");
					scanf("%d", &bet);
					if(bet>p)
						printf("\n\nYour bet is higher than your current money!\n\nBet again!\n\n");
					}
				p = p - bet;
				}
								
			else if(t==1){
				while(bet>ep){
					printf("\n# P L A C E   Y O U R   B E T #\n\nBet: ");
					scanf("%d", &bet);
					if(bet>ep)
						printf("\n\nYour bet is higher than your current money!\n\nBet again!\n\n");
					}
				ep = ep - bet;
				}
							
			printf("\n\n");
			
			d1 = diceroll();
			wait();
			d2 = diceroll();
			wait();
			d3 = diceroll();
			wait();
			
			if(d1==d2&&d2==d3&&d1==d3){
				printf("\n\nN - N - N COMBO!!\n\nYou WIN 3x of bet!\n\n");
				if(t==0)
					p = p + bet*3;
				else if(t==1)
					ep = ep + bet*3;
				}
				
			else if(d1==d2&&(d1!=d3&&d2!=d3)){
				printf("\n\nX - X - N COMBO!!\n\nYour value %d is stored for DICE BATTLE!\n\n", d3);
				wait();
				if(t==0){
					your = d3;
					bat = 1;
					}
				else if(t==1){
					enemy = d3;
					bat = 1;
					}
				}
				
			else if(d1+d2+d3==15&&(d1!=d2&&d2!=d3&&d1!=d3)){
				printf("\n\n4 - 5 - 6 COMBO!!\n\nYou WIN 2x of bet!\n\n");
				if(t==0)
					p = p + bet*2;
				else if(t==1)
					ep = ep + bet*2;
				}
				
			else if(d1+d2+d3==6&&(d1!=d2&&d2!=d3&&d1!=d3)){
				printf("\n\n1 - 2 - 3 COMBO..\n\nYou LOSE 2x of bet!\n\n");
				if(t==0)
					p = p - bet*2;
				else if(t==1)
					ep = ep - bet*2;
				}
				
			else{
				printf("\n\nNO COMBOS! TRY AGAIN!\n\n");
				if(t==0)
					p = p + bet;
				else if(t==1)
					ep = ep + bet;
				}
				
			break;
			
		case 2:
			end = 1;
			break;
			
		case 3:
			printf("\n\n\tInstructions:\n\n");
			printf("\tPlace your bet and roll the dice!\n\n");
			printf("\tCOMBOS:\n\n\n");
			printf("\t1 - 2 - 3 COMBO\n");
			printf("\t    RESULT:   LOSE 2x of your bet\n\n");
			printf("\t4 - 5 - 6 COMBO\n");
			printf("\t    RESULT:   WIN 2x of your bet\n\n");
			printf("\tN - N - N COMBO\n");
			printf("\t    RESULT:   WIN 3x of your bet\n\n");
			printf("\tX - X - N COMBO\n");
			printf("\t    RESULT:   DICE BATTLE! WINNER TAKES THE BET!\n\n");
			if(strcmp(turn, "Player 1")==0){
				strcpy(turn, "Player 2");
				t = 1;
				}
		
			else{
				strcpy(turn, "Player 1");
				t = 0;
				}
				
			break;
			
		default:
			printf("\n\nERROR!\n\nLose one turn!\n\n");
		}
		
	if(strcmp(turn, "Player 1")==0){
		strcpy(turn, "Player 2");
		t = 1;
		}
		
	else{
		strcpy(turn, "Player 1");
		t = 0;
		}
		
	while(bat == 1){
		printf("\n%s rolls to battle the value of ", turn);
		if(t==1){
			printf("%d!\n\n", your);
			wait();
			d1 = diceroll();
			wait();
			printf("\n\nThe value of %d will be used!\n\n", d1);
			enemy = d1;
			}
		else if(t==0){
			printf("%d!\n\n", enemy);
			wait();
			d1 = diceroll();
			wait();
			printf("\n\nThe value of %d will be used!\n\n", d1);
			your = d1;
			}
			
		wait();
			
		if(your>enemy){
			printf("Player 1 wins the battle!\n\n");
			printf("Bet subtracted to Player 2!\n\n");
			p = p + bet;
			bat = 0;
			}
			
		else if(enemy>your){
			printf("Player 2 wins the battle!\n\n");
			printf("Bet subtracted to Player 1!\n\n");
			p = p + bet;
			bat = 0;
			}
		
		else if(enemy==your){
			bat = 0;
			if(t==0)
				p = p + bet;
			else if(t==1)
				ep = ep + bet;
			printf("\n\nDRAAWWW!!\n\n");
			}
		}
	}
}
			

int diceroll(){
int roll;

roll = (rand()%6)+1;
showdice(roll);
return roll;

}

void wait(){
int x,y;
x = clock();
srand(time(NULL));

	while(x+(rand()%5000+945)>clock()){
		y = clock();
		}
}

void showdice(int roll){
if(roll==1){
printf("    _______________\n");
printf("   /              /|\n");
printf("  /              / |\n");			   
printf(" /              /  |\n");
printf("/______________/   |\n");
printf("|              |   |\n");
printf("|      _       |   /\n");
printf("|     (_)      |  /\n");
printf("|              | /\n");
printf("|______________|/\n");
}
else if(roll==2){
printf("    _______________\n");
printf("   /              /|\n");
printf("  /              / |\n");			   
printf(" /              /  |\n");
printf("/______________/   |\n");
printf("|   _          |   |\n");
printf("|  (_)         |   /\n");
printf("|          _   |  /\n");
printf("|         (_)  | /\n");
printf("|______________|/\n");
}
else if(roll==3){
printf("    _______________\n");
printf("   /              /|\n");
printf("  /              / |\n");			   
printf(" /              /  |\n");
printf("/______________/   |\n");
printf("|  _           |   |\n");
printf("| (_)  _       |   /\n");
printf("|     (_)   _  |  /\n");
printf("|          (_) | /\n");
printf("|______________|/\n");
}
else if(roll==4){
printf("    _______________\n");
printf("   /              /|\n");
printf("  /              / |\n");			   
printf(" /              /  |\n");
printf("/______________/   |\n");
printf("|   _      _   |   |\n");
printf("|  (_)    (_)  |   /\n");
printf("|   _      _   |  /\n");
printf("|  (_)    (_)  | /\n");
printf("|______________|/\n");
}
else if(roll==5){
printf("    _______________\n");
printf("   /              /|\n");
printf("  /              / |\n");			   
printf(" /              /  |\n");
printf("/______________/   |\n");
printf("|  _       _   |   |\n");
printf("| (_)  _  (_)  |   /\n");
printf("|  _  (_)  _   |  /\n");
printf("| (_)     (_)  | /\n");
printf("|______________|/\n");
}
else if(roll==6){
printf("    _______________\n");
printf("   /              /|\n");
printf("  /              / |\n");			   
printf(" /              /  |\n");
printf("/______________/   |\n");
printf("|  _        _  |   |\n");
printf("| (_)      (_) |   /\n");
printf("| (_)      (_) |  /\n");
printf("| (_)      (_) | /\n");
printf("|______________|/\n");
}
}

void header(){
printf("\n\n\n\t    W E L C O M E   T O\n\t    'DICE BATTLERS v2.0' !\n\t\tCreated by: \n\n");
printf("\t\t#############\n");
printf("\t\t##         ##\n");
printf("\t\t##  #####  ##\n");
printf("\t\t##  #########\n");
printf("\t\t##  #########\n");
printf("\t\t##  #########\n");
printf("\t\t##  #########\n");
printf("\t\t##  #####  ##\n");
printf("\t\t##         ##\n");
printf("\t\t#############\n\n");

showdice(6);
printf("\n\n");
}
