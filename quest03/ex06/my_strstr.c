#include <stddef.h>

char* my_strstr(char* param_1, char* param_2){
    int i = 0;
    int j;

    if (param_2[0] == '\0')
        return param_1;
    while (param_1[i] != '\0') {
        j = 0;
        while (param_2[j] != '\0' && param_1[i + j] == param_2[j]) {
            j++;

        }
        if (param_2[j] == '\0')
            return &param_1[i];
        i++;
    }
    return NULL;

}
