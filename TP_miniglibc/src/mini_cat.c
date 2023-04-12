#include "mini_lib.h"

int main(int argc, char **argv) {
    MYFILE *file = (MYFILE*)mini_calloc(sizeof(MYFILE), 1);
    if (argc == 1) {
        mini_printf("Error\n");
        mini_exit();
    }
    for (int i=1; i<argc; ++i) {
        char *buff = (char*)mini_calloc(1, IOBUFFER_SIZE);
        file = mini_fopen(argv[i], 'r');
        int r = mini_fread(buff, 1, IOBUFFER_SIZE, file);
	mini_printf(buff);
    }
    mini_exit();
}
