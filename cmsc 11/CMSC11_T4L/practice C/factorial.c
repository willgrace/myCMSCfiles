#include <stdio.h>

main()
{
	int n, ans=1;
	
	do{
		printf("please enter an integer: ");
		scanf("%d", &n);
		
	} while (n<0); {
		if(n==0) {
			printf("1\n");
		}
		else{
			while(n!=0){
				ans=ans*n;
				n--;				
			}
			printf("%d\n", ans);
		}
	}
}
