/*Jonathan M. Almalvez*/
/*S-4L*/

#include<stdio.h>
#include<stdlib.h>
main(){
srand(time(NULL));
//inputs
int intX[6][11];
int i,j,x;
float rowave, rowsum = 0;	
float columnave, columnsum = 0; 		
//solutions / formulas	
	for( i=0; i<5; i++){
		for(j=0; j<10;j++){
			intX[i][j] = (rand()%5) + 1;
			printf("%d ", intX[i][j]);
		
		}	
		putchar('\n');	
		
	}
//solution for the row average
	for ( i=0; i<5; i++){
	
		for(j=0; j<11;j++){
			
			rowsum = rowsum + intX[i][j]; 
			
			printf("%d\t",intX[i][j]);	
			rowave = rowsum/5;
	}
		printf("%.2f", rowave);
		putchar('\n');
		rowsum = rowsum - rowsum;	
	
//solution for the column average	
	for ( i=0; i<6; i++){
		}
		for(j=0; j<10;j++){
			
			columnsum = columnsum + intX[i][j]; 
			
			printf("%d\t",intX[i][j]);	
			columnave = columnsum/10;
	}
		putchar('\n');
		columnsum = 0;		
			
}
//end of program
