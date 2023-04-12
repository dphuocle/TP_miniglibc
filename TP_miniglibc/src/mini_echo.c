#include "mini_lib.h"

int main(int argc, char **argv) {
    for (int i=1; i<argc; ++i) {
        mini_printf(argv[i]);
        if (i != argc - 1) {
            mini_printf(" ");
        }
    }
    mini_exit();
}