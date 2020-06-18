/********************************************************************
* File : decrypt.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to decrypt text that was encrypted
*               by a cipher encryption.
*
********************************************************************/

//program still need some work to cover some cases that give wrong answer

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
//defining macro for cipher name
#define NAME caeser
//macro for word and key size
#define SIZE (5)

//creating struct that hold the word and key
struct cipher_tag {
char * w;
char * ans;
int * k;
};
typedef struct cipher_tag cipher_t ;

//function prototype for taking words
void w(char * n);
//function prototype for taking key
void k(int * m);
//function prototype for deciphering
void decipher(cipher_t NAME);
//function prototype for printing
void print(cipher_t NAME) ;

int main()
{
    cipher_t NAME ;
    char word[SIZE];
    char answer[SIZE];
    int key[SIZE];
    NAME.w=word;
    NAME.ans=answer;
    NAME.k=key;

    //function for taking words
    w(NAME.w);

    //function for taking key
    k(NAME.k);

    //function for deciphering
    decipher(NAME);

    //function for printing
    print(NAME);

    return 0;
}

void w(char * n)
{
    printf("Enter the required word from %d lettres :",SIZE);
    for(int i=0;i<SIZE;i++)
    {
        scanf("%c",n);
        n++;
    }
}

void k(int * m)
{ 
    for(int i=0;i<SIZE;i++)
    {
        printf("Enter key number %d :",(i+1));    
        scanf("%d",m);
        m++;
    }
}

void decipher(cipher_t NAME)
{
    for(int i=0;i<SIZE;i++)
    {
        *NAME.ans=*NAME.w+*NAME.k ;
        NAME.ans++;
        NAME.w++;
        NAME.k++;
    }
}

void print(cipher_t NAME)
{
    for(int i=0;i<SIZE;i++)
    {
	printf("%c",*NAME.ans);
	NAME.ans++;
    }
    printf("\n");
}
*/

#define SIZE 26

void set_zero(size_t * data,size_t length);
void print_array(size_t * data,size_t length);
size_t max_count(size_t * array,size_t size);
void decrypt(FILE * f, size_t key);

int main(int argc,char ** argv)
{
    if(argc!=2)
    {
        printf("Not enough arguments\nPlease specify the file name and opening mode\n");
        return EXIT_FAILURE;
    }
    FILE * f =fopen(argv[1],"r");
    if(f==NULL)
    {
    printf("file opening faild\n");
    return EXIT_FAILURE;
    }
    char c;
    size_t count[SIZE],index;
    set_zero(count,SIZE);
    while ((c=fgetc(f))!=EOF)
    {
        if (isalpha(c))
        {
            c = tolower(c);
            index=c-'a';
            count[index]+=1;
        }
    }
    int key;
    key=max_count(count,SIZE);
    printf("%d\n",key);
    key+=('a'-'e');
    printf("%d\n",key);
    //next to counter negative key
    key+=SIZE;
    key%=SIZE;
    
    //print array was for debugging
    print_array(count,SIZE);

    printf("Key =%d\n",key);
    rewind(f);
    decrypt(f,SIZE-key);

    fclose(f);
    return EXIT_SUCCESS;
    
}


void set_zero(size_t * data,size_t length)
{
    for (size_t i = 0; i < length; i++)
        data[i]=0;
}

void print_array(size_t * data,size_t length)
{
    for (size_t i = 0; i < length; i++)
        printf("count[%ld] = %ld\t%c\n",i+1,data[i],'A'+i);
}


size_t max_count(size_t * array,size_t size)
{
    size_t max =array[0],max_i=0;
    for (size_t i = 1; i < size; i++)
    {
        if (array[i]>max)
        {
            max=array[i];
            max_i=i;
        }
    }
    return(max_i);
}


//same as encryption but we pass in the key as 26-key
void decrypt(FILE * f, size_t key) 
{
  int c;
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      c += key;
      c %= 26;
      c += 'a';
    }
    printf("%c", c);
  }
}