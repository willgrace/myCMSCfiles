#include <stdio.h>

main()
{	
	int age, gf, gender, M;

	printf("Hello, please enter 1 if you're female and 2 if you're a male: ");
	scanf("%d", &gender);
	
	if(gender==1){
      		printf("\nSo, how many girlfriend/s you had? ");
		scanf("%d", &gf);
   
            if(gf>3){
                 printf("\nYou like girls so much. don't you?");
                 }
            else{
                 printf("\nYou're a good boy!\n");
            }

	}else{
                printf("How old are you now? ");
		scanf("%d", &age);
            
 		if(age<18){
                 printf("\nHello young lady!");
                 }
            	else{
                 printf("\nYou're in the right age anyway.\n");
            	}
	}
	printf("\nbye\n");
}

