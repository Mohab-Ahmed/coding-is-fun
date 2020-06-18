#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

counts_t * createCounts(void) {
  //WRITE ME                                                                                      
  counts_t* data;
  data=malloc(sizeof(counts_t));
  data->array=malloc(sizeof(one_count_t));
  data->lenght=0;
  data->count_unknown=0;

  return(data);
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME                                                                                      
  if (name==NULL)
    {
      c->count_unknown++;
      return;
    }

  if (c->lenght==0)
    {
      c->array[c->lenght].value=malloc((1+strlen(name))*sizeof(char));
      strcpy(c->array[c->lenght].value,name);
      c->array[c->lenght].count=1;
      c->lenght++;
      return;
    }

  for (int i = 0; i < c->lenght; i++)
    {
      if (strcmp(c->array[i].value,name)==0)
        {
          c->array[i].count++;
          return;
        }
    }

  c->array=realloc(c->array,(c->lenght+1)*sizeof(counts_t));
  c->array[c->lenght].value=malloc((1+strlen(name))*sizeof(char));
  strcpy(c->array[c->lenght].value,name);
  c->array[c->lenght].count=1;
  c->lenght++;


}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME                                                                                      
  for (size_t i = 0; i < c->lenght; i++)
    {
      fprintf(outFile,"%s: %d\n",c->array[i].value,c->array[i].count);
    }
  if (c->count_unknown>0)
    {
      fprintf(outFile,"<unknown> : %d\n",c->count_unknown);
    }

}

void freeCounts(counts_t * c) {
  //WRITE ME                                                                                      
  for (size_t i = 0; i < c->lenght; i++)
    {
      free(c->array[i].value);
    }
  free(c->array);
  free(c);
}
