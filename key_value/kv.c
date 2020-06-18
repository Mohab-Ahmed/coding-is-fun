#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"



//function to remove the \n from the string                                                       
void is_it_there(char* ptr)
{
  char* hold;
  int i=0;
  if ((hold=strchr(ptr,'\n'))!=NULL)
    {
      while ((ptr[hold-ptr+i])!='\0')
        {
          ptr[hold-ptr+i]=ptr[hold-ptr+i+1];
          i++;
        }
    }
}


kvarray_t * readKVs(const char * fname) {
  //WRITE ME                                                                                      
  FILE *f =fopen(fname,"r");
  if(f==NULL)
    {
      fprintf(stderr,"file opening faild\n");
      exit(EXIT_FAILURE);
    }

  //allocate space for first struct then for 2nd struct which is the array                        
  kvarray_t* data=malloc(sizeof(kvarray_t));
  data->array=malloc(sizeof(kvpair_t));
  data->lenght=0;

  //variables for getline and what we will need in this function an index i                       
  //and char* temp to hold values while we split the array                                        
  char* line=NULL;
  size_t size=0;
  char* temp;
  size_t key_size;

  //main while loop                                                                               
  while (getline(&line,&size,f)>0)
    {
      is_it_there(line);
      data->array=realloc(data->array,(data->lenght+1)*sizeof(kvpair_t));
      temp=strchr(line,'=');
      //key_size=strlen(line)-strlen(temp);                                                       
      key_size=temp-line;
      data->array[data->lenght].key=malloc((1+key_size)*sizeof(char));
      strncpy(data->array[data->lenght].key,line,key_size);
      data->array[data->lenght].key[key_size]='\0';

      temp++;
      data->array[data->lenght].value=malloc((1+strlen(temp))*sizeof(char));
      strcpy(data->array[data->lenght].value,temp);
      data->lenght++;
    }
  free(line);
  fclose(f);

  return(data);
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME                                                                                      
  for (size_t i = 0; i < pairs->lenght; i++)
    {
      free(pairs->array[i].key);
      free(pairs->array[i].value);
    }
  free(pairs->array);
  free(pairs);

}

void printKVs(kvarray_t * pairs) {
  //WRITE ME                                                                                      
  for (size_t i = 0; i < pairs->lenght; i++)
    {
      printf("key = '%s' value = '%s'\n",pairs->array[i].key,pairs->array[i].value);
    }

}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME                                                                                      
  for (size_t i = 0; i < pairs->lenght; i++)
    {
      if (strcmp(pairs->array[i].key,key)==0)
        {
          return(pairs->array[i].value);
        }
    }

  return(NULL);
}
