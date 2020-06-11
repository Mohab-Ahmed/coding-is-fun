/********************************************************************
* File : tt.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to perform the same function
                as atoi function and then transform to hex.
*
********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int myatoi(const char * str);

//first attemp to crack the puzzle 
/*
int main()
{
	const char * a="12345" ;
	int x;
	//x=atoi(a);
	x=myatoi(a);

    printf("%s\n",a);
    printf("%d\n",x);
}

int myatoi(const char * str)
{
    int res=0,i=0;
    if(*str==43||*str==45)
        {
            str++;
            if(*str>=48&&*str<=57)
                {str--;}
            else
                {return res;}
        }
    while((*str>=48&&*str<=57)||*str==43||*str==45)
    {
        str++;
        i++;
    }
    int temp[i],k=0 ;
    str--;
    for(int j=(i-1);j>=0;j--)
    {
        switch (*str)
        {
        case '0' :
            temp[j]=0;

            break;
        case '1' :
            temp[j]=1;
            break;
        case '2' :
            temp[j]=2;
            break;
        case '3' :
            temp[j]=3;
            break;
        case '4' :
            temp[j]=4;
            break;
        case '5' :
            temp[j]=5;
            break;
        case '6' :
            temp[j]=6;
            break;
        case '7' :
            temp[j]=7;
            break;
        case '8' :
            temp[j]=8;
            break;
        case '9' :
            temp[j]=9;
            break;
        case '+' :
            temp[j]=0;
            break;
        case '-' :
            temp[j]=-1;
            break;
        }
        if(*str=='-')
        {return (-res);}
        res+=(temp[j]*pow(10,k));
        printf("%d-%c\t%d\t%d\t%f\n",j,*str,temp[j],res,pow(10,k));
        str--;
        k++;
    }
    return (res);
}*/

//_______________________________________________
//second attemp with simplified code
//_______________________________________________

int myatoi(const char * str);

int main()
{
	const char * a="-540xyz" ;
	int x;
	//x=atoi(a);
	x=myatoi(a);

    printf("%s\n",a);
    printf("%x\n",x);
}

int myatoi(const char * str)
{
    int res=0,i=0;
    if(*str==43||*str==45)
        {
            str++;
            if(*str>=48&&*str<=57)
                {str--;}
            else
                {return res;}
        }
    while((*str>=48&&*str<=57)||*str==43||*str==45)
    {
        str++;
        i++;
    }
    int k=0;
    str--;
    for(int j=(i-1);j>=0;j--)
    {
        if(*str=='-')
        {return (-res);}
        res+=((*str-'0')*pow(10,k));
        printf("%d - %c\t%d\t%f\n",j,*str,res,pow(10,k));
        str--;
        k++;
    }
    return (res);
}
