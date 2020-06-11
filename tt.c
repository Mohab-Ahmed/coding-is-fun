/********************************************************************
* File : tt.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to test the functionalites of
*               structs and other basic things.
*
********************************************************************/
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
#define NAME (ana) 

struct tl_tag{
char * c;
char  s;
int j;
};
typedef struct tl_tag tl_t ;

tl_t max(tl_t NAME);

int main()
{
    tl_t NAME ;
    //char word[SIZE]="hello" ;
    char word[SIZE]={'h','e','l','l','o'} ;
    NAME.c=word;
    NAME=max(NAME);
    printf("%c\n",NAME.s);
    printf("%d\n",NAME.s);
    printf("%d\n",NAME.j);
}


tl_t max(tl_t NAME)
{
    NAME.s=NAME.c[0];
    NAME.j=0;
    for(int i=1;i<SIZE;i++)
    {
        if(NAME.c[i]>NAME.s)
        {
            NAME.s=NAME.c[i];
            NAME.j=i;
        }
    }
    return(NAME);
}

