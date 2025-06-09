#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/jwt.h"
#include "../include/random.h"
#include "../include/uuid.h"

#define VERSION "1.0.0"

static void help(const char program_name[]) {
    printf("%s v %s\n", program_name, VERSION);
    printf("-h | --help\t\tshow this message\n\n");

    printf("-j  | --jwt\t\tgenerate a jwt key\n");
    printf("-u  | --uuid\t\tgenerate version 4 uuid\n\n");

    printf("-a {len} | --alphanum {len}\tget a random string of len length\n");
    printf("-c {len} | --char {len}\t\tget a random letters-only string of len lenght\n");
    printf("-x {len} | --hex {len}\t\tget a random hex of len length\n");
    printf("-n {len} | --number {len}\tget a random number of len length\n\n");
}

static void parse_flags(const int argc, const char *argv[]) {
    char *str;

    for (unsigned int i = 1; i < argc; i++ ) {
        if (strcmp(argv[i], "-j") == 0 || strcmp(argv[i], "--jwt") == 0 ) {
            str = generate_jwt();

        } else if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--uuid") == 0 ) {
            str = generate_uuid();

        } else if ((strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--alphanum") == 0) && i + 1 < argc) {
            str = generate_alphanum(atoi(argv[i + 1]));
            i++;
        
        } else if ((strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--char") == 0) && i + 1 < argc) {
            str = generate_char(atoi(argv[i + 1]));
            i++;
        
        } else if ((strcmp(argv[i], "-x") == 0 || strcmp(argv[i], "--hex") == 0) && i + 1 < argc) {
            str = generate_hex(atoi(argv[i + 1]));
            i++;

        } else if ((strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--number") == 0) && i + 1 < argc) {
            str = generate_number(atoi(argv[i + 1]));
            i++;
        
        } else {
            help(argv[0]);
            continue;
        }
    
        printf("%s\n", str);
        free(str);
    }
}

int main(const int argc, const char *argv[]) {
    if (argc > 1)
        parse_flags(argc, argv);
    else 
        help(argv[0]);
    
    return 0;
}