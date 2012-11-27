#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_malloc.h"


#define SUPER	"Supercalifragilisticexpialidocious"

int main(void){

 char *str;
 /* Un appel direct à malloc */
  str = my_malloc(strlen(SUPER)+10);



/* On libere la memoire allouee sur str est strcp*/
/*  free(str);*/

 exit(EXIT_SUCCESS);
 }
