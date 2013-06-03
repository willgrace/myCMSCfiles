/* Graycel Santos, T-4L*/
#include <stdio.h>

main()
{
	int i, j, n;											//variables
	
	printf("Make a hollow square\n\n");						//title of program
	
	do{
	printf("Enter a number greater than 3: ");				//asking for columns
	scanf("%d", &n);
	
	} while(n<3);{
		
		for(j=0;j<n;j++){
			
			for(i=0;i<n;i++){
				
				if((j!=0 && j!=n-1) && (i!=0 && i!=n-1)){	//hollow part condition
					printf(" ");							//spaces
				}
				else{
					printf("x");							//print symbol (border)
				}
			}
			printf("\n");
		}
	}
}

/*End of exer 5*/
