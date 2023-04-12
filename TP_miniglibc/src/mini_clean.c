#include "mini_lib.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        mini_printf("Too few arguments");
        mini_exit();
    } else if (argc > 2) {
        mini_printf("Too many arguments");
        mini_exit();
    }
    mode_t m = S_IWUSR | S_IRUSR;
    open(argv[1], O_CREAT | O_TRUNC, m);
    mini_exit();
    return 0;
}