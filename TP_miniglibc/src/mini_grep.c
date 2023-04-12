#include "mini_lib.h"

int main(int argc, char **argv) {
    MYFILE *file = mini_fopen(argv[2], 'r');
    char *buff = (char*)mini_calloc(1, IOBUFFER_SIZE);
    int r = mini_fread(buff, 1, IOBUFFER_SIZE, file);
    struct element {
        int value;
        struct element *next;
    };

    struct element *a = (struct element *)mini_calloc(sizeof(struct element), 1);
    a->value = 0;
    a->next = NULL;
    int count = 0;
    int ind = 1;
    while (count < r) {
	    if (buff[count] != '\n') {
	        count += 1;
	    } else {
	        if (count+1 < r) {
    	    	struct element *newElement = (struct element *)mini_calloc(sizeof(struct element), 1);
                newElement->value = count + 1;
                newElement->next = a;
                a = newElement;
                ind += 1;
	        } 
            count += 1;
	    }
    }
    
    int b[ind];
    int i = 1;
    while (a != NULL) {
        b[ind - i] = a->value;
        a = a->next;
        ++i;
    }
    for (int i=0; i<(ind-1); ++i) {
        for (int j=b[i]; j<(b[i+1]-1); ++j) {
            bool is_true = true;
            for(int k=0; k<mini_strlen(argv[1]); ++k) {
		if (buff[j+k] != (argv[1])[k]) {
		    is_true = false;
		    break;
		}
	    }
	    if (is_true) {
		mini_printf(&(buff[b[i]]));
		break;
	    }
        }
    }
    mini_exit();
}