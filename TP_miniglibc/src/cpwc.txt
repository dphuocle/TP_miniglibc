#include "mini_lib.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        mini_printf("To few arguments");
        mini_exit();
    } else if (argc > 2) {
        mini_printf("To many arguments");
        mini_exit();
    }

    MYFILE *file = mini_fopen(argv[1], 'r');
    char *buff = (char*)mini_calloc(1, IOBUFFER_SIZE);
    int r = mini_fread(buff, 1, IOBUFFER_SIZE, file);
    int count = 0;
    for(int i=0; i<r; ++i) {
        if ((buff[i] == ' ') || (buff[i] == '\n') || (buff[i] == '\0')) {
            if ((buff[i-1] != ' ') && (buff[i-1] != '\n') || (buff[i-1] != '\0')) {
                count += 1;
            }
        }
    }
    int temp = count;
    int n = 0;
    while (temp != 0) {
        temp = (temp - (temp%10))/10;
        n += 1;
    }
    char *str = (char*)mini_calloc(1, n+1);
    str[n] = '\0';
    for(int i=0; i<n; ++i) {
        str[n-1-i] = count%10 + 48;
        count = (count -(count%10))/10;
    }
    mini_printf(str);
    mini_exit();
}
