/********************************************************************
* File : retirement.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a simple program i used to solve a coursera 
*               assignment and the requirements are below .
*
********************************************************************/


/************************************************
For this problem, you will be writing a "retirement savings" calculator.
 We'll remove the effects of inflation by keeping everything in
 "today's dollars" and using a "Rate of return" that is in terms of
 "more than inflation."

 1. Create a file called "retirement.c".  Include the usual header
    files (stdlib.h and stdio.h) at the top.

 2. We're going to model both savings (while working) and expenditure
    (while retired).  It turns out that both of these require the
    same basic information, so we will make a struct to represent that.
    Declare a struct _retire_info which has three fields:
       (1) an int called "months" for the number of months it is applicable to,
       (2) a double called "contribution" for how many dollars
           are contributed (or spent if negative) from the account per month
       (3) a double called "rate_of_return" for the rate of returns
           (which we will assume to be "after inflation").

    After you have declared this struct, use typedef to make "retire_info"
    another name for this struct.

 3. Write the function
      void retirement (int startAge,   //in months
                       double initial, //initial savings in dollars
                       retire_info working, //info about working
                       retire_info retired) //info about being retired

   This function should perform two tasks (which are similar---look
   for a chance to abstract something out into a function!).

   First, it should compute your retirement account balance each
   month while you are working.  To do this, you need to calculate
   the account balance increase from returns (balance * rate of return),
   and add that to the current balance.  You then need to add the
   monthly contribution to the balance.
   For example, if you have $1,000 in the account, earn a 0.5% rate of
   return per month, and contribute $100 per month, you would
   cmopute 1000 * 0.005 = $5 in interest earned.  You would then
   add this plus the monthly contribution to the balance to end up
   with $1105 in the account at the end of the month.

   At the start of each month (before the balance changes), you should
   print out the current balance with the following format:
    "Age %3d month %2d you have $%.2lf\n"
   The first two format conversions are the savers age in years and months.
   The third format conversion is the account balance
   This calculation goes on for the number of months specified
   in the "working" retire_info structure.


   Second, you should perform a very similar calculation for each
   month of retirment.  The difference here is that you will use the
   information in the "retired" retire_info structure instead
   of the information in the "working" structure.  As with
   working, you should print out the same information as before.

   [Hint: since you are performing a very similar computation,
    think about how you can abstract that part out into a function,
    and re-use it, rather than re-writing it]

 4. Write a main function which computes the retirement assuming
     Working:
     --------
      Months: 489
      Per Month Savings: $1000
      Rate of Return:  4.5% per year ( 0.045/12 per month)
                       [above inflation]
    Retired:
    --------
      Months: 384
      Per Month Spending: -4000
      Rate of Return: 1% per year ( 0.01/12 per month)
                      [above inflation]
    Starting conditions:
    -------------------
       Age: 327 months (27 years, 3 months)
       Savings: $21,345
  5. Compile your code (we provided a Makefile) and test
     it (we provided the output: retirement_ans.txt).

  6. Submit retirement.c

************************************************/

#include<string.h>
#include<math.h>
#include<stdint.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int months;
    double contribution;
    double reate_of_return;
}retire_info;


void assign_struct(retire_info *p,int v1,double v2,double v3)
{
    p->months=v1;
    p->contribution=v2;
    p->reate_of_return=v3;
}


double assign_values(retire_info r,double sum)
{
    sum+=(r.reate_of_return*sum+r.contribution);
    return sum;
}


void retirement(int startAge,double intial,retire_info working,retire_info retired)
{
    int i;
    for(i=startAge;i<working.months+startAge;i++)
    {
        printf("Age %3d month %2d you have $%.2f\n",i/12,i%12,intial);
        intial=assign_values(working,intial);
    }
    //for(int j=i;j<retired.months+i;j++)
    for(;i<retired.months+working.months+startAge;i++)
    {
        //printf("Age %3d month %2d you have $%.2f\n",j/12,j%12,intial);
        printf("Age %3d month %2d you have $%.2f\n",i/12,i%12,intial);
        intial=assign_values(retired,intial);
    }
}




int main()
{
    retire_info work;
    retire_info retire;

    assign_struct(&work,489,1000,0.045/12);
    assign_struct(&retire,384,-4000,0.01/12);

    retirement(327,21345,work,retire);


    return EXIT_SUCCESS;
}














