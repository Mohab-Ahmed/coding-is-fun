#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME                                                                                      
  char * output=malloc((strlen(inputName)+8)*sizeof(*output));
  strcpy(output,inputName);
  strcat(output,".counts");
  return(output);
}
