/********************************************************************
* File : rectangle.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a small program to to solve a coursera assignment
*               which require u to find intersection between
*               rectangles .
*
********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>



typedef struct
{
    int x;
    int y;
    int width;
    int hight;
}rect_t;


void print_rect(rect_t *p);
void assign_rect(rect_t *p,int var1,int var2,int var3,int var4);
void canonical(rect_t *p);
rect_t intersection(rect_t r1, rect_t r2);
int max(int var1,int var2);
int min(int var1,int var2);
int check_border(rect_t r1,rect_t r2);


int main()
{
    rect_t r1;
    rect_t r2;
    rect_t r3;
    rect_t r4;

    assign_rect(&r1,2,3,5,6);
    assign_rect(&r2,4,5,-5,-7);
    assign_rect(&r3,-2,7,7,-10);
    assign_rect(&r4,0,7,-4,2);

    /*
    printf("rectangle 1 :\n");
    print_rect(&rect1);
    printf("rectangle 2 :\n");
    print_rect(&rect2);
    printf("rectangle 3 :\n");
    print_rect(&rect3);
    printf("rectangle 4 :\n");
    print_rect(&rect4);
    */

    canonical(&r1);
    canonical(&r2);
    canonical(&r3);
    canonical(&r4);


    rect_t i;

    //test everything with r1
    i = intersection(r1,r1);
  printf("intersection(r1,r1): ");
  print_rect(&i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  print_rect(&i);

  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  print_rect(&i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  print_rect(&i);



  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  print_rect(&i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  print_rect(&i);

  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  print_rect(&i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  print_rect(&i);



  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  print_rect(&i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  print_rect(&i);

  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  print_rect(&i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  print_rect(&i);



  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  print_rect(&i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  print_rect(&i);

  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  print_rect(&i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  print_rect(&i);



    return 0;
}


void print_rect(rect_t *p)
{
    if(p->hight==0&&p->width==0)
    {
        printf("Empty\n");
    }
    else
    {
        printf("x = %d\n",p->x);
        printf("y = %d\n",p->y);
        printf("width = %d\n",p->width);
        printf("hight = %d\n",p->hight);
    }
}

void assign_rect(rect_t *p,int var1,int var2,int var3,int var4)
{
    p->x=var1;
    p->y=var2;
    p->width=var3;
    p->hight=var4;
}

void canonical(rect_t *p)
{
    if(p->width<0)
    {
        p->x+=p->width;
        p->width*=(-1);
    }
    if(p->hight<0)
    {
        p->y+=p->hight;
        p->hight*=(-1);
    }
}

rect_t intersection(rect_t r1, rect_t r2)
{
    rect_t r;
    if(check_border(r1,r2)==0)
    {
        assign_rect(&r,0,0,0,0);
        return r;
    }

    r.x = max(r1.x, r2.x);
    r.y = max(r1.y, r2.y);
    r.width = min(r1.width+r1.x, r2.width+r2.x)-r.x;
    r.hight = min(r1.hight+r1.y, r2.hight+r2.y)-r.y;
    return r;
}

int max(int var1,int var2)
{
    if(var1>var2)
        return(var1);
    else
        return(var2);
}

int min(int var1,int var2)
{
    if(var1<var2)
        return(var1);
    else
        return(var2);
}

int check_border(rect_t r1,rect_t r2)
{
    int check_x=0,check_y=0;
    for(int i1=r1.x;i1<=r1.x+r1.width;i1++)
    {
        for(int j1=r2.x;j1<=r2.x+r2.width;j1++)
        {
            if(i1==j1)
                check_x=1;
        }
    }
    for(int i2=r1.y;i2<=r1.y+r1.hight;i2++)
    {
        for(int j2=r2.y;j2<=r2.y+r2.hight;j2++)
        {
            if(i2==j2)
                check_y=1;
        }
    }

    if(check_x&&check_y==1)
        return 1;
    else
        return 0;
}
