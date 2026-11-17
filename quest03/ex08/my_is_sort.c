#include <stdbool.h>
#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif


bool my_is_sort(integer_array* param_1){
    bool ascending =true;
    bool descending = true;
    int i = 1;

    while (i < param_1->size){
        if(param_1 -> array[i] < param_1->array[i - 1])
            ascending =false;
        if (param_1->array[i] > param_1->array[i-1])
            descending =false;
        i++;
    }
    return ascending || descending;
}
