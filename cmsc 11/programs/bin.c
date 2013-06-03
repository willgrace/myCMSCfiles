#include <stdio.h>

main(){

int dec, rem, counter=1, ans, bin=0;
scanf("%d", &dec);

while(dec>0){

	rem=dec%2;
	dec=dec/2;
	ans=rem*counter;
	bin=bin+ans;
	counter=counter*10;


}
	printf("%d", bin);
	printf("\n");
}
