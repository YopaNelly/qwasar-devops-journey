#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
#include <unistd.h>

typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif


void my_print_words_array(string_array* param_1){
    int i = 0;
    int j;

    while (i<param_1->size){
        j = 0;
        while (param_1->array[i][j] != '\0') {
            write(1, &param_1->array[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }

}
