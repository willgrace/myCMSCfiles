#include <stdio.h>
#include <string.h>


int search(char temp, int n)
{
    if (strcmp(temp, "contact[n].name.fname[0]")==0){
        return search(char temp, int n-1 );
    }else return n;
}

main()
{
