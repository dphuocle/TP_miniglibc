#include<stdlib.h>
#include <unistd.h>
#include "mini_lib.h"
#define BUF_SIZE 1024

char* buffer;
int ind=-1;
#define _POSIX_SOURCE 1 
void mini_printf(char* msg){
	if(ind==-1){
		buffer=mini_calloc(1,BUF_SIZE);
		if(buffer==NULL){
			
			buffer = mini_calloc(sizeof(char),BUF_SIZE);
		}
		ind=0;
	}
	
	for(int i=0;msg[i]!='\0';i++){ 
	   if(msg[i]=='\n' || ind==BUF_SIZE){
		if(write(1,buffer,ind)==-1){
			perror("erreur printf");

		}
		ind=0;
	    }
		
		if(msg[i]=='\n'){
			if(write(1,msg+i,1)==-1){
			perror("erreur printf");
			}
		}
	    if(msg[i]!='\n'){
			buffer[ind]=msg[i];
			ind++;
			}
    }
}

int mini_scanf(char* buffer, int size_buffer)
{
	if (read(0,buffer,size_buffer) == -1) 
	{
		mini_perror("error scanf");
		return -1;
	}
	buffer[size_buffer+1] = '\0';
	return 0;
}

int mini_strlen(char* s){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}

int mini_strcpy(char* s,char* d){
	if (!d)
    {
        return -1;
    }
    while (*s != '\0')
    {
        *d = *s;
        d++;
        s++;
    }
    *d = '\0';
    return mini_strlen(d);
}

int mini_strncpy(char *s, char *d, int size)
{
    if (!d)
    {
        return -1;
    }
    int i = 0;
    while (*s != '\0' && i < size)
    {
        *d = *s;
        d++;
        s++;
        i++;
    }
    *d = '\0';
    return mini_strlen(d);
}

int mini_strcmp(char *s1, char *s2)
{
    if ((!s1 || !s2))
    {
        return -1;
    }
    int i = 0;
    while (i < mini_strlen(s1) && s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return -1;
        i++;
    }
    return 0;
}

void mini_perror(char* message){
	mini_printf(message);
	perror((char*)&errno);
}


