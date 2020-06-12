/********************************************************************
* File : enum.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to test the functionalites of
*               enums.
*
********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>


typedef enum 
{
    SAT=1,
    SUN,
    MON,
    TUS,
    WED,
    THU,
    FRI
}days_e;

int main()
{
    days_e var[10];
    printf("size of var[10] = %ld\n",sizeof(var));
    for (size_t i = SAT; i < FRI; i++)
    {
        var[i-1]=i+10;
        printf("%d\n",var[i-1]);
    }
    
    printf("%d\n",SUN);
    printf("%ld\n",sizeof(days_e));

    return 0;
}
