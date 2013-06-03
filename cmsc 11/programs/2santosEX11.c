/*Graycel Santos
T-4L*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *fp;

main()
{


int counter=0, choose=0, i=0, j;
char c[10], p[10], a[50], d;
char line[50];

printf("\n**Welcome!**\n");

fp=fopen("sample.txt", "rt");


if(fp==NULL){

    printf("ERROR: There is NO SUCH FILE in the directory.");
}

else{
    printf("\nCount\n\n");


        while(!feof(fp)){
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
                printf("\nENCRYPT\n\n ");


                    fp=fopen("sample.txt", "rt");
                        for(i=0;i!=counter-1;i++){
                        	c[i]=getc(fp);
                        	p[i]=c[i]+1;
                        }

                    fclose(fp);


                    //write

                    fp=fopen("sample.txt", "wt");

                    fprintf(fp,"%s", p);


                    fclose(fp);

                    printf("\n\nENCRYPTED!!\n\n");
                    
                    
                    break;



			case 2:
                    printf("\nDECRYPT:");

                    fp=fopen("sample.txt", "rt");

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

					printf("\n\nLoading....\n\n");
                    //write

                    fp=fopen("sample.txt", "wt");

                    for(j=0; j<counter-1; j++){

                    a[j]=p[j]-1;

                    }

                    fprintf(fp,"%s", a);


                    fclose(fp);

                    printf("\n\nDECRYPTED!!\n\n");
                    
                    break;


			case 3:
					
					printf("\nThe message is...\n\n");

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
						fclose(fp);
						}

					break;

			case 4:
					printf("\nGoodbye!!\n");
					break;

            default:
					printf("\nInvalid Input\n");
					break;
			}

        }
    }

}










