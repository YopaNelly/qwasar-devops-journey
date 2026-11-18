#include <stdlib.h>
#include <stdlib.h>

char* my_strdup(char* str){

    int len=0;
    int i=0;
    char* copy;

    while (str[len] != '\0'){
        len++;
    }
    copy = malloc(len + 1);
    if (copy == NULL){
        return NULL;
    }
    while(i<len){
        copy[i] = str[i];
        i++;
    }
    copy[len] = '\0';
    return copy;
}
