#include <stdio.h>

main()
{
	char charName [100];
	int age;

	printf("Konnichiwa! dare desuka?\n");
	scanf("%s", charName);
	printf("oh, Okaeri nasai, %s-ojousama!", charName);
	printf("\nyou live in Bataan\n");
	printf("and your cell# is 09196364916\n");
	printf("How old are you agan, ojousama?");
	scanf("%d", &age);
	printf("oh how young!\n");
	printf("Ja-ne, %s-ojousama. see you next year when you are %d.\n", charName, age+1);
	printf("Have fun being %d now!\n", age);
}
