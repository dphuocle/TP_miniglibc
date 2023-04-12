#include <fcntl.h>
#include "mini_lib.h"
#include <unistd.h>

MYFILE *myfile_list=NULL;
MYFILE* mini_fopen(char* file, char mode){
	int flag;
	mode_t m= S_IWUSR | S_IRUSR;
	switch(mode){
		case 'a' : flag=O_APPEND | O_CREAT | O_RDONLY;
			break;
		case 'b' : flag=O_RDWR | O_CREAT;
			break;
		case 'r' : flag=O_RDONLY;
			break;
		case 'w' : flag=O_WRONLY | O_CREAT | O_TRUNC;
			break;	
	}
	int fd=open(file,flag,m);
	if(fd==-1){
		mini_printf("error : fopen123\n");
		return NULL;
	}
	MYFILE* myfile=mini_calloc((int)sizeof(MYFILE),1);
	myfile->fd=fd;
	myfile->buffer_read=NULL;
	myfile->buffer_write=NULL;
	myfile->ind_read=-1;
	myfile->ind_write=-1;
	myfile->next=myfile_list;
	myfile_list=myfile;
	return myfile_list;
}
int mini_fread(void* buffer,int size_element,int number_element,MYFILE* file){
	
	if(file==NULL){
		mini_printf("error : fread1\n");
		return -1;
	}
	if(file->ind_read==-1){
		file->buffer_read=mini_calloc(1,IOBUFFER_SIZE);
	}
	int r=read(file->fd,file->buffer_read,IOBUFFER_SIZE);
	//mini_printf((char*)file->buffer_read);
	if(r==-1){
		mini_printf("error :fread2\n");
		perror((char*)&errno);
		return -1;
	}
	file->ind_read=0;
	char* buff=buffer;
	int i;
	for(i=0;i<number_element*size_element;i++){
		buff[i]=((char*)file->buffer_read)[file->ind_read];
		file->ind_read++;
		if(file->ind_read==IOBUFFER_SIZE){
			int r=read(file->fd,file->buffer_read,IOBUFFER_SIZE);
			if(r==-1){
				mini_printf("error : fread3\n");
				return -1;
			}
			if(r<IOBUFFER_SIZE-1){
				return i;
			}
			file->ind_read=0;
		}
		
	}
       return i;
}

int mini_fwrite(void* buffer,int size_element,int number_element,MYFILE* file){
	if(file==NULL){
		mini_printf("error : write\n");
		return -1;
	}
	if(file->ind_write==-1){
		file->buffer_write=mini_calloc(1,IOBUFFER_SIZE);
		if(file->buffer_write==NULL){
			mini_printf("error : write\n");
			return -1;
		}
		file->ind_write=0;
	}
	char* buff=file->buffer_write;
	int i = 0;
	while(i<size_element*number_element){
		buff[file->ind_write]=((char*)buffer)[i];
		file->ind_write++; 
		if(file->ind_write==IOBUFFER_SIZE){
			int w=write(file->fd,file->buffer_write,IOBUFFER_SIZE);
			if(w==-1){
				mini_printf("error : write\n");
				return -1;
			}
			file->ind_write=0;
		}
		i++;
	}
	if (write(file->fd,buff,file->ind_write) == -1){
			perror("error printf");
		}
	return i;
	
}
int mini_fflush(MYFILE *file){
	if(file==NULL){
		mini_printf("error : fflush\n");
		return -1;
	}
	MYFILE* list=myfile_list;
	while(list!=NULL){
		if(file->ind_write==-1){
		return -1;
	}
		if(mini_strlen(file->buffer_write)>IOBUFFER_SIZE){
			int w=write(file->fd,file->buffer_write,mini_strlen(file->buffer_write));
		if(w==-1){
			mini_printf("error : fflush\n");
			return -1;
		}
	}
	list=list->next;
    }
    return 0;
	
	
}

int mini_fclose(MYFILE *file){
	if(file==NULL){
		return -1;
	}
	MYFILE* list=myfile_list;
	while(list!=NULL){
	if(list->next==file){
		int fd=close(file->fd);
		if(fd==-1){
		mini_printf("error : fclose\n");
		return fd;
	     }
	     list->next=file->next;
	     mini_free(file);
	}
	list=list->next;
     }
     return 0;
}

int mini_fgetc(MYFILE* file){
	if(file==NULL){
		mini_printf("error : fgetc\n");
		return -1;
	}
	int r=read(file->fd,file->buffer_read,1);
	if(r==-1){
		mini_printf("error : fgetc\n");
		return -1;
	}
	char c=((char*)file->buffer_read)[0];
	return c;
}
int mini_fputc(MYFILE* file,char c){
	if(file==NULL){
		mini_printf("error1 : fputc\n");
		return -1;
	}
	int w=write(file->fd,&c,1);
	if(w==-1){
		mini_printf("error2 : fputc\n");
		perror((char*)&errno);
		return -1;
	}
	return w;
}



