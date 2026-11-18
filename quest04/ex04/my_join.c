#include <stdlib.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

static int len_of(char* s)
{
    int len = 0;

    while (s[len] != '\0')
        len++;
    return len;
}

char* my_join(string_array* param_1, char* param_2)
{
    int total = 0;
    int i = 0;
    int j;
    int pos = 0;
    char* result;

    if (param_1->size == 0)
        return NULL;
    while (i < param_1->size)
    {
        total += len_of(param_1->array[i]);
        i++;
    }
    total += len_of(param_2) * (param_1->size - 1);
    result = malloc(total + 1);
    if (result == NULL)
        return NULL;
    i = 0;
    while (i < param_1->size)
    {
        j = 0;
        while (param_1->array[i][j] != '\0')
            result[pos++] = param_1->array[i][j++];
        if (i < param_1->size - 1)
        {
            j = 0;
            while (param_2[j] != '\0')
                result[pos++] = param_2[j++];
        }
        i++;
    }
    result[pos] = '\0';
    return result;
}
