int join(char **str1, char *str2) {
    if (!str1 || !str2 ) { return -1; }
    
    size_t first_string_length = (*str1) ? strlen(*str1) : 0;
    size_t second_string_length = strlen(str2);
    size_t combined_length = first_string_length + second_string_length;
    
    char *tmp = realloc(*str1, combined_length + 1);
    
    if (NULL == tmp) { return -1; }
    
    *str1 = tmp;
    
    memcpy(*str1 + first_string_length, str2, second_string_length);
    
    (*str1)[combined_length] = '\0';
    
    return 0;
} 
