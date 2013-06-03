/*Graycel Santos T-4L*/
#include <stdio.h>

main()
{	

	float floatheight, floatweight, floatBMI;			//variable assignments

	printf("Hello there! Let's know your BMI or Body Mass Index!\n");  //greetings
	printf("First, what is your weight in kg? ");
	scanf("%f", &floatweight);										//input of weight
	
	printf("thank you, now what is your height in m? ");
	scanf("%f", &floatheight);										//input of height
	
	floatheight=floatheight*floatheight;
	floatBMI=floatweight/floatheight; 								//BMI computation

	if(floatBMI<18.5){
      		
      		printf("Oh, your BMI is %.1f.Sad to say you're underweight...eat some more, ok?\n", floatBMI); //assessment for underweight
      		}
	else{
          
 		if( floatBMI>=18.5 && floatBMI<25){
                 printf("\nWOW! your BMI is %.1f so you're NORMAL. Keep it up!\n", floatBMI);	//assessment for NORMAL
            }
        else{
        
        	if( floatBMI>=25 && floatBMI<30){
                 printf("\nYour BMI is %.1f so you should be careful cause' you are Overweight already!\n", floatBMI);																					//assessment for Overweight
            }
            else{
            	printf("\nYou're Obese because your BMI is %.1f. Watch your diet please!\n", floatBMI); //assessment for Overweight
           }
		}
	}
		printf("\nThank you for the information above. Have a nice day, good bye!\n");	//farewell statement
}

/*End of Exercise 4*/

