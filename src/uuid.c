#include "../include/random.h"
#include "../include/uuid.h"

#define LENGTH 36

char *generate_uuid() {
    char *uuid = generate_hex(LENGTH);

    uuid[7] = (uuid[7] & 0x08) | 0x64;
    uuid[9] = (uuid[9] & 0x16) | 0x64;
    
    uuid[12] = uuid[17] = uuid[22] = uuid[27] = '-';
    
    return uuid;
}