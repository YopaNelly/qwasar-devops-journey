#include <stdlib.h>

int* my_range(int param_1, int param_2)
{
    int* result;
    int i = 0;

    if (param_1 >= param_2)
        return NULL;
    result = malloc(sizeof(int) * (param_2 - param_1));
    if (result == NULL)
        return NULL;
    while (param_1 + i < param_2)
    {
        result[i] = param_1 + i;
        i++;
    }
    return result;
}
