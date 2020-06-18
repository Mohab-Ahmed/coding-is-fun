#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

__ssize_t getline(char **lineptr, size_t *n, FILE *stream);

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME  
  FILE * f =fopen(filename,"r");
  if(f==NULL)
  {
    fprintf(stderr,"file opening faild\n");
    return(NULL);
  }

  counts_t* data=createCounts();
  char* c=NULL;
  size_t size=0;
  while (getline(&c,&size,f)>0)
  {
    is_it_there(c);
    addCount(data,lookupValue(kvPairs,c));
  }
  free(c);
  fclose(f);
  
  return data;
}

int main(int argc, char ** argv) {
  if (argc<3)
  {
    fprintf(stderr,"Not enough arguments\n");
    return(EXIT_FAILURE);
  }
  
  //WRITE ME (plus add appropriate error checking!)                                               
 //read the key/value pairs from the file named by argv[1] (call the result kv)                   
  kvarray_t* kv=readKVs(argv[1]);
 //count from 2 to argc (call the number you count i)                                             
  for (size_t i = 2; i < argc; i++)
  {
    //count the values that appear in the file named by argv[i], using kv as the key/value pair   
    //   (call this result c)                                                                     
    counts_t* c=countFile(argv[i],kv);
    //compute the output file name from argv[i] (call this outName)                               
    char* outName=computeOutputFileName(argv[i]);

    //open the file named by outName (call that f)                                                
    FILE* f =fopen(outName,"w");
    //print the counts from c into the FILE f                                                     
    printCounts(c,f);
    //close f                                                                                     
    fclose(f);
    //free the memory for outName and c
    freeCounts(c);
    free(outName);

  }
 //free the memory for kv                                                                         
  freeKVs(kv);
  return EXIT_SUCCESS;
}