#include "mini_lib.h"
int main(int argc,char** argv){
	mini_fopen(*(argv+1),"r");
	mini_exit();
	
}
