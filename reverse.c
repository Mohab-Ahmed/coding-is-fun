/********************************************************************
* File : reverse.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to reverse a string .
*
********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdint.h>


void reverse(char * str) {
  
  if (str!=NULL)
  {
  int count=0;
  char temp;
  while(*str!='\0')
  {
    count++;
    str++;
  }
  str-=count;
  for(int i=0;i<count/2;i++)
  {
    temp=*(str+i);
    *(str+i)=*(str+count-1-i);
    *(str+count-1-i)=temp;
  }
  }
}

int main()
{
    char name[]="Mohab Ahmed";

    printf("Before =%s\n",name);
    reverse(name);
    printf("After  =%s\n",name);

    return 0;
}