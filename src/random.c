#include <stdlib.h>
#include <time.h>

#include "../include/random.h"

static const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *generate_alphanum(int length) {
    char *str = (char *)malloc((length + 1) * sizeof(char));
    srand(time(NULL));

    for (unsigned int i = 0; i < length; i++)
        str[i] = charset[rand() % 62];
    
    str[length] = '\0';
    return str;
}

char *generate_char(int length) {
    char *str = (char *)malloc((length + 1) * sizeof(char));
    srand(time(NULL));

    for (unsigned int i = 0; i < length; i++)
        str[i] = charset[rand() % 52 + 10];
    
    str[length] = '\0';
    return str;
}

char *generate_hex(int length) {
    char *str = (char *)malloc((length + 1) * sizeof(char));
    srand(time(NULL));

    for (unsigned int i = 0; i < length; i++)
        str[i] = charset[rand() % 16];
    
    str[length] = '\0';
    return str;
}

char *generate_number(int length) {
    char *str = (char *)malloc((length + 1) * sizeof(char));
    srand(time(NULL));

    for (unsigned int i = 0; i < length; i++)
        str[i] = charset[rand() % 10];
    
    str[length] = '\0';
    return str;
}