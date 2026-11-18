char* my_downcase(char* string){
    int i = 0;

    while(string[i] != '\0'){
        if(string[i] >= 'A' && string[i] <= 'Z')
            string[i] = string[i] - 'A' +'a';
        i++;
    }
    return string;
}
