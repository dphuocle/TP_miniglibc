#include <stdio.h>
#include <string.h>
#include "mini_lib.h"
int main (int argc,char* argv[]) {
   int ret;
   FILE *fp;
   char* filename = argv[1];

   fp = mini_fopen(filename, 'w');

   
   mini_fclose(fp);
   
   ret = remove(filename);

   if(ret == 0) {
      mini_printf("File deleted successfully");
   } else {
      mini_printf("Error: unable to delete the file");
   }
   
   return(0);
}
