#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"

int read_number(FILE* data)
{
    char c;
    int ans=0;
    int count_plus=0;
    while((c=fgetc(data))!='\n')
    {
        if(c==EOF)
            break;
        if(c==43)
        {
            if(count_plus>0)
            {
                return(-1);
            }
            else
            {
                continue;
            }

        }
        if(is_a_number(c)>=0)
        {
            ans=(ans*10)+is_a_number(c);
            count_plus++;
        }
        else
        {
            return(-1);
        }
    }
    return ans;
}

int is_a_number(char num)
{
    if((num>='0'&&num<='9'))
        {return(num-'0');}
    else
        {return(-1);}
}

int assign_struct(student_t *data,size_t size,FILE* f)
{
    __ssize_t count;
    size_t getline_size=0;
    for(size_t i=0;i<size;i++)
    {
        count=0;
        getline_size=0;
        data[i].name=NULL;
        count=getline(&data[i].name,&getline_size,f);
        if(count<0)
        {
            printf("assigning of name(%ld) failed\n",i);
            return EXIT_FAILURE;
        }

        //reading and checking if it's a number
        data[i].class_num=read_number(f);
        if(data[i].class_num<0)
        {
            printf("assigning of class_num(%ld) faild\n",i);
            return EXIT_FAILURE;
        }

        data[i].st_classes=malloc(data[i].class_num*sizeof(char*));
        for(size_t j=0;j<data[i].class_num;j++)
        {
            count=0;
            getline_size=0;
            data[i].st_classes[j]=NULL;
            count=getline(&data[i].st_classes[j],&getline_size,f);
            if(count<0)
            {
                printf("assigning of class name(%ld) of student(%ld) failed\n",j,i);
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}

classes_t assign_classes_arr(student_t *data,size_t size,classes_t classes)
{
    classes.classes_arr=malloc(1*sizeof(char*));
    classes.classes_arr[0]=malloc((1+strlen(data[0].st_classes[0]))*sizeof(char));
    strcpy(classes.classes_arr[0],data[0].st_classes[0]);
    int check;
    classes.classes_size=1;
    for(size_t i=0;i<size;i++)
    {
        for(size_t j=0;j<data[i].class_num;j++)
        {
            for(size_t k=0;k<classes.classes_size;k++)
            {
                if(strcmp(data[i].st_classes[j],classes.classes_arr[k])==0)
                    {
                        check=0;
                        break;
                    }
                else
                {
                     check=1; 
                }
            }
            if(check==1)
            {
                classes.classes_size++;
                classes.classes_arr=realloc(classes.classes_arr,classes.classes_size*sizeof(char*));
                classes.classes_arr[classes.classes_size-1]=malloc((1+strlen(data[i].st_classes[j]))*sizeof(char));
                strcpy(classes.classes_arr[classes.classes_size-1],data[i].st_classes[j]);
            }
        }
    }
    return classes;
}

void print_file(student_t *data, size_t size,classes_t classes)
{
    int check;
    for (int i = 0; i < classes.classes_size; i++)
    {
        FILE* f=fopen(classes.classes_arr[i],"w");
        for (size_t j = 0; j < size; j++)
        {
            for (size_t k = 0; k < data[j].class_num; k++)
            {
                if (strcmp(data[j].st_classes[k],classes.classes_arr[i])==0)
                {
                    check=1;
                    break;
                }
                else
                {
                    check=0;
                }
            }
            if (check==1)
            {
                fprintf(f,"%s",data[j].name);
            }
        }
        fclose(f);
    }
}

void free_ptr(student_t *data, size_t size,classes_t classes)
{
    //freeing student struct
    for (size_t i = 0; i < size; i++)
    {
        free(data[i].name);
        for (size_t j = 0; j < data[i].class_num; j++)
        {
            free(data[i].st_classes[j]);
        }
        free(data[i].st_classes);
    }
    
    //freeing classes struct
    for (size_t k = 0; k < classes.classes_size; k++)
    {
        free(classes.classes_arr[k]);
    }
    free(classes.classes_arr);
}

void print_struct(student_t *data, size_t size)
{
    for(size_t i=0;i<size;i++)
    {
        printf("Student(%ld) name = %s",i+1,data[i].name);
        printf("Student(%ld) num of classes = %d\n",i+1,data[i].class_num);
        for(size_t j=0;j<data[i].class_num;j++)
        {
            printf("%s",data[i].st_classes[j]);
        }
        printf("\n");
    }
}

void print_arr(char **arr,int size)
{
    printf("\n");
    for(int i=0;i<size;i++)
    {
        printf("%s",arr[i]);
    }
    printf("\n");
}
