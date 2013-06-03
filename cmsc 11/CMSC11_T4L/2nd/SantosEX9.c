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
	putchar('\n');
	
//get sum and ave of each column
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			SUM=SUM+inta[i][j];		
		}
		
		cAVE=(float)SUM/5.0;
		printf("COLUMN %d : sum is %d & ave %.2f\n", i+1, SUM, cAVE);
		SUM=0;	
	}
	putchar('\n');

//get sum and ave of each row
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			SUM=SUM+inta[j][i];		
		}
		
		rAVE=(float)SUM/5.0;
	
		printf("Row %d : sum is %d & ave %.2f\n", i+1, SUM, rAVE);
		SUM=0;
	}
	putchar('\n');

//TOTAL SUM and AVE
	
	for(i=0; i<r; i++){
		for(j=0; j<c;j++){
	
	SUM = SUM + inta[j][i];
	
		}
	}

	totalAVE = (float)SUM/25.0;
	
	printf("\nthe total sum and ave is %d, %.2f respectively\n\n", SUM, totalAVE);


}
/*end of program*/
