#include "../include/random.h"

const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

char *generate_alphanum(int length) {
    char *str = (char *)malloc(length * sizeof(char));
    srand(time(NULL));

    for (unsigned int i = 0; i < length; i++)
        str[i] = charset[rand() % 62];
    
    str[length - 1] = '\0';
    return str;
}

char *generate_char(int length) {
    char *str = (char *)malloc(length * sizeof(char));
    srand(time(NULL));

    for (unsigned int i = 0; i < length; i++)
        str[i] = charset[rand() % 52];
    
    str[length - 1] = '\0';
    return str;
}

char *generate_number(int length) {
    char *str = (char *)malloc(length * sizeof(char));
    srand(time(NULL));

    for (unsigned int i = 0; i < length; i++)
        str[i] = charset[rand() % 10 + 52];
    
    str[length - 1] = '\0';
    return str;
}