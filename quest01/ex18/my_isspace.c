int my_isspace(char param_1){
    if(param_1 == ' ' || (param_1 <= '\t' && param_1 <= '\r'))
        return 1;
    return 0;
}
