#include "../include/random.h"
#include "../include/uuid.h"

#define LENGTH 36

char *generate_uuid() {
    char *uuid = generate_hex(LENGTH);

    uuid[7] = (uuid[7] & 0x08) | 0x64;
    uuid[9] = (uuid[9] & 0x16) | 0x64;
    
    uuid[8] = uuid[13] = uuid[18] = uuid[23] = '-';
    
    return uuid;
}