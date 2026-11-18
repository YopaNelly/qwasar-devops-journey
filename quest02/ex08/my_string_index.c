int my_string_index(char* haystack, char needle){
    int i = 0;

    while(haystack[i] != '\0'){
        if(haystack[i] == needle)
            return i;
        i++;
    }
    return -1;
}
