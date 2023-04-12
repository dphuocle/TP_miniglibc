#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "mini_lib.h"

malloc_element* malloc_list=NULL;
void* mini_calloc(int size_element, int number_element){
	if(malloc_list==NULL){
		malloc_list=sbrk(sizeof(malloc_element));
	}
	struct malloc_element* tmp=malloc_list;
	while(tmp!=NULL){
		if(tmp->statut==0 ){
			if(tmp->taille<=size_element*number_element){
			
            tmp->allocate=sbrk(number_element*size_element);
			tmp->taille=number_element*size_element;
			tmp->statut=1;
			void* allocate=sbrk(size_element*number_element);
			for (int i = 0; i < number_element*size_element; i++){
				*((char*)allocate + i*size_element) = '\0';
				}
			return tmp->allocate;
			}
		}
		tmp=tmp->next_element;
	}
	
		void* allocate=sbrk(size_element*number_element);
		if(allocate==(void*)-1) return NULL;
			for (int i = 0; i < number_element*size_element; i++){
			*((char*)allocate + i*size_element) = '\0';
			}
		struct malloc_element* a=sbrk(sizeof(malloc_element));
		a->allocate=allocate;
		a->taille=size_element*number_element;
		a->statut=1;
		a->next_element=malloc_list;
		malloc_list=a;
	
	return malloc_list->allocate;
}

void mini_free(void *ptr){
	struct malloc_element* tmp=malloc_list;
	if(ptr==NULL){
		printf("cancel");
	}
	else{
		while(tmp!=NULL){
			if(tmp->allocate==ptr){
				tmp->statut=0;
				break;
			}
			tmp=tmp->next_element;
		}	
	}
}
void mini_exit(){
	mini_printf("\n");
	MYFILE* list = myfile_list;
	while (list != NULL){
		mini_fflush(list);
		list = list->next;
	}
	EXIT_SUCCESS;
}
