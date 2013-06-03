#include <stdio.h>

main()
{
	int i,j,n;
	
	printf(" Enter the number upto which we have to find the prime number: ");
	scanf("%d",&n);
	printf("\n");
	
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=i-1;j++)
		if(i%j==0) break; //Number is divisble by some other number. So break out
		if(i==j) printf("%d",i); //Number was divisible by itself (that is, i was same as j)
	}//Continue loop upto nth number
	
} 
