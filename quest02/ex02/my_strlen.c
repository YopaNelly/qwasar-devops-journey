int my_strlen(char* param_1){
    int count =0;

    while (param_1[count] != '\0')
        count++;
    return count;
}
