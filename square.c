/********************************************************************
* File : square.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to squares of # and * which might 
*               intercept with each other .
*
********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>


int is_star(int x,int y,int size,int i, int j);
int is_hash(int x,int y,int size,int i, int j);
void squares(int size1, int x_offset, int y_offset, int size2);

//see if those cordinants within the star square boundries
int is_star(int x,int y,int size,int i, int j)
{
    while((x<=i&&i<size+x)&&(y<=j&&j<size+y))
    {
    if(i==x||i==(x+size-1)||j==y||j==(y+size-1))
        {

            return(1);
        }
        else
        {
            return(0);
        }
    }
    return(0);
}

//see if those cordinants within the hashtag square boundries
int is_hash(int x,int y,int size,int i, int j)
{
    while(i<size&&j<size)
    {
    if(i==x||i==(x+size-1)||j==y||j==(y+size-1))
        {

            return(1);
        }
        else
        {
            return(0);
        }
    }
    return(0);
}

void squares(int size1, int x_offset, int y_offset, int size2)
{
    int x =x_offset+size2;
    int y =y_offset+size2;

    //check if the new total is smaller hence it's inside of the original square
    if(x<size1)
    {
        x=size1;
    }
    if(y<size1)
    {
        y=size1;
    }
    
    for(int i=0;i<y;i++)
    {
        for(int j=0;j<x;j++)
        {
            if(is_star(x_offset,y_offset,size2,j,i)==1)
            {

                printf("*");
            }
            else if(is_hash(0,0,size1,j,i)==1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}



int main(int argc ,char **argv)
{
    if(argc!=5)
    {
        printf("Not enough arguments\nPlease specify <sizeof#> <x-ofsset> <y-ofsset> <sizeof*>\n");
        return EXIT_FAILURE;
    }
    squares(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
    return EXIT_SUCCESS;
}
