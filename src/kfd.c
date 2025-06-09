#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/jwt.h"
#include "../include/random.h"
#include "../include/uuid.h"

#define VERSION "1.0.0"

static inline int check_option(const char *argument, const char *short_form, const char *long_form) {
    return strcmp(argument, short_form) == 0 || strcmp(argument, long_form) == 0;
}

static const void help(const char program_name[]) {
    printf("%s v %s\n", program_name, VERSION);
    printf("-h | --help\t\tshow this message\n\n");

    printf("-j  | --jwt\t\tgenerate a jwt key\n");
    printf("-u  | --uuid\t\tgenerate version 4 uuid\n\n");

    printf("-a {len} | --alphanum {len}\tget a random string of len length\n");
    printf("-c {len} | --char {len}\t\tget a random letters-only string of len lenght\n");
    printf("-x {len} | --hex {len}\t\tget a random hex of len length\n");
    printf("-n {len} | --number {len}\tget a random number of len length\n\n");
}

static const void initialize_randomness() {
    srand(time(NULL));
}

static const void parse_flags(const int argc, const char *argv[]) {
    char *str;

    for (unsigned int i = 1; i < argc; i++ ) {
        if (check_option(argv[i], "-j", "--jwt")) {
            str = generate_jwt();

        } else if (check_option(argv[i], "-u", "--uuid")) {
            str = generate_uuid();

        } else if (check_option(argv[i], "-a", "--alphanum") && i + 1 < argc) {
            str = generate_alphanum(atoi(argv[i + 1]));
            i++;
        
        } else if (check_option(argv[i], "-c", "--char") && i + 1 < argc) {
            str = generate_char(atoi(argv[i + 1]));
            i++;
        
        } else if (check_option(argv[i], "-x", "--hex") && i + 1 < argc) {
            str = generate_hex(atoi(argv[i + 1]));
            i++;

        } else if (check_option(argv[i], "-n", "--number") && i + 1 < argc) {
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
    initialize_randomness();

    if (argc > 1)
        parse_flags(argc, argv);
    else 
        help(argv[0]);
    
    return 0;
}