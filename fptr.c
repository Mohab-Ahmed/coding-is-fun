/********************************************************************
* File : fptr.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to test the functionalites of
*               a function pointer .
*
********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int add(int x, int y);
int sub(int x, int y);
int mult(int x, int y);
int divi(int x, int y);

typedef int (*fptr_t)();

typedef enum {
    FP_ADD, FP_SUN, FP_MULT,FP_DIVI
} fp_e;

int main()
{
    //first test of only one function pointer
    fptr_t fptr1=&add;
    printf("first test = %d\n",fptr1(50,30));

    //second test trying array of function pointers
    fptr_t farr[4]={add,sub,mult,divi};
    for(int i=0;i<4;i++)
        printf("%d\n",farr[i](60,20));

    //test fro enumeration with function pointer
    printf("enum example = %d\n",farr[FP_ADD](60,20));

    return 0 ;
}

int add(int x, int y)
{
    return(x+y);
}

int sub(int x, int y)
{
    return(x-y);
}

int mult(int x, int y)
{
    return(x*y);
}

int divi(int x, int y)
{
    return(x/y);
}