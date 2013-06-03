#include <stdio.h>

main(){

int x, y;
for(x=1;x<=5;x++){
	for(y=1;y<=5;y++){
		if((x==1&&y==1)||(x==1&&y==5)||(x==2&&y==2)||(x==2&&y==4)||(x==3&&y==3)||(x==4&&y==2)||(x==4&&y==4)||(x==5&&y==1)||(x==5&&y==5))
		printf("X");
		else
			printf(" ");	
	}
	printf("\n");
}











}
