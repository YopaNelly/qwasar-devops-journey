#include <stdio.h>
#include <string.h>

char* reverse_string(char* str){
    int len =0;
    int i = 0;
    char temp;

    while(str[len] != '\0')
        len++;
    while (i < len/2){
        temp = str[i];
        str[i] = str[len -1 - i];
        str[len -1 -i] = temp;
        i++;
    }
    return str;
}
