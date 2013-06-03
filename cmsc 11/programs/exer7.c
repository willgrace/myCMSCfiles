#include <stdio.h>

main(){


int allowance=300, i;

	for(i=0; i<12; i++){
	
	allowance=allowance+100;
		if(i%6==0)
			allowance=allowance+500;
	
	
	}

printf("savings after 12 months is %d\n", allowance);

}
