/********************************************************************
* File : struct.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to test the functionalites of
*               a struct that is used in a bigger project later .
*
********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

struct student_tag {
    int m;
    int *p;
};
typedef struct student_tag student_t ;

void print_struct(student_t *ptr);
void change(student_t *ptr1,student_t *ptr2);
int main()
{
    student_t misho;
    student_t ans ;
    int *p ;
    p=malloc(sizeof(int));
    misho.m=5;
    misho.p=p;
    *misho.p=6;
    int*a;
    a=malloc(sizeof(int));
    ans.m=0;
    ans.p=a;
    *ans.p=0;
    print_struct(&misho);
    change(&ans,&misho);
    print_struct(&ans);
    print_struct(&misho);
    free(misho.p);
    free(ans.p);
    return 0 ;
}

void print_struct(student_t *ptr)
{
    printf("misho.m=%d\n",ptr->m);
    printf("*misho.p=%d\n",*ptr->p);

}

void change(student_t *ptr1,student_t *ptr2)
{
    ptr1->m=ptr2->m+50;
    *ptr1->p=*ptr1->p+60;
}
