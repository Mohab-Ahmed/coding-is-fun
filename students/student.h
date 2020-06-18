#ifndef __STUDENT_H__
#define __STUDENT_H__

struct student_tag 
{
    char *name;
    int class_num;
    char** st_classes;
}; 
typedef struct student_tag student_t ;

struct classes_tag
{
    char** classes_arr;
    int classes_size;
};
typedef struct classes_tag classes_t ;


__ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void free_ptr(student_t *data, size_t size,classes_t classes);

int read_number(FILE* data);
int is_a_number(char num);

int assign_struct(student_t *data,size_t size,FILE* f);
classes_t assign_classes_arr(student_t *data,size_t size,classes_t classes);

void print_file(student_t *data, size_t size,classes_t classes);
void print_struct(student_t *data, size_t size);
void print_arr(char **arr,int size);

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#endif /*__STUDENT_H__*/
