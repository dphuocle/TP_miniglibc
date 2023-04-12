#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "mini_lib.h"

int main() {
 	while(1){
	char* argv[10] ;
	char* input = mini_calloc(1,100);
	mini_printf("\n");
	mini_scanf(input,30);
	//mini_printf(input);
	int argc = parsing_space(input,argv);
	mini_printf(argv[0]);
	if (mini_strcmp(argv[0],"exit") == 0)
	{
		mini_printf("Exit\n");
		return 0;
	}
	
	execArgv(argv);
	mini_exit();
	}
	
}

int parsing_space(char* str, char** argv)
{
	char *token;                  
        token = strtok(str," ");
        int argc=0;
        while(token!=NULL){
            argv[argc]=token;      
            token = strtok(NULL," ");
            argc++;
        }
        argv[argc]=NULL;
        return argc;
}

void execArgv(char** argv)
{
    pid_t pid = fork(); 

    if (pid == -1) {
        mini_printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {
        if (execv(argv[0], argv) < 0) {
            mini_printf("\nCould not execute command..");
        }
        mini_exit();
    } else {
        wait(NULL); 
        return;
    }
}