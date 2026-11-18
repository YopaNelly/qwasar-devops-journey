#include <stdlib.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

integer_array* my_count_on_it(string_array* param_1)
{
    integer_array* result;
    int i = 0;
    int len;

    result = malloc(sizeof(integer_array));
    if (result == NULL)
        return NULL;
    result->size = param_1->size;
    result->array = malloc(sizeof(int) * param_1->size);
    if (result->array == NULL){
        free(result);
        return NULL;
    }
    while (i < param_1->size)
    {
        len = 0;
        while (param_1->array[i][len] != '\0')
            len++;
        result->array[i] = len;
        i++;
    }
    return result;
}
