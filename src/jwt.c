#include "../include/jwt.h"
#include "../include/random.h"

#define JWT_LENGTH 64

char *generate_jwt() {
    return generate_alphanum(JWT_LENGTH);
}