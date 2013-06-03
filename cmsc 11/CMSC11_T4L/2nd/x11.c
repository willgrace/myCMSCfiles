/*Graycel Santos
T-4L*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *fp;

main()
{


int counter=0, choose, i, j, temp;
char c, store[50], orig[50];
char line[100];

printf("\n**Welcome!**\n");
printf("Let's encrypt and decrypt your secret messages\n\n");

//this is where the file will be open to be counted
fp=fopen("sample.txt", "r");


if(fp==NULL){

    printf("ERROR: There is NO FILE in the directory ready to be encrypted.\n");
}

else{
    printf("\nCount\n\n");


        while(!feof(fp)){ //codes to count the characters in the files
        getc(fp);
        counter++;
        }

    printf("There are %d characters in the file\n\n", counter);



fclose(fp);


while(choose!=4){

printf("\nWhat would you like to do?\n");
printf("[1] Encrypt\n");
printf("[2] Decrypt\n");
printf("[3] View\n");
printf("[4] EXIT\n");
printf("choice: ");

scanf("%d", &choose);

switch(choose){


			case 1:
			
                printf("\nENCRYPT\n\n");//this reads the file and displays it as encryted
			
			{

                    fp=fopen("sample.txt", "r");

		   if(fp==NULL){
                        printf("ERROR: There is NO SUCH FILE in the directory.");//this checks if the file does exist
                    }

                    else{			
                      for(i=0;i<=counter-2;i++){ //for loop to read each charcter and encrypt it except eof
                        	c=getc(fp);
				store[i]=(char)c+1;
			}
						
			printf("%s", store);
			}
                    fclose(fp);
			}
		//write
			{
                    fp=fopen("sample.txt", "w");

                    fprintf(fp,"%s", store);//the characters in the files are stored in the temporary string and thsi string was written in the file 


                    fclose(fp);
			
			
                    printf("\n\nENCRYPTED!!\n\n");
			}
			break;


		case 2:{
			{
                    printf("\nDECRYPT:");// this where we decrypt the encrypted file
			
                    fp=fopen("sample.txt", "r");

                    if(fp==NULL){
                        printf("ERROR: There is NO SUCH FILE in the directory.");
                    }

                    else{
			
		       
		      printf("%s", store);			
			temp = (counter-2);
	
                      for(j=0;j<temp;j++){ //codes where the file will be decrypted and wil be saved in the string orig
                        	c=getc(fp);
				orig[j]=(char)c-1;
			}
			
                    fclose(fp);
			}
			}

		    
                    //write
			{
			
                    	
                    fp=fopen("sample.txt", "w");


                    fprintf(fp,"%s", orig);//this is where the original message will be saved in the file


                    fclose(fp);
			
			}
					

                    printf("\n\nDECRYPTED!!\n\n");
		}
		break;


			case 3:
					
					printf("\nThe message is...\n\n"); //this is where the encrypted or decrypted file will be viewed by the user

                			fp=fopen("sample.txt","rt");
						if(fp==NULL){

							printf("ERROR: There is NO SUCH FILE in the directory.");
						}
						else{
							char c=getc(fp);
							while(!feof(fp)){
							printf("%c",c);
							c=getc(fp);
							}
						
						}
					
					fclose(fp);
					break;

			case 4:
					printf("\nGoodbye!!\n");
					break;

           		default:
					printf("\nInvalid Input\n");//if the user enter a number not in the choices above
					break;
			
		
	
      }
   }

}
}

//end of program 











