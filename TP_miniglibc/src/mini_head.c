#include "mini_lib.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        mini_exit();
    }
    int temp = 0;
    char *s = argv[1];
    while (*s != '\0') {
        temp = temp*10;
        temp += (*s)-48;
        s += 1;
    }
    MYFILE *file = mini_fopen(argv[2], 'r');
    char *buffer = (char*)mini_calloc(1, IOBUFFER_SIZE);
    mini_fread(buffer, 1, IOBUFFER_SIZE, file);
    for (int i=0; i<temp; ++i) {
        mini_printf(buffer);
        while ((*buffer) != '\n') {
            buffer += 1;
        }
        buffer += 1;
    }
    mini_exit();
}