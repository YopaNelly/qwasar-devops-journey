char* my_strncpy(char* str1, char* str2, int nbr){
    int i = 0;

    while(i< nbr && str2[i] != '\0'){
        str1[i] = str2[i];
        i++;
    }
    while (i < nbr){
        str1[i] = '\0';
        i++;
    }
    return str1;
}
