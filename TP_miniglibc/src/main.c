#include "mini_lib.h"

int main () {
    int *a = (int*)mini_calloc(sizeof(int), 20);
    for(int i =0; i<20; ++i) {
        a[i] = i*i;
    }
    char *s = (char*)mini_calloc(sizeof(char), 10);
    strcpy(s, "Bonjour\n\0");
    for (int i=0; i<30; ++i) {
        printf("%d, ", a[i]);
    }
    printf("\n");
    fputs(s, stdout);
    mini_free(a);
    double *i = (double*)mini_calloc(sizeof(double), 2);
    i[0] = 0;
    i[1] = 3.5;
    printf("a: %p\ns: %p\nx: %p\n", a, s, i);
    struct malloc_element *temp;
    while (temp != NULL) {
        printf("%p: %d %d\n", temp->p, temp->status, temp->taille);
        temp = temp->next_malloc;
    }

    mini_printf("Hello");    
    mini_exit();

    char str[10];
    mini_scanf(str, 9);
    printf("%s", str);

    MYFILE *file = mini_fopen("test.txt", 'r');
    char buffer[50];
    mini_fread(str, 1, 49, file);
    fputs(buffer, stdout);

    MYFILE *file_2 = mini_fopen("test.txt", 'w');
    char buffer_2[] = "abcabc";
    mini_fwrite(buffer_2, 1, 6, file_2);

/* Ex38 */
    MYFILE *file_3 = mini_fopen("test.txt", 'w');
    mini_fputc(file_3, 'c');
}