#include <stdio.h>
#include <string.h>

#include "../include/jwt.h"
#include "../include/random.h"
#include "../include/rsa.h"
#include "../include/uuid.h"

#define VERSION "1.0.0"

static void help(const char program_name[]) {
    printf("%s v %s\n", program_name, VERSION);
    printf("-h | --help\t\tshow this message\n\n");

    printf("-u | --uuid\t\tgenerate an uuid\n");
    printf("-j | --jwt\t\tgenerate a jwt key\n");
    printf("-r | --rsa\t\tgenerate a rsa key\n\n");

    printf("-a {len} | --alphanum {len}\t\tget a random string of len length\n");
    printf("-n {len} | --number {len}\t\tget a random number of len length\n");
    printf("-c {len} | --char {len}\t\tget a random letters-only string of len lenght\n\n");
}

static void parse_flags(const int argc, const char *argv[]) {

    for (unsigned int i = 1; i < argc; i++)
        if (strcmp(argv[i], "-j") == 0 || strcmp(argv[i], "--jwt") == 0 ) {
            generate_jwt();

        } else if (strcmp(argv[i], "-r") ==  0 || strcmp(argv[i], "--rsa") == 0) {
            generate_rsa();

        } else if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--uuid") == 0 ) {
            generate_uuid();

        } else if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--alphanum") == 0 && i + 1 < argc) {
            generate_alphanum(atoi(argv[i + 1]));
            i++;
        
        } else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--char") == 0 && i + 1 < argc) {
            generate_char(atoi(argv[i + 1]));
            i++;

        } else if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--number") == 0 && i + 1 < argc) {
            generate_num(atoi(argv[i + 1]));
            i++;
        
        } else {
            help(argv[0]);
        }
}

int main(const int argc, const char *argv[]) {
    parse_flags(argc, argv);
    
    return 0;
}