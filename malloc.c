/********************************************************************
* File : malloc.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to test the functionalites of
*               malloc.
*
********************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

int * sort_arr(int * array,int size) ;
void * print_arr(int * array,int size);
#define SIZE 5

int main()
{
    int arr[SIZE];
    for(int i=0;i<SIZE;i++)
        arr[i]=i+1;
    print_arr(arr,SIZE);
    printf("-----\n");
    int *ptr=sort_arr(arr,SIZE);
    print_arr(ptr,SIZE+1);
    free(ptr);
    printf("-----\n");
    print_arr(arr,SIZE);
    return 0;
}

int * sort_arr(int * array,int size)
{
    int * sorted;
    sorted=malloc(size * sizeof(*sorted));
    int temp;
    for(int i=0;i<size;i++)
        sorted[i]=array[i];
    for(int j=0;j<size;j++)
    {
        for(int k=(j+1);k<size;k++)
        {
            if(sorted[k]>sorted[j])
            {
                temp=sorted[j];
                sorted[j]=sorted[k];
                sorted[k]=temp ;
            }
        }
    }
    sorted=realloc(sorted,((size+1) * sizeof(*sorted)));
    sorted[size]=6;
    return (sorted);
}
void * print_arr(int * array,int size)
{
    for(int i=0;i<size;i++)
        printf("%d - %d\n",i,array[i]);
    return 0 ;
}