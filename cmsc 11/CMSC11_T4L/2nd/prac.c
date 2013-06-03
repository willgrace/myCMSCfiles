/*a practice for exam*/

#include <stdio.h>
main()
{
	int a, b, j, sum=0;
	
	printf("enter two numbers: ");
	scanf("%d %d", &a, &b);

	if(a<b){
		for(j=a;j<=b;j++){
			if(j%2==1){
				printf(" %d ", j);
				sum=sum+j;
			}
		}
		putchar('\n');
	}
	else{
		for(j=a;j<=b;j++)
		{
			if(j%2==1){
				printf(" %d ", j);
				sum=sum+j;
			}
		}
		putchar('\n');
	}
	printf("the total is %d\n", sum);
}
