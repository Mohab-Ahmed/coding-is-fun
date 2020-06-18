/********************************************************************
* File : student.c
*
* Author : Mohab Ahmed
* Date   : jan 2020
*
* Description : a program which read the input of a file written
*               in a specific form like in student.txt and then 
*               print which classess each student attend .
*
********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"


int main(int argc,char ** argv)
{
    //check if user provided enough arguments
    if(argc!=2)
    {
        printf("Not enough arguments\nPlease specify the file name\n");
        return EXIT_FAILURE;
    }

    //checking if file opening is succes or failur   
    FILE *s_data =fopen(argv[1],"r");
    if(s_data==NULL)
    {
    printf("file opening faild\n");
    return EXIT_FAILURE;
    }

    //creating a variable for student numbers
    int students_num;
    students_num=read_number(s_data);

    //checking if the first line is the number of students
    if(students_num<0)
    {
        printf("File form is incorrect\n");
        return EXIT_FAILURE;
    }

    //creating an array of structs with there student num 
    student_t students[students_num];
    int check;
    check=assign_struct(students,students_num,s_data);

    //check if struct assigning is correct
    if(check==EXIT_FAILURE)
    {
        printf("Assignning failed\n");
        return EXIT_FAILURE;
    }

    // creating and assigning array of classes
    classes_t classes_all ;
    classes_all=assign_classes_arr(students,students_num,classes_all);
    
    print_struct(students,students_num);
    print_arr(classes_all.classes_arr,classes_all.classes_size);
    print_file(students,students_num,classes_all);
    free_ptr(students,students_num,classes_all);
    fclose(s_data);
    return EXIT_SUCCESS;
}
