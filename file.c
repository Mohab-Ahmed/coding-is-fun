
/********************************************************************
* File : file.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to test the functionalites of
*               opening a file and interacting with it .
*
********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#ifdef S
int main(int argc,char ** argv)
{
    if(argc!=3)
    {
        fprintf(stderr,"Not enough arguments\nPlease specify the file name and opening mode\n\n");
        return(EXIT_FAILURE);
    }
    FILE * f =fopen(argv[1],argv[2]);
    if(f==NULL)
    {
        fprintf(stderr,"file opening faild\n");
        return(EXIT_FAILURE);
    }
    size_t i=0;
    char c[200][200];
    while ((fgets(c[i],200,f)) != NULL)
    {
        printf("%s\n",c[i]);
        i++;
    }
    return 0;
}
#endif

#ifdef C
int main(int argc,char ** argv)
{
    if(argc!=3)
    {
        fprintf(stderr,"Not enough arguments\nPlease specify the file name and opening mode\n");
        exit(EXIT_FAILURE);
    }
    FILE * f =fopen(argv[1],argv[2]);
    if(f==NULL)
    {
        fprintf(stderr,"file opening faild\n");
        exit(EXIT_FAILURE);
    }
    int c ;
    size_t count=0;
    while ((c=fgetc(f)) != '\n')
    {
        if(c==EOF)
            break;
        if(isalpha(c))
        {
        printf("%c\n",c);
        count++;
        }
    }
    printf("Final count =%ld\n",count);
    return 0;
}
#endif
