/********************************************************************
* File : getline.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to test the functionalites of
*               getline.
*
********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

__ssize_t getline(char **lineptr, size_t *n, FILE *stream);

int main(int argc,char ** argv)
{
    if(argc!=3)
    {
        fprintf(stderr,"Not enough arguments\nPlease specify the file name and opening mode\n");
        return(EXIT_FAILURE);
    }
    FILE * f =fopen(argv[1],argv[2]);
    //FILE * f =fopen("/home/mohab/main/test/test.txt","r");
    if(f==NULL)
    {
        printf("file opening faild\n");
        return 0;
    }
    __ssize_t count;
    size_t size=0;
    char *arr=NULL;
    while ((count=getline(&arr,&size,f))>=0)
    {
        printf("%s",arr);
        printf("no. of char =%ld\n",count) ;
    }
    free(arr);
    fclose(f);
    return 0;
}
    

    
/*
int main(int argc,char ** argv)
{
    if(argc!=3)
    {
        fprintf(stderr,"Not enough arguments\nPlease specify the file name and opening mode\n");
        return(EXIT_FAILURE);
    }
    FILE * f =fopen(argv[1],argv[2]);
    //FILE * f =fopen("/home/mohab/main/test/test.txt","r");
    if(f==NULL)
    {
    printf("file opening faild\n");
    return 0;
    }
    __ssize_t count;
    size_t size=0;
    char** strings_array=malloc(4*sizeof(char*));
    size_t i=0;
    strings_array[i]=NULL;
    while ((count=getline(&strings_array[i],&size,f))>=0)
    {
        i++;
        size=0;
        strings_array[i]=NULL;
        printf("%s",strings_array[i]);
        printf("no. of char =%ld\n",count) ;
    }
    free(strings_array[0]);
    free(strings_array[1]);
    free(strings_array);
    fclose(f);
    return 0;
}    
*/     
    