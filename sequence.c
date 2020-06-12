/********************************************************************
* File : sequence.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program i used to solve a coursera 
*               assignment and the requirements are below .
*
********************************************************************/



/************************************************
* 
*1. Create a file called maxSeq.c and write the function:
*      size_t maxSeq(int * array, size_t n);
*
*   which returns the length of the maximum increasing contiguous
*   subsequence in the array.  The parameter n specifies the length
*   of the array For example, if the array passed in were
*
*     { 1, 2, 1, 3, 5, 7, 2, 4, 6, 9}
*
*   this function would return 4 because the longest sequence
*   of (strictly) increasing numbers in that array is 1, 3, 5, 7
*   which has length 4.  Note that 1,3,5,7,9 is an increasing
*   subsequence, but is not contiguous (finding discontiguous
*   ones efficiently takes techniques we haven't learned yet).
*
*   Note that the subseqence does not need to increase at a
*   constant rate (or follow any other pattern besides being strictly
*   increasing).  2, 4, 67, 93, 94, 102 would be a valid increasing
*   sequence of length 6.
*
*
*2. Compile and test your code using the test-subseq.c you wrote
*   previously.  (as before, compile the .c files separately, and link
*   them together).
*
*3. Submit your code for maxSeq.c
************************************************/


#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0

int find_max(int a,int b)
{
    if(a>b)
        return(YES);
    return(NO);
}

size_t max_count(size_t *array,size_t size)
{
    size_t max =array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i]>max)
        {
            max=array[i];
        }
    }
    return(max);
}

size_t maxSeq(int * array, size_t n)
{
    if(n==0)
        return(0);
    size_t ans[n];
    ans[0]=1;
    int count=1;

    int min=array[0];
    for(size_t i=1;i<n;i++)
    {
        if (find_max(array[i],min)==YES)
        {
            min=array[i];
            ans[count-1]++;
        }
        else
        {
            min=array[i];
            count++;
            ans[count-1]=1;
        }
    }
    return(max_count(ans,count));
}




int main()
{
    //implementation 11,2,5,7,8,9
    int arr1[]={1,3,2,5,7,8,3};
    if(maxSeq(arr1,7)!=4)
    {
        printf("Failed arr1\n");
        printf("Answer arr1 = %ld\n",maxSeq(arr1,7));
        exit(EXIT_FAILURE);
    }
    else{printf("Succeded arr1\n");}


    //implementation 6
    int arr2[]={1};
    if(maxSeq(arr2,1)!=1)
    {
        printf("Failed arr2\n");
        printf("Answer arr2 = %ld\n",maxSeq(arr2,1));
        exit(EXIT_FAILURE);
    }
    else{printf("Succeded arr2\n");}


    //implementation 3
    int arr3[]={1,3,2,5,7,8,3};
    if(maxSeq(arr3,4)!=2)
    {
        printf("Failed arr3\n");
        printf("Answer arr3 = %ld\n",maxSeq(arr3,1));
        exit(EXIT_FAILURE);
    }
    else{printf("Succeded arr3\n");}


    //implementation 10
    int arr4[]={8589934592,-9,-8,-5,-4,-8,2};
    if(maxSeq(arr4,7)!=4)
    {
        printf("Failed arr4\n");
        printf("Answer arr4 = %ld\n",maxSeq(arr4,7));
        exit(EXIT_FAILURE);
    }
    else{printf("Succeded arr4\n");}


    //implementation 1
    int arr5[]={0,0,0,0,0,0,0};
    if(maxSeq(arr5,7)!=1)
    {
        printf("Failed arr5\n");
        printf("Answer arr5 = %ld\n",maxSeq(arr5,7));
        exit(EXIT_FAILURE);
    }
    else{printf("Succeded arr5\n");}



    //implementation
    int arr6[]={};
    if(maxSeq(arr6,0)!=0)
    {
        printf("Failed arr6\n");
        printf("My Answer = 1\n");
        printf("Answer arr6 = %ld\n",maxSeq(arr6,0));
        return(EXIT_FAILURE);
    }
    else{printf("Succeded arr6\n");}









    /*
    //false implementation to success them all for testing
    int arr_test[]={1,3,2,5,7,8,3};
    if(maxSeq(arr_test,0)!=434)
    {
        printf("Failed arr_test\n");
        printf("Answer arr_test = %ld\n",maxSeq(arr_test,1));
        exit(EXIT_FAILURE);
    }
    else{printf("Succeded arr_test\n");}
    */

    printf("I fucking did it.\n");
    return(EXIT_SUCCESS);
}

 