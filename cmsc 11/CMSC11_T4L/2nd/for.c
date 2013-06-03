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
	
	//FOR each column
	
	printf("the sum and ave of each columns are:");
	
	for(j=0; j<r; j++){
		for(i=0; i<c; i++){
	cSUM=0;
	cSUM = cSUM + inta[i][j];
	cAVE = (float)cSUM/r;
	printf("\n1st col %d %.2f", cSUM, cAVE );
	}
	}
	
	putchar('\n');
	
	
	
	
	
	//For each row
	printf("the sum and ave of each rows are:" );
	rSUM = 0;
	for(j=0; j<c;j++){
	
	rSUM = rSUM + inta[j][0];
		}
	rAVE =(float) rSUM/c;
	
	printf("\n1st row %d %.2f", rSUM, rAVE );
	
	putchar('\n');
	rSUM = 0;
	for(j=0; j<c;j++){
	
	rSUM = rSUM + inta[j][1];
		}
	rAVE = rSUM/c;

	printf("2nd row %d %.2f", rSUM, rAVE );
	
	putchar('\n');
	
	rSUM = 0;
	for(j=0; j<c;j++){
	
	rSUM = rSUM + inta[j][2];
		}
	
	rAVE = rSUM/c;

	printf("3rd row %d %.2f", rSUM, rAVE );
	
	putchar('\n');
	
	rSUM = 0;
	for(j=0; j<c;j++){
	
	rSUM = rSUM + inta[j][3];
		}
	rAVE = rSUM/c;

	printf("4th row %d %.2f", rSUM, rAVE );
	
	putchar('\n');
	
	rSUM = 0;
	for(j=0; j<c;j++){
	
	rSUM = rSUM + inta[j][4];
		}
	rAVE = rSUM/c;

	printf("5th row %d %.2f", rSUM, rAVE );
	
	putchar('\n');
	
	
	//TOTAL SUM and AVE
	
	
	for(i=0; i<r; i++){
		for(j=0; j<c;j++){
	
	SUM = SUM + inta[j][i];
	
		}
	}

	totalAVE = SUM/(r*c);
	
	printf("\nthe total sum and ave is %d %.2f respectively\n\n", SUM, totalAVE);

}
/*end of program*/
