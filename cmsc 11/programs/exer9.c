#include <stdio.h>
#define n 5

main(){

int a, max=0, min;
float num, total=0;


	for(a=0;a<n;a++){
		printf("Enter num:");
		scanf("%f", &num);
	
			if(num>max)
				max=num;
				
			if(num<min)
				min=num;

		total=total+num;
	
	
	}
		
	
float ave=total/n;
	printf("average is %.3f\n", ave);
	
	printf("max is %d\n", max);
	printf("min is %d\n", min);





}
