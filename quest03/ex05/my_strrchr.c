#include <stddef.h>

char* my_strrchr(char* param_1, char param_2)
{
    char* last = NULL;
    int i = 0;

    while (param_1[i] != '\0')
    {
        if (param_1[i] == param_2)
            last = &param_1[i];
        i++;
    }
    if (param_2 == '\0')
        return &param_1[i];
    return last;
}
