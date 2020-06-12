/********************************************************************
* File : bit.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program to test the functionalites of
*               bitfields withen a struct .
*
********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>

typedef struct 
{
    uint32_t x:2;
    uint32_t y:7;
    uint32_t z:1;
    uint16_t :0;
    uint8_t w;
}ex1_t;

typedef union bit
{
    uint8_t x:2;
    uint8_t y:7;
    uint8_t z:1;
}un_t;

typedef struct 
{
    uint8_t x;
    uint16_t y;
    uint8_t z;
}ex2_t __attribute__((aligned));

int main()
{
    printf("%ld\n",sizeof(ex1_t));
    printf("%ld\n",sizeof(un_t));
    printf("%ld\n",sizeof(ex2_t));
    return 0;
}
