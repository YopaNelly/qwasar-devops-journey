char* my_upcase(char* string){
    int i = 0;

    while(string[i] != '\0'){
        if(string[i] >= 'a' && string[i] <= 'z')
            string[i] = string[i] - 'a' +'A';
        i++;
    }
    return string;
}
