#include "mini_lib.h"
#include <stdio.h>
int main(int argc,char** argv){
	MYFILE *src=mini_fopen(argv[1],'r');
	MYFILE *dest=mini_fopen(argv[2],'w');
	char* buffer=(char*)mini_calloc(1,IOBUFFER_SIZE);
	int r=mini_fread(buffer,1,IOBUFFER_SIZE,src);
	mini_fwrite(buffer,1,r,dest);
	mini_exit();
	return 0;
}
