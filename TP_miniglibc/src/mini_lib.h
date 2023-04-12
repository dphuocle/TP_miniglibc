#ifndef NEW_LIB_H
#define NEW_LIB_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 100
#define IOBUFFER_SIZE 2048

struct malloc_element {
    void* allocate;
    int taille;
    int statut;
    struct malloc_element* next_element;
};

typedef struct malloc_element malloc_element;
struct MYFILE{
    int fd;
    void* buffer_read;
    void* buffer_write;
    int ind_read;
    int ind_write;
    struct MYFILE *next;
};

typedef struct MYFILE MYFILE;
extern MYFILE *myfile_list;

// Gestion de la memoire

void* mini_calloc(int,int);
void mini_free(void *);
void mini_exit();

// Gestion des chaines de caracteres

void mini_printf(char*);
int mini_scanf(char*,int);
int mini_strlen(char*);
int mini_strcpy(char*,char*);
int mini_strcmp(char*,char*);
void mini_perror(char*);

// Gestion des Entrees/Sorties 

MYFILE* mini_fopen(char*,char);
int mini_fread(void*,int,int,MYFILE*);
int mini_fwrite(void*,int,int,MYFILE*);
int mini_fflush(MYFILE*);
int mini_fclose(MYFILE*);
int mini_fgetc(MYFILE*);
int mini_fputc(MYFILE*,char);

// Mini shell

int parsing_space(char*,char**);
void execArgv(char**);

#endif