/*Graycel Santos
	T-4L*/
	
#include<stdio.h>
#include<stdlib.h>
#define r 5
#define c 5

main(){
srand(time(NULL));


int inta[r][c];
int i,j, rSUM, cSUM, SUM = 0;	
float rAVE, cAVE, totalAVE;
															//random input of int inside each array
	for(j=0; j<r;j++){
		for( i=0; i<c; i++){
			inta[i][j] = (rand()%5) + 1;
			printf("%d ", inta[i][j]);
		
		}	
		putchar('\n');	
	}

	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			SUM=SUM+inta[i][j];		
		}
		
		cAVE=SUM/5.0;
		printf("COLUMN%d is SUM is %d Ave %f\n", i+1, SUM, cAVE);
		SUM=0;
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			SUM=SUM+inta[j][i];		
		}
		
		rAVE=SUM/5.0;
		printf("Row%d is SUM is %d Ave %f\n", i+1, SUM, rAVE);
		SUM=0;
	}
	//TOTAL SUM and AVE
	
	
	for(i=0; i<r; i++){
		for(j=0; j<c;j++){
	
	SUM = SUM + inta[j][i];
	
		}
	}

	totalAVE = (float)SUM/(r*c);
	
	printf("\nthe total sum and ave is %d %.2f respectively\n\n", SUM, totalAVE);


}
/*end of program*/
