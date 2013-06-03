/* Jennifer H. Turingan
THE DICE COMBOS 
	Note: This program is a DICE GAME. The combos below will be used as well as followed during the game.  

		nnn = 3x
		123 = -x2
		456 = x2
		xxn = n points, hang then compare

*/

#include <stdio.h>
#include <time.h>

int diceroll(); 	//This is a function for rolling the three dices.
void showdice(int); 	// This funtion will display the rolled dices one at a time.
void wait();    	// This funtion will let the program to pause for a while especially in rolling the dice.
void header(); 		// This will hide the header during the game, esp. in the xxn round.

main(){
int bet, p, ep, t, your, enemy, bat=0; 		// These are the declarations used in to indicate the players, money as well as the bet.
int d1, d2, d3, end=0, choice; 			//These are for the dices and the choice declarations.
char turn[10]; 					//This one is for the turn of each player. 

header();		//This is the start of the game proper.

strcpy(turn, "Player 1");
t = 0;

p = 1000;		//The initial money of both players is 1000 each.
ep = 1000;

while(end!=1){		//This is the loop used to regulate the turns of each player.
	if(p<=0){
		printf("Player 1 has lost all your money! GAMEOVER!\n\n"); //This will indicate which of the player has lost all his/her money.
		end=1;
		}
	else if(ep<=0){
		printf("Player 2 has lost all money! GAMEOVER!\n\n");
		end=1;
		}
		
	if(end==0){				//This will facilitate the flow of turns of each player.
		printf("\n\nTurn: %s", turn);
		printf("\n\n# S E L E C T #\n\n[1] To PLAY!\n[2] TO EXIT\n[3] FOR INSTRUCTIONS\n\nM1: %d\tM2: %d\n\nMode: ", p, ep);
		scanf("%d", &choice);		//This will let the players to choose whether to play/continue, to stop/close or to read the instruction.
		
		if(t==0)			//This will regulate the turn to bet of each player.
			bet = p + 1;
		else if(t==1)
			bet = ep + 1;
		}
	
	if(end==0)
	switch(choice){				//This will facilitate the game proper which includes the bet, the rolling of dice and the cases indicated in the combo menu.
		case 1:
			
			if(t==0){		//This will check if the bet entered by the Player1 is exceeding the original amount of his/her money.
				while(bet>p){
					printf("\n# P L A C E   Y O U R   B E T #\n\nBet: ");
					scanf("%d", &bet);
					if(bet>p)
						printf("\n\nYour bet is higher than your current money!\n\nBet again!\n\n");
					}
				p = p - bet;	//This will deduct the bet from the money of the loser (player1).
				}
								
			else if(t==1){		//This will check if the bet entered by the Player2 is exceeding the original amount of his/her money.
				while(bet>ep){
					printf("\n# P L A C E   Y O U R   B E T #\n\nBet: ");
					scanf("%d", &bet);
					if(bet>ep)
						printf("\n\nYour bet is higher than your current money!\n\nBet again!\n\n");
					}
				ep = ep - bet; //This will deduct the bet from the money of the loser(player2).
				}
							
			printf("\n\n");		//This is where the rolling of dice takes place. 
			
			d1 = diceroll();
			wait();
			d2 = diceroll();
			wait();
			d3 = diceroll();
			wait();
					//This is where the evaluation of the results occurs. 
			if(d1==d2&&d2==d3&&d1==d3){
				printf("\n\n N - N - N COMBO!!\n\n You WIN 3x of bet!\n\n");	//The N-N-N combo was displayed.
				if(t==0)
					p = p + bet*3;			//The bet is multiplied thrice and added to the money of the player(winner).
				else if(t==1)
					ep = ep + bet*3;
				}

			else if(d1+d2+d3==15&&(d1!=d2&&d2!=d3&&d1!=d3)){
				printf("\n\n4 - 5 - 6 COMBO!!\n\nYou WIN 2x of bet!\n\n"); //The 4-5-6 combo appeared.
				if(t==0)
					p = p + bet*2;			//The bet is multiplied twice and added to the money of the player(winner).
				else if(t==1)
					ep = ep + bet*2;
				}
				
			else if(d1+d2+d3==6&&(d1!=d2&&d2!=d3&&d1!=d3)){
				printf("\n\n1 - 2 - 3 COMBO..\n\nYou LOSE 2x of bet!\n\n"); //The 1-2-3 combo also appeared.
				if(t==0)
					p = p - bet*2;			//The bet is multiplied twice but deducted from the money of the player(loser).
				else if(t==1)
					ep = ep - bet*2;
				}

			else if(d1==d2&&(d1!=d3&&d2!=d3)){
				printf("\n\nX - X - N COMBO!!\n\nYour value %d is stored for DICE BATTLE!\n\n", d3); //The X-X-N combo was displayed.
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

			else if(d2==d3&&(d2!=d1&&d3!=d1)){
   				printf("\n\n N - X - X COMBO!!\n\nYour value %d is stored for DICE BATTLE!\n\n", d1); //The N-X-X combo was displayed.
   				wait();
   				if(t==0){
   				your = d1;
				bat = 1;
				}
			else if(t==1){
				enemy = d1;
				bat = 1;
				}
      			     }


   			else if(d1==d3&&(d1!=d2&&d3!=d2)){
  				printf("\n\n X - N - X COMBO!!\n\nYour value %d is stored for DICE BATTLE!\n\n", d2); //The X-N-X combo was displayed.
   				wait();
   				if(t==0){
   				your = d2;
				bat = 1;
					}
			else if(t==1){
				enemy = d2;
				bat = 1;
				}
    			     }

			else{
				printf("\n\n NO COMBOS! NexT Player, Please!!!\n\n"); //This will let the player roll again until there is a specific combo.
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
		strcpy(turn, "Player 1");	//This is an extension of the last combo,X-X-N Combination. 
		t = 0;
		}
		
	while(bat == 1){
		printf("\n%s rolls to battle the value of ", turn); //The unique number is being saved to be compared to the next unique number.
		wait();
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
			
		if(your>enemy){			//This will compare which of the unique numbers is higher. Furthermore, to know who will get the bet.
			printf("Player 1 wins the battle!\n\n");
			wait();
			printf("Bet subtracted to Player 2!\n\n");	//Player 1's unique number is higher than Player2.
			p = p + bet;
			bat = 0;
			}
			
		else if(enemy>your){
			printf("Player 2 wins the battle!\n\n");	//Player 2's unique number is higher than Player1.
			printf("Bet subtracted to Player 1!\n\n");
			p = p + bet;
			bat = 0;
			}
		
		else if(enemy==your){		//This indicate if the unique numbers of both players are the same. DRAW!!!
			bat = 0;
			if(t==0)
				p = p + bet;
			else if(t==1)
				ep = ep + bet;
			printf("\n\nDRAAWWW!!!(^.^)v \n\n");
			}
		}
	}
}
			

int diceroll(){		//This will regulate the rolling of dice (only 1-6).
int roll;

roll = (rand()%6)+1;
showdice(roll);
return roll;

}

void wait(){		//This will regulate the pause for each roll of dice. 
int x,y;
x = clock();
srand(time(NULL));

	while(x+(rand()%5000+945)>clock()){
		y = clock();
		}
}

void showdice(int roll){		//These are the value of each dice(with representation). 
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
printf("\n\n\n\t    W E L C O M E!!!   T O\n\t   !!! >>>>THE DICE COMBOS<<<< !!!\n\t\tCreated by: (^.^)V \n\n");
printf("\t\t##############\n");
printf("\t\t#           ##\n");
printf("\t\t###  ###### ##\n");
printf("\t\t###  ### #####\n");
printf("\t\t###      #####\n");
printf("\t\t###  ### #####\n");
printf("\t\t###  #########\n");
printf("\t\t###  #########\n");
printf("\t\t#      #######\n");
printf("\t\t##############\n\n");

showdice(1);
showdice(4);
showdice(3);
printf("\n\n");
}


//END OF PROGRAM.... THANK YOU!!!!