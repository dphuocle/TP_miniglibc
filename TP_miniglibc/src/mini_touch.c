#include "mini_lib.h"

int main(int argc, char** argv) {
    for (int i=1; i<argc; ++i) {
        open(argv[i], O_CREAT);
    }
}