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
    char *buff = (char*)mini_calloc(1, IOBUFFER_SIZE);
    int r = mini_fread(buff, 1, IOBUFFER_SIZE, file);
    int a[temp];
    a[0] = 0;
    int ind = 1;
    int count = 0;
    while (count < r) {
	if (buff[count] != '\n') {
	    count += 1;
	} else {
	    if (count+1 < r) {
    	    	if (ind == temp) {
        	    int i = 0;
		    for(int i=0; i<(temp-1); ++i) {
            	    	a[i] = a[i+1];
		    }
		    a[ind-1] = count+1;
		    count += 1;
    	        } else {
		    a[ind] = count + 1;
		    count += 1;
		    ind += 1;
		}
	    } else {
		count += 1;
	    }
	}
    }
    buff += a[0];
    int min = temp>ind ? ind : temp;
    for (int i=0; i<min; ++i) {
        mini_printf(buff);
        buff += (a[i+1] - a[i]);
    }
    mini_exit();
}