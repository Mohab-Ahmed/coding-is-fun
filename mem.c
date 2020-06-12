/********************************************************************
* File : mem.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a small program to test the functionalites of
*               some memory functions which will be used in 
*               later in the embedded coursera course .
*
********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

void * mymemcopy(void *dst,void *src,size_t n);
void * mymemmove(void *dst,void *src,size_t n);
void * mymemmove1(void *dst,void *src,size_t n);
void * my_memmove(void *dest,void *src,size_t count);
void * my_reverse(void *src, size_t length);
void * my_memset(void *src, size_t value, size_t length);
void * my_memzero(void * src, size_t length);

int main()
{
    //examples of ints
    int arr[]={1,2,3,4,5,6};
    int *dest=malloc(sizeof(arr));

    //example of chars
    char name[]="Geeksfor";
    char *copy=malloc(sizeof(name));

    //print original INT array b4 copy
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
        printf("%d\t",arr[i]);

    //print original CHAR array b4 copy
    printf("\n%s\n",name);

    #ifdef COPY
    /*dest=memcpy(arr+2,arr,12);
    copy=memcpy(name+5,name,3);*/
    dest=mymemcopy(arr+2,arr,12);
    copy=mymemcopy(name+5,name,3);
    #endif /* COPY */

    #ifdef MOVE
    /*dest=memmove(arr+2,arr,12);
    copy=memmove(name+5,name,4);*/
    dest=mymemmove(arr+2,arr,12);
    copy=mymemmove(name+5,name,4);
    #endif /* MOVE */

    #ifdef REV
    //no idea why -3 yet
    //name-1 because '\0' when reverted is first and it prints blank
    dest=my_reverse(arr,sizeof(arr)-3);
    copy=my_reverse(name,sizeof(name)-1);
    #endif /* REV */

    #ifdef SET
    /*dest=memset(arr,12,sizeof(arr));
    copy=memset(name,97,sizeof(name)-1);*/
    
    //name-1 because '\0' when reverted is first and it prints blank
    dest=my_memset(arr,12,sizeof(arr));
    copy=my_memset(name,97,sizeof(name)-1);
    #endif /* SET */

    #ifdef ZERO
    dest=my_memzero(arr,sizeof(arr));
    copy=my_memzero(name,sizeof(name));
    #endif

    //print original INT array after copy
    printf("\nafter...\n");
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
        printf("%d\t",arr[i]);

    //print original CHAR array after copy
    printf("\n%s\n",name);

    //print copied INT array
    printf("\ncopied...\n");
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
        printf("%d\t",dest[i]);
    printf("\n");

    //print copied CHAR array
    printf("%s\n",copy);

    return EXIT_SUCCESS;
}

    
void * mymemcopy(void* dst,void* src,size_t n)
{
    //type cast to char cuz it's 1 byte
    char* csrc=(char*)src;
    char* cdst=(char*)dst;

    for(size_t i=0;i<n;i++)
      *(cdst+i)=*(csrc+i);

    return(cdst);
}
void * mymemmove(void* dst,void* src,size_t n)
{
    //type cast to char cuz it's 1 byte
    char* csrc=(char*)src;
    char* cdst=(char*)dst;

    if(dst<=src)
    {
      for(size_t i=0;i<n;i++)
        *(cdst+i)=*(csrc+i);
    }
    else
    {
      for(size_t i=n;i>0;i--)
        *(cdst+i-1)=*(csrc+i-1);
    }

    return(cdst);
}
void * mymemmove1(void* dst,void* src,size_t n)
{
    //type cast to char cuz it's 1 byte
    char* csrc=(char*)src;
    char* cdst=(char*)dst;

    char temp[n];

    for(size_t i=0;i<n;i++)
        *(temp+i)=*(csrc+i);

    for(size_t i=0;i<n;i++)
        *(cdst+i)=*(temp+i);

    return(cdst);
}

// function from http://kernel4u.blogspot.com/2015/10/write-your-own-memmove-program-without.html
void * my_memmove(void *dest,void *src,size_t count)
  {
    char *temp;
    char *s;
    if ( dest <= src) {
      temp = dest;
      s = src;
      while(count--)
        *temp++ = *s++;
    } else {
      temp = dest;
      temp += count;
      s = src;
      s += count;
     while(count--)
        *--temp = *--s;
    }
    return dest;
  }

void * my_reverse(void * src, size_t length)
{
  //type cast to char to copy byte by byte
  char *csrc=(char*)src;

  char temp[length];

  for(size_t i=0;i<length;i++)
    *(temp+i)=*(csrc+i);

  for(size_t i=0;i<length;i++)
    *(csrc+i)=*(temp+length-1-i);
  return(csrc);
}

void * my_memset(void * src, size_t value, size_t length)
{
  //type cast to char to copy byte by byte
  char *csrc=(char*)src;

  for (size_t i = 0; i < length; i++)
  {
    *(csrc+i)=value;
  }
  return(csrc);
}

void * my_memzero(void * src, size_t length)
{
  //type cast to char to copy byte by byte
  char *csrc=(char*)src;

  for (size_t i = 0; i < length; i++)
  {
    *(csrc+i)=0;
  }
  return(csrc);
}