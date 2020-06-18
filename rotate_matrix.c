/********************************************************************
* File : rotate_matrix.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to Read a 10X10 matrix and
*                rotate it 90 degree.
*
********************************************************************/




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdint.h>


                                                            
void rotate(char matrix[10][10]);
void print_array(char matrix[10][10]);
size_t read_array(FILE* fptr,char matrix[10][10]);




int main(int argc,char** argv)
{
    if(argc!=2)
    {
        fprintf(stderr,"Not enough arguments\n");
        exit(EXIT_FAILURE);
    }
    FILE * f =fopen(argv[1],"r");
    if(f==NULL)
    {
        fprintf(stderr,"file opening faild\n");
        exit(EXIT_FAILURE);
    }
    char array[10][10];
    size_t check;
    check=read_array(f,&array[0]);
    //printf("check = %ld\n",check);
    if (check!=100)
    {
        fprintf(stderr,"invalid file inputs\n");
        exit(EXIT_FAILURE);
    }
    
    print_array(&array[0]);

    printf("______________________________\n");
    rotate(&array[0]);
    print_array(&array[0]);

    fclose(f);
    return EXIT_SUCCESS;
}





void rotate(char matrix[10][10])
{
  char temp[10][10];
  for(int k=0;k<10;k++)
    {
      for(int l=0;l<10;l++)
        {
          temp[k][l]=matrix[k][l];
        }
    }

  for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
        {
          matrix[j][9-i]=temp[i][j];
        }
    }
}

void print_array(char matrix[10][10])
{
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            printf("%c",matrix[i][j]);
        }
        printf("\n");
    }   
}


size_t read_array(FILE* fptr,char matrix[10][10])
{
    //int c not char cuz when dealing with fgetc u would expect it 
    //to return EOF which equals -1 
    int c;
    size_t j=0,count=0;
    for (size_t i = 0; i < 10; i++)
    {
        j=0;
        while ((c=fgetc(fptr))!=EOF)
        {
            if (c=='\n')
                break;
            matrix[i][j]=c;
            j++;   
            count++;
        }
    }
    if ((c=fgetc(fptr))!=EOF)
        return(EXIT_FAILURE);
    
    return(count);
}
