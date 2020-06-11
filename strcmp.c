/********************************************************************
* File : strcmp.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to compare 2 strings.
*
********************************************************************/

// U excute it bt typing ./a.out argv[1] argv[2]
#include<stdio.h>
//#include<string.h>

int str(char * p1,char *p2);
int main(int argc,char ** argv)
{
	if(argc !=3)
	{printf("Not enough arguments. Please specify 2 strings\n");
	return 0;}
	char * a = argv[1];
        char * b = argv[2];

	//printf("%d",strcmp(a,b));
	printf("%d\n",str(a,b));
	return 0 ;
}

int str(char * p1 ,char *p2)
{
    while(1)
    {
        if(*p1==*p2)
        {p1++;
        p2++;}
        else{return 0;}
	if(*p1=='\0'&&*p2=='\0')
	break;
    }
    return(1);
}/*
int str(char * p1,char *p2)
{
    while(*p1==*p2)
    {
        if(*p1=='\0')
        {return(1);}
        p1++;
        p2++;
    }
    return(0);
}*/
